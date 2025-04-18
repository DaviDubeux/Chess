#include "Chess.h"

Chess::Chess() {
  bitboard = Bitboard();
  position = Position();
}

void Chess::start() {
  std::string moveString;
  Move move;

  std::cout << "Enter your move (in PGN format): ";
  while (!gameOver()) {
    std::cin >> moveString;
    move = PGNToMove(moveString);

    // Process the move here
    if (!isValidMove(move)) {
      std::cout << "Invalid move. Try again." << std::endl;
      continue;
    }

    // Update the board and position
    bitboard.update(move);  // Update the bitboard with the move
    position.update(move);  // Update the position object
    updateTypeBoard(move);  // Update the type board

    printBoard();                            // Print the board after the move
    turn = (turn == white) ? black : white;  // Switch turns
    halfMove++;
  }
}

bool Chess::gameOver() {
  // Check if the game is over (checkmate, stalemate, etc.)
  // This is a placeholder implementation
  return (halfMove >= 10);  // Example condition for game over
}

Move Chess::PGNToMove(std::string moveString) {
  Move scotchGame[10] = {
      {white, pawn, empty, 12, 28},  {black, pawn, empty, 52, 36},
      {white, knight, empty, 6, 21}, {black, knight, empty, 57, 42},
      {white, pawn, empty, 11, 27},  {black, pawn, pawn, 36, 27},
      {white, knight, pawn, 21, 27}, {black, bishop, empty, 61, 34},
      {white, bishop, empty, 2, 20}, {black, queen, empty, 59, 45}};

  return scotchGame[halfMove];
}

bool Chess::isValidMove(Move move) {
  // Check if the move is valid
  // This is a placeholder implementation
  return true;
}

void Chess::updateTypeBoard(Move move) {
  unsigned char fromI = move.from / 8;
  unsigned char fromJ = move.from % 8;
  unsigned char toI = move.to / 8;
  unsigned char toJ = move.to % 8;

  // Update the type board with the move
  typeBoard[fromI][fromJ] = empty;  // Remove the piece from the starting square
  typeBoard[toI][toJ] = move.type;  // Place the piece on the destination square
}

void Chess::printBoard() {
  char c;
  bool color;
  std::cout << "  + - + - + - + - + - + - + - + - +\n";
  for (int i = 7; i >= 0; i--) {
    std::cout << i + 1 << " | ";
    for (int j = 0; j < 8; j++) {
      if (bitboard[empty] & (C64(1) << (i * 8 + j))) {
        c = (i + j) % 2 ? '#' : ' ';
      } else {
        color = ((bitboard[black] & (C64(1) << (i * 8 + j))) > 0);
        c = bitboardToChar[color];
      }

      for (int k = pawn; k <= king; k++) {
        if (bitboard[k] & (C64(1) << (i * 8 + j))) {
          c += bitboardToChar[k];
          break;
        }
      }

      std::cout << c << " | ";
    }
    std::cout << "\n  + - + - + - + - + - + - + - + - +\n";
  }
  std::cout << "    a   b   c   d   e   f   g   h  \n";
}
#include "Bitboard.h"

Bitboard::Bitboard() {
  for (int i = 0; i < 10; i++) {
    board[i] = initBitboard[i];
  }
}

void Bitboard::print(enumBitboard color, enumBitboard type) {
  utils::printBitboard(board[color] & board[type]);
}

void Bitboard::update(Move move) {
  if (move.captures != empty) {
    U64 toMask = C64(1) << move.to;
    // Remove piece from
    board[move.captures] &= ~toMask;  // piece's bitboard
    board[!move.color] &= ~toMask;    // opponent's bitboard
  }
  update(move.color, move.from, move.to);  // Update the color bitboard
  update(move.type, move.from, move.to);   // Update the type bitboard
  update(occupied, move.from, move.to);    // Update the occupied bitboard
  update(empty, move.to, move.from);       // Update the empty bitboard
}

void Bitboard::update(enumBitboard type, unsigned char from, unsigned char to) {
  // Move a piece from one square to another
  U64 fromMask = C64(1) << from;
  U64 toMask = C64(1) << to;

  board[type] &= ~fromMask;  // Remove piece from the type bitboard
  board[type] |= toMask;     // Add piece to the type bitboard

  // unsigned char c = bitboardToChar[type];
  // if (type == white) c = 'w';
  // if (type == black) c = 'b';

  // unsigned int fromI = from / 8;
  // unsigned int fromJ = from % 8;
  // unsigned int toI = to / 8;
  // unsigned int toJ = to % 8;

  // std::cout << c << " " << '(' << fromJ + 1 << ',' << fromI + 1 << ") -> ("
  //           << toJ + 1 << ',' << toI + 1 << ")\n";
  // utils::printBitboard(fromMask | toMask);
  // std::cout << '\n';
}

U64& Bitboard::operator[](int index) { return board[index]; }

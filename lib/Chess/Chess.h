#ifndef CHESS_H
#define CHESS_H

#include "../Bitboard/Bitboard.h"
#include "../Move/Move.h"
#include "../Position/Position.h"
#include "../Utils/constants.h"

struct Chess {
  Bitboard bitboard;
  Position position;
  unsigned char turn = white;
  unsigned int halfMove = 0;

  enumBitboard typeBoard[8][8] = {
      rook,  knight, bishop, queen, king,  bishop, knight, rook,
      pawn,  pawn,   pawn,   pawn,  pawn,  pawn,   pawn,   pawn,
      empty, empty,  empty,  empty, empty, empty,  empty,  empty,
      empty, empty,  empty,  empty, empty, empty,  empty,  empty,
      empty, empty,  empty,  empty, empty, empty,  empty,  empty,
      empty, empty,  empty,  empty, empty, empty,  empty,  empty,
      pawn,  pawn,   pawn,   pawn,  pawn,  pawn,   pawn,   pawn,
      rook,  knight, bishop, queen, king,  bishop, knight, rook};

 public:
  Chess();

  void start();
  bool gameOver();
  Move PGNToMove(std::string moveString);
  bool isValidMove(Move move);
  void updateTypeBoard(Move move);
  void printBoard();
};

#endif
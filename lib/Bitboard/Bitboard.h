#ifndef BITBOARD_H
#define BITBOARD_H

#include <iostream>

#include "../Move/Move.h"
#include "../Utils/constants.h"
#include "../Utils/utils.h"

struct Bitboard {
  U64 board[10];

  Bitboard();

  void print(enumBitboard color, enumBitboard type);
  void update(Move move);
  void update(enumBitboard type, unsigned char from, unsigned char to);
  U64& operator[](int index);
};
#endif
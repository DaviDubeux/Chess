#ifndef CONSTANTS_H
#define CONSTANTS_H

#define C64(constantU64) constantU64##ULL

typedef unsigned long long int U64;

enum enumBitboard : unsigned char {
  white = 0,
  black,
  pawn,
  knight,
  bishop,
  rook,
  queen,
  king,
  occupied,
  empty
};

static const U64 initBitboard[] = {0x000000000000FFFF, 0xFFFF000000000000,
                                   0x00FF00000000FF00, 0x4200000000000042,
                                   0x2400000000000024, 0x8100000000000081,
                                   0x0800000000000008, 0x1000000000000010,
                                   0xFFFF00000000FFFF, 0x0000FFFFFFFF0000};

static const char bitboardToChar[10] = {0,   32,  'P', 'N', 'B',
                                        'R', 'Q', 'K', 'O', 'E'};
#endif
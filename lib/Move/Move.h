#ifndef MOVE_H
#define MOVE_H

#include "../Utils/constants.h"

struct Move {
  enumBitboard color;
  enumBitboard type;
  enumBitboard captures;
  unsigned char from;
  unsigned char to;
};

#endif
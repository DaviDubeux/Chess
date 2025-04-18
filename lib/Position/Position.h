#ifndef POSITION_H
#define POSITION_H

#include "../Move/Move.h"
#include "../Utils/constants.h"

struct Position {
  bool turn;

  void update(Move move);
};

#endif
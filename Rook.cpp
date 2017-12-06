//Implementation file for the rook

#include "Rook.h"

Rook::Rook(string type, bool c, int a, int b) : Figure (type, c, a, b) {
  //tbc
}

bool Rook::validMove (string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  //Either dimension of the movement must be zero (can only move either vertical or horizontal)
  if ((abs(horizontal) == 0) || ((abs(vertical) == 0)))
    return true;

  return false;
}

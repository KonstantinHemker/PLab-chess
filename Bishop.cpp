//Implementation file for Bishop
#include "Bishop.h"

Bishop::Bishop(string type, bool c, int a, int b) : Figure (type, c, a, b) {
//tbc
}

bool Bishop::validMove(string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  if (abs(horizontal) == abs(vertical))
    return true;

  return false;
}

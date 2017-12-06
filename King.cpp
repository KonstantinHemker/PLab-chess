//Implementation file for king
#include "King.h"

King::King (string type, bool c, int a, int b) : Figure (type, c, a, b)  {
  //tbc
}

bool King::validMove(string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  if ((abs(horizontal) == 1) || (abs(vertical) == 0))
    return true;
  if ((abs(horizontal) == 0) || (abs(vertical) == 1))
    return true;
  if ((abs(horizontal) == abs(vertical)) && (abs(vertical)) == 1)
    return true;

  return false; 
}

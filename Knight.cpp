//Implementation file for knight
#include "Knight.h"

Knight::Knight(string type, bool c, int a, int b) : Figure (type, c, a, b)  {
//tbc
}

bool Knight::validMove(FigurePtr square[][8], string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  if ((abs(horizontal) == 1) && (abs(vertical) == 2))
    return true;

  if ((abs(horizontal) == 2) && (abs(vertical) == 1))
    return true;


  return false;
}

//Implementation file for king
#include "King.h"

King::King (string type, bool c, int a, int b) : Figure (type, c, a, b)  {
  //tbc
}

bool King::validMove(FigurePtr square[][8], string currPos, string newPos) {
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

/*
bool King::validRoute(FigurePtr square[][8], string currPos, string newPos) {
  //deliberately Empty
  //no route check required as the destination is the only step in the route
}
*/

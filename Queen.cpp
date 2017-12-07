//Implementation file for queen
#include "Queen.h"

Queen::Queen(string type, bool c, int a, int b) : Figure (type, c, a, b)  {
//tbc
}

bool Queen::validMove(FigurePtr square[][8], string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  //The queen essentially combines the valid moves of the rook and the bishop.
  //That is, the following set of moves is valid:
  //absvalue[X][0]
  //absvalue[0][X]
  //absvalue[X][Y] where X == Y
  //Note that this assumes that it is also being checked for valid destination and
  //the route itself
  if (abs(horizontal) == abs(vertical))
    return true;
  if ((abs(horizontal) == 0) || ((abs(vertical) == 0)))
    return true;


  return false;
}


bool Queen::validRoute(FigurePtr square[][8], string currPos, string newPos) {
  //do something
}

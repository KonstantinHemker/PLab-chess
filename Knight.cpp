//Implementation file for knight
#include "Knight.h"

Knight::Knight(string type, bool c, int a, int b) : Figure (type, c, a, b)  {
//tbc
}

bool Knight::validMove(FigurePtr square[][8], string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  //cout << "Horizontal steps " << horizontal << endl;
  //cout << "Vertical steps " << vertical << endl;

  //This states that the absolute values of the move must be
  //either 1 or 2, or 1 or 2. We can think of this as two options:
  //absvalue[1][2]
  //absvalue[2][1]
  //where the values in parentheses are [horizontal move][vertical move]
  //Note that this assumes that we already accounted for invalid destination
  //(outside of chessboard or own figure)
  if ((abs(horizontal) == 1) && (abs(vertical) == 2))
    return true;

  if ((abs(horizontal) == 2) && (abs(vertical) == 1))
    return true;


  return false;
}

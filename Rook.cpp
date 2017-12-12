//Implementation file for the rook

#include "Rook.h"

Rook::Rook(string type, bool c, int a, int b) : Figure (type, c, a, b) {
  //tbc
}

bool Rook::validMove (FigurePtr square[][8], string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  //The rook can only move vertically or horizontally.
  //That is, the following set of moves is valid:
  //absvalue[X][0]
  //absvalue[0][X]
  //Note that this assumes that it is also being checked for valid destination
  //and the route itself
  if ((abs(horizontal) == 0) || ((abs(vertical) == 0)))
    return true;

  return false;
}

bool Rook::validRoute(FigurePtr square[][8], string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;
  bool result;

  //We want to check the route for all cases that the Rook moves more than 1 field
  //The other case is already covered in the "destination" check
  if ((abs(horizontal) == 1) || (abs(vertical) == 1))
    return true;
  else {
  if (horizontal > 1) {
    for (int i = 1; i < horizontal; i++) {
      if (square[file+1][rank] == NULL)
        result = true;
      else
        result = false;
    }
  }

  if (horizontal < -1) {
    for (int i = 1; i < horizontal; i++) {
      if (square[file-1][rank] == NULL)
        result = true;
      else
        result = false;
    }
  }

  if (vertical > 1) {
    for (int i = 1; i < horizontal; i++) {
      if (square[file][rank+i] == NULL)
        result = true;
      else
        result = false;
    }
  }


  if (vertical < -1) {
    for (int i = 1; i < horizontal; i++) {
      if (square[file][rank-i] == NULL)
        result = true;
      else
        result = false;
    }
  }
}
  return result;

}

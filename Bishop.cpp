//Implementation file for Bishop
#include "Bishop.h"

Bishop::Bishop(string type, bool c, int a, int b) : Figure (type, c, a, b) {
//tbc
}

//The rook can only move diagonal.
//That is, the following set of moves is valid:
//absvalue[X][Y] where X == Y
//Note that this assumes that it is also being checked for valid destination
//and the route itself
bool Bishop::validMove(FigurePtr square[][8], string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  //cout << "Horizontal movement " << horizontal << endl;
  //cout << "Vertical movement " << vertical << endl;


  if (abs(horizontal) == abs(vertical))
    return true;

  return false;
}

bool Bishop::validRoute(FigurePtr square[][8], string currPos, string newPos) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;
  bool result = false;

  /*Possibility 1: Bishop moves in a "double positive" diagonal */
    if ((horizontal > 0) && (vertical>0)) {
    for (int i = 1; i < abs(horizontal); i++) {
      if (square[file+i][rank+i] == NULL)
        result = true;
      else
        return false;
    }
  }
    if (result == true)
      return result;

  /*Possibility 2: Bishop moves in a "positive/negative" diagonal */
    if ((horizontal > 0) && (vertical<0)) {
    for (int i = 1; i < abs(horizontal); i++) {
      if (square[file+i][rank-i] == NULL)
        result = true;
      else
        return false;
    }
  }
    if (result == true)
      return result;

  /*Possibliity 3: Bishop moves in a "negative/positive" diagonal */
    if ((horizontal < 0) && (vertical>0)) {
    for (int i = 1; i < abs(horizontal); i++) {
      if (square[file-i][rank+i] == NULL)
        result = true;
      else
        return false;
      }
    }
    if (result == true)
      return result;

    /*Possibliity 4: Bishop moves in a "double negative" diagonal */
      if ((horizontal < 0) && (vertical<0)) {
      for (int i = 1; i < abs(horizontal); i++) {
        if (square[file-i][rank+i] == NULL)
          result = true;
        else
          return false;
        }
      }

    return result;

  }

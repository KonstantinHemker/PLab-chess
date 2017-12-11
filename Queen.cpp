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

  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;
  bool result;

//We only want to check the route for all cases that the queen moves by more than 1 field

if ((abs(horizontal == 1) || abs(vertical) == 1))
  return true;
else {
if (horizontal > 1) {
  for (int i = 1; i < horizontal; i++) {
    if (square[file][rank+i] == NULL)
      result = true;
    else
      result = false;
  }
}

if (horizontal < -1) {
  for (int i = 1; i < horizontal; i++) {
    if (square[file][rank-i] == NULL)
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


if (abs(horizontal == 1))
  return true;
else {
/*Possibility 1: Queen moves in a "double positive" diagonal */
if ((horizontal > 1) && (vertical > 1)) { //>1 because if we only move by one, this will be checked by the
  //destination check
  for (int i = 1; i < abs(horizontal); i++) {
    if (square[file+i][rank+i] == NULL)
      result = true;
    else
      return false;
  }
}
  if (result == true)
    return result;

/*Possibility 2: Queen moves in a "positive/negative" diagonal */
  if ((horizontal > 1) && (vertical < -1)) {
  for (int i = 1; i < abs(horizontal); i++) {
    if (square[file+i][rank-i] == NULL)
      result = true;
    else
      return false;
  }
}
  if (result == true)
    return result;

/*Possibliity 3: Queen moves in a "negative/positive" diagonal */
  if ((horizontal < -1) && (vertical > 1)) {
  for (int i = 1; i < abs(horizontal); i++) {
    if (square[file-i][rank+i] == NULL)
      result = true;
    else
      return false;
    }
  }
  if (result == true)
    return result;

  /*Possibliity 4: Queen moves in a "double negative" diagonal */
    if ((horizontal < -1) && (vertical < -1)) {
    for (int i = 1; i < abs(horizontal); i++) {
      if (square[file-i][rank-i] == NULL)
        result = true;
      else
        return false;
      }
    }
}
  return result;
}

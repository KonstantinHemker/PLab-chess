//Implementation file for the rook

#include "Rook.h"

Rook::Rook(string type, bool c, int a, int b) : Figure (type, c, a, b) {
  //deliberately empty
}

bool Rook::validMove (FigurePtr square[][8], string currPos, string newPos) {
  bool output = straightMove(square, currPos, newPos, rank, file);
  return output;

}

bool Rook::straightMove(FigurePtr square[][8], string currPos, string newPos, int rank, int file) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  if (((abs(horizontal) == 0) && (abs(vertical) > 0)) || ((abs(vertical) == 0) && (abs(horizontal) > 0 )))
    return true;

  return false;
}

bool Rook::validRoute(FigurePtr square[][8], string currPos, string newPos) {

  bool output  = straightRoute(square, currPos, newPos, rank, file);
  return output;
}


bool Rook::straightRoute(FigurePtr square[][8], string currPos, string newPos, int rank, int file) {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;
  bool result;

  //We want to check the route for all cases that the Rook moves more than 1 field
  //The other case is already covered in the "destination" check
  if (((abs(horizontal) == 1) && (vertical == 0))|| ((abs(vertical) == 1) && (horizontal == 0)))
  return true;

/*Possiblity 1: Rook moves "North"*/
else {
if (horizontal > 1) {
  for (int i = 1; i < horizontal; i++) {
    if (square[file+i][rank] == NULL)
      result = true;
    else
      return false;
  }
}

/*Possibility 2: Rook moves "South"*/
if (horizontal < -1) {
  for (int i = 1; i < abs(horizontal); i++) {
    if (square[file-i][rank] == NULL)
      result = true;
    else
      return false;
  }
}

/*Possibility 3: Rook moves "East"*/
if (vertical > 1) {
  for (int i = 1; i < vertical; i++) {
    if (square[file][rank+i] == NULL)
      result = true;
    else
      return false;
  }
}

/*Possibility 3: Rook moves "West"*/
if (vertical < -1) {
  for (int i = 1; i < abs(vertical); i++) {
    if (square[file][rank-i] == NULL)
      result = true;
    else
      return false;
  }
}
}
  return result;

}

//Implementation file for pawn
#include "Pawn.h"

Pawn::Pawn(string type, bool c, int a, int b) : Figure (type, c, a, b) {
  //tbc
}

bool Pawn::validMove(FigurePtr square[][8], string currPos, string newPos)  {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  //We cannot deal with absolute values in the case of the pawn, because it can
  //only ever move into one vertical direction of the board. Hence, the valid movement
  //of the pawn depends on its (1) colour, (2) whether it's the pawn's first move and
  //(3) whether there is a figure of the opposite colours in the immediate
  // diagonal fields "in front" of the pawn

  //Condition(1): Colour white
  if (colour == 0)  {
    if ((rank = 1) && ((vertical == 1) || (vertical == 2)) && (horizontal == 0))
      return true;
    if ((rank > 1) && (vertical == 1) && (horizontal == 0))


    //Condition(2): Immediate diagonal fields
    if (file < 7) { //avoids the rightmost edge case
    if (square[file+1][rank+1] != NULL) {
      if ((square[file+1][rank+1]->getColour() != 0) && (vertical == 1) && (horizontal == 1))
        return true;
    }
  }
    if (file > 0) { // avoids the leftmost edge case
    if (square[file-1][rank+1] != NULL) {
      if ((square[file-1][rank+1]->getColour() != 0) && (vertical == -1) && (horizontal == 1))
        return true;
    }
  }
}

  //Condition(1): Colour Black
  if (colour == 1)  {
    if ((rank = 6) && ((vertical == -2) || (vertical == -1)) && (horizontal == 0))
      return true;
    if ((rank < 6) && (vertical == -1) && (horizontal == 0))
      return true;


  if (file < 7) { //avoids the rightmost edge case
  if (square[file-1][rank-1] != NULL) {
    if ((square[file-1][rank-1]->getColour() != 1) && (vertical == -1) && (horizontal == -1))
      return true;
    }
  }

  if (file > 0)
  if (square[file+1][rank-1] != NULL) {
    if ((square[file+1][rank-1]->getColour() != 1)  && (vertical == 1) && (horizontal == -1))
      return true;
    }

  }
  return false;

}


/*
bool Pawn::validRoute(FigurePtr square[][8], string currPos, string newPos) {
  int horizontal = gF(newPos) - file;
  int vertical = gR(newPos) - rank;

  //for white figures
  if (colour == 0) {

    if ((rank == 1) && (vertical == 2)) {
      if (square[file][rank+1] != NULL)
	return false;
    }
  }

  if (colour == 1)  {

    if ((rank == 6) && (vertical == -2)) {
      if (square[file][rank-1] != NULL)
	return false;
    }

    return true;
  }
}
*/	

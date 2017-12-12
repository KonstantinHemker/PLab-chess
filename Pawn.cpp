//Implementation file for pawn
#include "Pawn.h"

Pawn::Pawn(string type, bool c, int a, int b) : Figure (type, c, a, b) {
  //tbc
}

bool Pawn::validMove(FigurePtr square[][8], string currPos, string newPos)  {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;



  /*Condition(1): Colour white*/
  if (colour == 0)  {

  /*Condition (2): First or second move*/
    if ((rank == 1) && ((vertical == 1) || (vertical == 2)) && (horizontal == 0)) {
      if ((square[file][rank+1] == NULL) && (square[file][rank +2] == NULL))
        return true;
      }
    if ((rank > 1) && (vertical == 1) && (horizontal == 0)) {
      if ((square[file][rank+1]) == NULL)
        return true;
      }

    /*Condition(3): Immediate diagonal fields*/
    if ((file < 7) && (file > 0)) {
      if (square[file+1][rank+1] != NULL) {
	if ((square[file+1][rank+1]->getColour() != 0) && (vertical == 1) && (horizontal == 1))
	  return true;
      }
      if (square[file-1][rank+1] != NULL) {
	if ((square[file-1][rank+1]->getColour() != 0) && (vertical == 1) && (horizontal == -1))
	return true;
      }
    }
    //edge case
    if (file == 0) {
      if (square[file+1][rank+1] != NULL) {
      if ((square[file+1][rank+1]->getColour() != 0) && (vertical == 1) && (horizontal == 1))
	return true;
    }
    }
    //edge case
    if (file == 7) {
      if (square[file-1][rank+1] != NULL) {
      if ((square[file-1][rank+1]->getColour() !=0) && (vertical == 1) && (horizontal == -1))
	return true;
    }
    }
  }


  //Condition(1): Colour Black
  if (colour == 1)  {

  /*Condition (2): First or second move*/
    if ((rank == 6) && ((vertical == -2) || (vertical == -1)) && (horizontal == 0)) {
      if ((square[file][rank-1] == NULL) && (square[file][rank -2] == NULL))
      return true;
    }

    if ((rank < 6) && (vertical == -1) && (horizontal == 0)) {
      if ((square[file][rank-1]) == NULL)
      return true;
    }


  /*Condition(3): Immediate diagonal fields (non edge pawns)*/
    if ((file < 7) && (file > 0)) { //avoids the rightmost/leftmost edge case
  if (square[file+1][rank-1] != NULL) {
    if ((square[file+1][rank-1]->getColour() != 1) && (vertical == -1) && (horizontal == +1))
      return true;
  }

    if (square[file-1][rank-1] != NULL) {
    if ((square[file-1][rank-1]->getColour() != 1)  && (vertical == -1) && (horizontal == -1))
      return true;
    }
  }

  //edge case
  if (file == 0) {
    if (square[file+1][rank-1] != NULL)
      if ((square[file+1][rank-1]->getColour() != 1) && (vertical == -1) && (horizontal == -1))
	return true;
	}
  //edge case
  if (file == 7) {
  if (square[file-1][rank-1] != NULL) {
    if ((square[file-1][rank-1]->getColour() != 1)  && (vertical == -1) && (horizontal == 1))
      return true;
    }

  }
  }
  return false;
  }






bool Pawn::validRoute(FigurePtr square[][8], string currPos, string newPos) {
  int horizontal = gF(newPos) - file;
  int vertical = gR(newPos) - rank;

  //for white figures
  if (colour == 0) {
    if ((rank == 1) && (vertical == 2)) {
      if (square[file][rank+1] == NULL)
	     return true;
      else
        return false;
    }
  }

  if (colour == 1)  {

    if ((rank == 6) && (vertical == -2)) {
      if (square[file][rank-1] == NULL)
       return true;
      else
       return false;
    }

  }
  return true;
}

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
    if ((rank = 1) && (vertical == 2))
      return true;
    if ((rank > 1) && (vertical == 2))

    //Condition(2): Immediate diagonal fields
    if (square[file+1][rank+1] != NULL) {
      if ((square[file+1][rank+1]->getColour() != 0) && (vertical == 1) && (horizontal == 1))
        return true;
    }

    if (square[file+1][rank-1] != NULL) {
      if ((square[file+1][rank-1]->getColour() != 0) && (vertical == 1) && (horizontal == -1))
        return true;
    }

  //Condition(1): Colour Black
  if (colour == 1)  {
    if ((rank = 6) && (vertical == -2))
      return true;
    if ((rank < 6) && (vertical == -1))
      return true;


  if (square[file-1][rank+1] != NULL) {
    if ((square[file-1][rank+1]->getColour() != 1) && (vertical == -1) && (horizontal == 1))
      return true;
    }
  if (square[file-1][rank-1] != NULL) {
    if ((square[file-1][rank-1]->getColour() != 1)  && (vertical == -1) && (horizontal == -1))
      return true;
    }

  }
  }
  return false;

}

/*
bool Pawn::validRoute(FigurePtr square[][8], string currPos, string newPos) {
  //deliberately empty
  //no route check required as the destination is the only step in the route
}
*/

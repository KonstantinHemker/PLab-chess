//Header file for pawn
#ifndef PAWN_H
#define PAWN_H

//#include "ChessBoard.h"
#include "Figure.h"

class Pawn : public Figure  {
 private:
 public:
  Pawn (string type, bool c, int a, int b);

  //Validates that the pawn's move is legal according to standard chess rules
  //We cannot deal with absolute values in the case of the pawn, because it can
  //only ever move into one vertical direction of the board. Hence, the valid movement
  //of the pawn depends on its (1) colour, (2) whether it's the pawn's first move and
  //(3) whether there is a figure of the opposite colours in the immediate
  // diagonal fields "in front" of the pawn


  //Precondition: Given the current position and new position of the move as well as
  //the current state of the board.
  //Postcondition: Checks the validity of the move and return "true" is the move
  //is legit
  //Note that this function has quite a lot of edge cases to consider, that may
  //not be obvious at first sight
  bool validMove (FigurePtr square[][8], string currPos, string newPos) override;

  //Function that checks the route for the pawn. The pawn possibly can only have
  //a route in its first move if it moves by two places. This function checks whether
  //the fields that it passes on the way are NULL pointers, i.e. empty fields.
  bool validRoute (FigurePtr square[][8], string currPos, string newPos) override;
};

#endif

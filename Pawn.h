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
  bool validMove (FigurePtr square[][8], string currPos, string newPos) override;

  //Function that checks the route for the pawn. The pawn possibly can only have
  //a route in its first move if it moves by two places. This function checks whether
  //the fields that it passes on the way are NULL pointers, i.e. empty fields.
  bool validRoute (FigurePtr square[][8], string currPos, string newPos) override;
};

#endif

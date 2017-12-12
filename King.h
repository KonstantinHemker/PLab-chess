#ifndef KING_H
#define KING_H

#include "Figure.h"


class King : public Figure  {
 private:

 public:
   //Constructor of the King which only calls the base class initializer
  King(string type, bool c, int a, int b);

  //Function that determines the set of valid moves for the King
  //The King can move only one step in any direction, meaning that we can
  //think of this in abolute value terms as follows:
  //absvalue[1][0]
  //absvalue[0][1]
  //absvalue[1][1]
  //where the values in parentheses are [horizontal move][vertical move]
  //Note that this assumes that we already accounted for invalid destination
  //(outside of chessboard or own figure)
  //Precondition: Is given the current position and future position of the move
  //Postcondition: Evaluates as "true"
  bool validMove  (FigurePtr square[][8], string currPos, string newPos) override;
};

#endif

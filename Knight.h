//Header file for knight
#ifndef KNIGHT_H
#define KNIGHT_H

//#include "ChessBoard.h"
#include "Figure.h"

class Knight : public Figure  {
 private:
 public:
  //Constructor of the Knight which only calls the base class initializer
  Knight(string type, bool c, int a, int b);

  //Function that determines the set of valid moves for the Knight
  //This states that the absolute values of the move must be
  //either 1 or 2, or 1 or 2. We can think of this as two options:
  //absvalue[1][2]
  //absvalue[2][1]
  //where the values in parentheses are [horizontal move][vertical move]
  //Note that this assumes that we already accounted for invalid destination
  //(outside of chessboard or own figure)
  //Precondition: Is given the current position and future position of the move
  //Postcondition: Evaluates as "true"
  bool validMove (FigurePtr square[][8], string currPos, string newPos) override;
};

#endif

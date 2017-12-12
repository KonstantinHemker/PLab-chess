//Header file for bishop
#ifndef BISHOP_H
#define BISHOP_H

//#include "ChessBoard.h"
#include "Figure.h"

class Bishop : public Figure {
 private:
 public:
   //Constructor of the Bishop which only calls the base class initializer
   Bishop(string type, bool c, int a, int b);

   //These two functions determine the set of valid moves for the Bishop
   //The Bishop can only move diagonal.
   //That is, the following set of moves is valid:
   //absvalue[X][Y] where X == Y
   //Note that this assumes that it is also being checked for valid destination
   //and the route itself
   //Precondition: Is given the current position and future position of the move
   //Postcondition: Evaluates as "true" if the move is valid
   //Note that the static function is later used for the Queen
   bool validMove (FigurePtr square[][8], string currPos, string newPos) override;
   static bool diagonalMove(FigurePtr square[][8], string currPos, string newPos, int rank, int file);


   //These two functions determine whether the route towards the destination of
   //the Bishop is valid. That is, each field on the way must be empty, i.e.
   // a null pointer
   //Precondition: Is given the current position and future position of the move
   //Postconditon: Checks whether each field on the way to the destination is empty
   bool validRoute(FigurePtr square[][8], string currPos, string newPos) override;
   static bool diagonalRoute(FigurePtr square[][8], string currPos, string newPos, int rank, int file);
};

#endif

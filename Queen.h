//Header File for queen
#ifndef QUEEN_H
#define QUEEN_H

//#include "ChessBoard.h"
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"

class Queen : public Figure{
 private:
//converted ASCII characters
 public:
  //Constructor of the Queen which only calls the base class initializer
  Queen(string type, bool c, int a, int b);

  //The queen essentially combines the valid moves of the rook and the bishop.
  //That is, the following set of moves is valid:
  //absvalue[X][0]
  //absvalue[0][X]
  //absvalue[X][Y] where X == Y
  //Note that this assumes that it is also being checked for valid destination and
  //the route itself
  //Precondition: Is given the current position and destination of the move
  //Postconditon: Validates the move according to the rules above and returns "true"
  //if the move is valid (note that this doesn't include the route to get to the destination)
  bool validMove (FigurePtr square[][8], string currPos, string newPos) override;

  //Similarly to the "validMove" member function, this function combines the elements
  //of the rook and the bishop by calling their static member function that validate
  //the route for vertical, horizontal, and diagonal directions
  //Precondition: Is given the current position and future position of the move
  //Postcondition: Evalues as "true if the move is valid"
  bool validRoute(FigurePtr square[][8], string currPos, string newPos) override;
};
#endif

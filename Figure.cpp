//Implementation file for the figure class

#include "Figure.h"

Figure::Figure(string input_type, bool input_colour, int input_file, int input_rank) {
  type = input_type;
  colour = input_colour;
  rank = input_rank;
  file = input_file;
  //cout << "Figure " << this << " has rank " << rank << " and file " << file << endl;
}

void Figure::updatePosition(string newPos)  {
  file = gF(newPos);
  rank = gR(newPos);
}


void Figure::validStep(FigurePtr square[][8], string newPos, string currPos, int error_code) {

  //Check the whether the move is legal for respective figure
  if (square[gF(currPos)][gR(currPos)]->validMove(square, currPos, newPos) == false) {
    error_code = INVALID_MOVE;
    cerr << "Invalid move of " << square[gF(currPos)][gR(currPos)]->getType();
    cerr << " from " << currPos << " to " << newPos << endl;
    return;
  }


  //Destination
  if (square[gF(currPos)][gR(currPos)]->validDestination(square, newPos, currPos) == false)  {
    square[gF(currPos)][gR(currPos)]->DestinationError(square, newPos, currPos);
    error_code = INVALID_DESTINATION;
    return;
  }

  //Route
  if (square[gF(currPos)][gR(currPos)]->validRoute(square, newPos, currPos) == false) {
    error_code = INVALID_ROUTE;
    cerr << "Invalid route of " << square[gF(currPos)][gR(currPos)]->getType();
    cerr << " from " << currPos << " to " << newPos << endl;
  }


}

bool Figure::validRoute(FigurePtr square[][8], string currPos, string newPos) {

  return true; //will be adjusted for the rook, the queen and the bishop
}

bool Figure::validDestination(FigurePtr square[][8], string newPos, string currPos)  {

  //Validity Condition(1): Empty field
  if (square[gF(newPos)][gR(newPos)] == NULL)
    return true;

  //Validity Condition(2): Destination is not the King (cannot beat King)
  if (square[gF(newPos)][gR(newPos)]->getType() == "King")
    return false;

  //Validity Condition(3): Opponent chess piece
  if (square[gF(newPos)][gR(newPos)]-> getColour() != square[gF(currPos)][gR(currPos)]->getColour())
    return true;

  return false;
}

/*
virtual bool Figure::validRoute(string currPos, string newPos)  {

  createRoute(string currPos, newPos);

}
*/



void Figure::DestinationError(FigurePtr square[][8], string newPos, string currPos) {
  cerr << "Invalid Destination for ";
  square[gF(currPos)][gR(currPos)]->printColour();
  cerr << "'s move attempt ";
  cerr << "to move from " << currPos << " to " << newPos << endl;
}


string Figure::getPosition()  {
  string temp;
  temp = rank + file;
  return temp;
}

string Figure::getType()  {
  return type;
}

bool Figure::getColour() {
  return colour;
}

void Figure::printColour() {
  if (colour == 0)
    cout << "White";
  else
    cout << "Black";
}

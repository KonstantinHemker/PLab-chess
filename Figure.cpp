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

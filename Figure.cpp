//Implementation file for the figure class

#include "Figure.h"

Figure::Figure(string input_type, bool input_colour, int input_rank, int input_file) {
  colour = input_colour;
  rank = input_rank;
  file = input_file;
  type = input_type;
}

void Figure::updatePosition(string newPos)  {
  rank = gR(newPos);
  file = gF(newPos);
}

bool Figure::validDestination(FigurePtr square[][8], string newPos, string currPos)  {

  //Validity Condition(1): Empty field
  if (square[gR(newPos)][gF(newPos)] == NULL)
    return true;

  //Validity Condition(2): Destination is not the King (cannot beat King)
  if (square[gR(newPos)][gF(newPos)]->getType() == "King")
    return false;

  //Validity Condition(3): Opponent chess piece
  if (square[gR(newPos)][gF(newPos)]-> getColour() != square[gR(currPos)][gF(currPos)]->getColour())
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
  square[gR(currPos)][gF(currPos)]->printColour();
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

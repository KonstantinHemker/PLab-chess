//Implementation file for the figure class

#include "Figure.h"


Figure::Figure(string input_type, bool input_colour, int input_rank, int input_file) {
  colour = input_colour;
  rank = input_rank;
  file = input_file;
  type = input_type;
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

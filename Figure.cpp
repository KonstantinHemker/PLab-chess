//Implementation file for the figure class

#include "Figure.h"

Figure::Figure(string input_type, bool input_colour, int input_file, int input_rank) {
  type = input_type;
  colour = input_colour;
  rank = input_rank;
  file = input_file;
}

void Figure::updatePosition(FigurePtr square[][8], string newPos)  {

  file = gF(newPos);
  rank = gR(newPos);

  //Update the legal moves for each figure on the field

  /*
  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
    if (square[i][c] != NULL)
      square[i][c]->getValidMoves(square);
    }
  }
*/
  if (square[1][0] == NULL)
  cout << "NULL" << endl;
  cout << square[1][0]-> getType() << endl;
  square[1][0] -> getValidMoves(square);

}


bool Figure::validStep(FigurePtr square[][8], string currPos, string newPos, int &error_code) {
/*DO NOT CHANGE ORDER OF CHECKS*/

  //Check the whether the move is legal for respective figure
  if (square[gF(currPos)][gR(currPos)]->validMove(square, currPos, newPos) == false) {
    error_code = INVALID_MOVE;
    cerr << "Invalid move of " << square[gF(currPos)][gR(currPos)]->getType();
    cerr << " from " << currPos << " to " << newPos << endl;
    return false;
  }

  //Destination
  if (square[gF(currPos)][gR(currPos)]->validDestination(square, currPos, newPos) == false)  {
    error_code = INVALID_DESTINATION;
    cerr << "Invalid Destination for ";
    square[gF(currPos)][gR(currPos)]->printColour();
    cerr << "'s move attempt ";
    cerr << "to move from " << currPos << " to " << newPos << endl;
    return false;
  }

  //Route
  if (square[gF(currPos)][gR(currPos)]->validRoute(square, newPos, currPos) == false) {
    error_code = INVALID_ROUTE;
    cerr << "Invalid route of " << square[gF(currPos)][gR(currPos)]->getType();
    cerr << " from " << currPos << " to " << newPos << endl;
    return false;
  }
}

void Figure::getValidMoves(FigurePtr square[][8]) {
  string newPos;
  string currPos = getPosition();
  int count = 0;

  bool condition1, condition2, condition3;

  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
      newPos = createNewPos(i, c);
      condition1 = validRoute(square, currPos, newPos);
      condition2 = validDestination(square, currPos, newPos);
      condition3 = validMove(square, currPos, newPos);

      if ((condition1 == true) && (condition2 == true) && (condition3 == true)) {
        legalMove[count] = newPos;
        count++;
      }
    }

  }

  cout << getType() << getColour() << legalMove[0] << endl;
  cout << getType() << getColour() << legalMove[1] << endl;
  cout << getType() << getColour() << legalMove[2] << endl;
  cout << getType() << getColour() << legalMove[3] << endl;
  //Loop through all fields on the board and check whether they are a valid move

  //do something
}

string Figure::createNewPos(int i, int c)  {
  string file; //Note that this is deliberately temporarily overloading the variable name
  string rank;
  string output;

  file = i + 65; //corresponds to ASCII table letter
  rank = c + 49; //corresponds to ASCII table digits
  output = file + rank;

  return output;
}

string Figure::getPosition() {
  string letter;
  string number;

  letter = file + 65;
  number = rank + 49;
  string output = letter + number;

  return output;
}

bool Figure::validRoute(FigurePtr square[][8], string currPos, string newPos) {

  return true; //will be adjusted for the rook, the queen and the bishop
}

bool Figure::validDestination(FigurePtr square[][8], string currPos, string newPos)  {

  //Validity Condition(1): Empty field
  if (square[gF(newPos)][gR(newPos)] == NULL)
    return true;

  //Validity Condition(2): Destination is not the King (cannot beat King)
  if (square[gF(newPos)][gR(newPos)]->getType() == "King")
    return true;

  //Validity Condition(3): Opponent chess piece
  if (square[gF(newPos)][gR(newPos)]-> getColour() != square[gF(currPos)][gR(currPos)]->getColour())
    return true;



  return false;
}


/*
void Figure::DestinationError(FigurePtr square[][8], string newPos, string currPos) {
  cerr << "Invalid Destination for ";
  square[gF(currPos)][gR(currPos)]->printColour();
  cerr << "'s move attempt ";
  cerr << "to move from " << currPos << " to " << newPos << endl;
}
*/


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

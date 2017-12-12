//Implementation file for the figure class

#include "Figure.h"

Figure::Figure(string input_type, bool input_colour, int input_file, int input_rank) {
  type = input_type;
  colour = input_colour;
  rank = input_rank;
  file = input_file;
}

void Figure::updatePosition(FigurePtr square[][8], string currPos, string newPos, bool turn, string &winston, string &charles)  {

  file = gF(newPos);
  rank = gR(newPos);

//Updating the King if applicable
  if (getType() == "King") {
    if (turn == 0)
      winston = getPosition(square, file, rank);
    if (turn == 1)
      charles = getPosition(square, file, rank);
  }

//Resetting the array of valid moves
  for (int i = 0; i < 30;  i++) {
    legalMove[i] = "";
  }
}


bool Figure::checkCheck(FigurePtr square[][8], int i, int c, bool turn, string winston, string charles) {
  if (turn == 0) {
    for (int n = 0; n < 30 ; n++) {
      if (legalMove[n] == charles)
	return true;
    }
  }


  if (turn == 1) {
    for (int n = 0; n < 30; n++) {
      if (legalMove[n] == winston)
	return true;
    }
  }

  return false;
}




bool Figure::validStep(FigurePtr square[][8], string currPos, string newPos, int &error_code, bool turn, bool &steal) {
/*DO NOT CHANGE ORDER OF CHECKS*/

  //Check the whether the move is legal for respective figure
  if (square[gF(currPos)][gR(currPos)]->validMove(square, currPos, newPos) == false) {
    error_code = INVALID_MOVE;
    cerr << "Invalid move of " << square[gF(currPos)][gR(currPos)]->getType();
    cerr << " from " << currPos << " to " << newPos << endl;
    return false;
  }

  //Destination
  if (square[gF(currPos)][gR(currPos)]->validDestination(square, currPos, newPos, turn, steal) == false)  {
    error_code = INVALID_DESTINATION;
    cerr << "Invalid Destination for ";
    square[gF(currPos)][gR(currPos)]->printColour();
    cerr << "'s move attempt ";
    cerr << "to move from " << currPos << " to " << newPos << endl;
    return false;
  }

  //Route
  if (square[gF(currPos)][gR(currPos)]->validRoute(square, currPos, newPos) == false) {
    error_code = INVALID_ROUTE;
    cerr << "Invalid route of " << square[gF(currPos)][gR(currPos)]->getType();
    cerr << " from " << currPos << " to " << newPos << endl;
    return false;
  }
  return true;

}


string Figure::getValidMove(int n) {
  return legalMove[n];
}

int Figure::getFile() {
  return file;
}

int Figure::getRank() {
  return rank;
}


void Figure::writeMove(int count, string newPos) {
  legalMove[count] = newPos;
  //cout << getType() << legalMove[count];
  //printColour();
  //cout << endl;
  }

bool Figure::validRoute(FigurePtr square[][8], string currPos, string newPos) {
  return true; //will be adjusted for the rook, the queen and the bishop
}


bool Figure::validDestination(FigurePtr square[][8], string currPos, string newPos, bool turn, bool &steal)  {
  int fNew = gF(newPos);
  int rNew = gR(newPos);

  //Validity Condition(1): Empty field
  if (square[fNew][rNew] == NULL) {
    return true;
  }

  //Validity Condition(2): Opponent chess piece
    if (square[fNew][rNew]->getColour() != turn) {
    steal = true;
    return true;
    }

  return false;
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

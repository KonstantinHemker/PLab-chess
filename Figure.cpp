//Implementation file for the figure class

#include "Figure.h"

Figure::Figure(string input_type, bool input_colour, int input_file, int input_rank) {
  type = input_type;
  colour = input_colour;
  rank = input_rank;
  file = input_file;
}

void Figure::updatePosition(FigurePtr square[][8], string newPos, bool turn)  {

  file = gF(newPos);
  rank = gR(newPos);

  //Update the legal moves for each figure on the field


  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
    if (square[i][c] != NULL)
      square[i][c]->loadValidMoves(square, turn);
    }
  }


  cout << this->getType() << " legal move: " << legalMove[0] << endl;

  cout << this->getType() << " legal move: " << legalMove[1] << endl;

  //cout << this->getType() << " legal move: " << legalMove[2] << endl;

  /*
  if (square[0][0] == NULL)
  cout << "NULL" << endl;
  //cout << square[0][0]-> getType() << endl;
  square[A][0] -> loadValidMoves(square);
  */
}


bool Figure::checkCheck(FigurePtr square[][8], int i, int c, bool turn, string winston, string charles) {
  if ((turn == 0) && (square[i][c]->getColour() != turn))  {
    for (int n = 0; n < legalMove.size(); n++) {
      if (legalMove[n] == winston)
	return true;
    }
  }

  if ((turn == 1) && (square[i][c]->getColour() != turn)) {
    for (int n = 0; n < legalMove.size(); n++) {
      if (legalMove[n] == charles)
	return true;
    }
  }

return false;
}



string Figure::validMove(int n) {
  return legalMove[n];
}


bool Figure::validStep(FigurePtr square[][8], string currPos, string newPos, int &error_code, bool turn) {
/*DO NOT CHANGE ORDER OF CHECKS*/

  //Check the whether the move is legal for respective figure
  if (square[gF(currPos)][gR(currPos)]->validMove(square, currPos, newPos) == false) {
    error_code = INVALID_MOVE;
    cerr << "Invalid move of " << square[gF(currPos)][gR(currPos)]->getType();
    cerr << " from " << currPos << " to " << newPos << endl;
    return false;
  }

  //Destination
  if (square[gF(currPos)][gR(currPos)]->validDestination(square, currPos, newPos, turn) == false)  {
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

void Figure::loadValidMoves(FigurePtr square[][8], bool turn) {
  string newPos;
  string currPos = getPosition();//current position of the pawn after
  int count = 0;

  bool condition1, condition2, condition3;

  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
      newPos = createNewPos(i, c);
      condition1 = validRoute(square, currPos, newPos);
      condition2 = validDestination(square, currPos, newPos, turn);
      condition3 = validMove(square, currPos, newPos);

      if ((condition1 == true) && (condition2 == true) && (condition3 == true)) {
	legalMove.insert(legalMove.begin(), newPos);
	//legalMove[cout << square[gF(newPos)][gR(newPos)]->getFile() << square[gF(newPos)][gR(newPos)]->getRank();count] = newPos;
        count++;
      }
    }

  }

  return;
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

bool Figure::validDestination(FigurePtr square[][8], string currPos, string newPos, bool turn)  {

  //Validity Condition(1): Empty field
  if (square[gF(newPos)][gR(newPos)] == NULL) {
    //cout << "NULL" << endl;
    return true;
  }

  //Validity Condition(2): Destination is not the King (cannot beat King)
  if ((square[gF(newPos)][gR(newPos)]->getType() == "King") &&
      //(getColour() != turn)) {
       (square[gF(newPos)][gR(newPos)]->getColour() != turn)) {
    //cout << "Destination not King" << endl;
    return true;
  }

  //Validity Condition(3): Opponent chess piece
  //if (getColour() != turn) {
  if (square[gR(newPos)][gR(newPos)] -> getColour() != turn) {
      //cout << "Opponent chess piece" << endl;
    return true;
    }


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

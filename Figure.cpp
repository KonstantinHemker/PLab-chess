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

  //empty array of previously valid Moves
  //legalMove.fill('\0');

  for (int i = 0; i < 50;  i++) {
    legalMove[i] = '\0';
}
  //Update the legal moves for each figure on the field

/*
  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
    if (square[i][c] != NULL)
      square[i][c]->getValidMoves(square, turn);
    }
  }
*/

  /*
  if (square[0][0] == NULL)
  cout << "NULL" << endl;
  //cout << square[0][0]-> getType() << endl;
  square[E][0] -> getValidMoves(square);
  */
}


bool Figure::checkCheck(FigurePtr square[][8], int i, int c, bool turn, string winston, string charles) {
  if (turn == 0) {
  //if ((turn == 0) && (square[i][c]->getColour() != turn))  {
    for (int n = 0; n < 50 ; n++) {
      if (legalMove[n] == charles)
	return true;
    }
  }


  if (turn == 1) {
  //if ((turn == 1) && (square[i][c]->getColour() != turn)) {
    for (int n = 0; n < 50; n++) {
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
}
/*
void Figure::getValidMoves(FigurePtr square[][8], bool turn) {
  string newPos;
  string currPos = getPosition();
  int count = 0;

  bool condition1, condition2, condition3;

  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
      newPos = createNewPos(i, c);
      condition1 = validRoute(square, currPos, newPos);
      condition2 = validDestination(square, currPos, newPos, turn);
      condition3 = validMove(square, currPos, newPos);

      if ((condition1 == true) && (condition2 == true) && (condition3 == true)) {
        legalMove[count] = newPos;
        count++;
  //Validity Condition(2): Destina
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
*/

string Figure::createNewPos(int i, int c)  {
  string f; //Note that this is deliberately temporarily overloading the variable name
  string r;
  string output;

  f = i + 65; //corresponds to ASCII table letter
  r = c + 49; //corresponds to ASCII table digits
  output = f + r;

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


int Figure::getArraySize() {
  int temp;
  temp = sizeof(legalMove)/sizeof(legalMove[0]);
  return temp;
}


//NOTE THE DUPLICATE - REMOVE REDUNDANCY!!
bool Figure::validDestination(FigurePtr square[][8], string currPos, string newPos, bool turn, bool &steal)  {
  int fNew = gF(newPos);
  int rNew = gR(newPos);

  //Validity Condition(1): Empty field
  if (square[fNew][rNew] == NULL) {
    return true;
  }

  //Validity Condition(2): Destination is not the King (cannot beat King)
  if ((square[fNew][rNew]->getType() == "King") &&
      (square[fNew][rNew]->getColour() != square[gF(currPos)][gR(currPos)]->getColour())) {
    return true;
  }

  //Validity Condition(3): Opponent chess piece
    if (square[fNew][rNew]->getColour() != turn) {
    steal = true;
    return true;
    }

  return false;
}

/* DO NOT DELETE THIS FUNCTION! SEG FAULT OTHERWISE*/
bool Figure::validDestPositions(FigurePtr square[][8], string currPos, string newPos, bool turn, bool &steal)  {
  //int fNew = gF(newPos);
  //int rNew = gR(newPos);

  //Validity Condition(1): Empty field
  //if (square[fNew][rNew] == NULL) {
  //  return true;
  //}

  //Validity Condition(2): Destination is not the King (cannot beat King)
  if ((getType() == "King") && (getColour() != turn)) {
    return true;
  }

  //Validity Condition(3): Opponent chess piece
    if (getColour() != turn) {
    steal = true;
    return true;
    }

  return false;
}


/*
void Figure::DestinationError(FigurePtr square[][8], string newPos, string currPos) {
  cerr << "Invalid Destination for ";
  square[gF(currPos)][gR(currPos)]->printColour();
  cerr << "'s move att, turnempt ";
  cerr << "to move from " << currPos << " to " << newPos << endl;
}, turn
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

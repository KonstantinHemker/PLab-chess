/*Implementation file for the chessboard*/

#include "ChessBoard.h"
#include "Figure.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

using namespace std;

/************************GLOBAL HELPER FUNCTIONS*****************************/
  string getPosition (FigurePtr square[][8], int i, int c) {
    string letter;
    string number;
    letter = square[i][c]->getFile() + 65;
    number = square[i][c]->getRank() + 49;
    string output = letter + number;

    return output;
    }


    int gF (string str) {
      char target;
      target = str[0];
      return target-65;
    }

    int gR (string str) {
      char temp = str[1];
      int x = temp - '0';
      return x-1;
    }




/*******************MEMBER FUNCTIONS OF THE CHESSBOARD************************/
ChessBoard::ChessBoard () {

  turn = 0; //White always begins
  error_code = 0;

  square[4][0] = new King("King", 0, 4, 0);
  square[4][7] = new King("King", 1, 4, 7);
  square[3][0] = new Queen("Queen", 0, 3, 0);
  square[3][7] = new Queen("Queen", 1, 3, 7);
  square[0][0] = new Rook("Rook", 0, 0, 0);
  square[7][0] = new Rook("Rook", 0, 7, 0);
  square[0][7] = new Rook("Rook", 1, 0, 7);
  square[7][7] = new Rook("Rook", 1, 7, 7);
  square[1][0] = new Knight("Knight", 0, 1, 0);
  square[6][0] = new Knight("Knight", 0, 6, 0);
  square[1][7] = new Knight("Knight", 1, 1, 7);
  square[6][7] = new Knight("Knight", 1, 6, 7);
  square[2][0] = new Bishop("Bishop", 0, 2, 0);
  square[5][0] = new Bishop("Bishop", 0, 5, 0);
  square[2][7] = new Bishop("Bishop", 1, 2, 7);
  square[5][7] = new Bishop("Bishop", 1, 5, 7);

  //White Pawns
  for (int i = 0; i<8; i++)
    square[i][1] = new Pawn("Pawn", 0, i, 1);

  //Black Pawns
  for (int c = 0; c < 8 ; c++)
    square[c][6] = new Pawn("Pawn", 1, c, 6);

  for (int i = 0; i < 8 ; i++) {
    for (int c = 2; c < 6; c++)
      square[i][c] = NULL;
    }

    winston = "E1";
    charles = "E8";

    cout << "A new chess game is started!" << endl;
}

ChessBoard::~ChessBoard() {

  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
      if (square[i][c] != NULL)
        delete square[i][c]; // Imperial College?
    }
  }
}


    void ChessBoard::submitMove(string currPos, string newPos) {

      int fOld = gF(currPos);
      int rOld = gR(currPos);
      int fNew = gF(newPos);
      int rNew = gR(newPos);
      bool steal = false;

      //Check move
      checkMove(currPos, newPos, steal);
      if (error_code != 0) {
         return;
      }
      printMoveMessage(currPos, newPos, steal);
      //Make move
      FigurePtr temp = square[fOld][rOld];
      //delete square[fNew][rNew];
      square[fNew][rNew] = temp;
      square[fOld][rOld] = NULL;

      square[fNew][rNew]->updatePosition(square, currPos, newPos, turn, winston, charles);
      updateMoves(steal);

      if (checkCheck() == true) {
	       if (checkMate(steal) == true)
	        printCheckMate(turn);
	       else
	        printCheck(turn);
      }



      switchTurn();
    }

bool ChessBoard::checkMate(bool steal) {
  int fileKing;
  int rankKing;
  bool result;
  string tempMove;

  if (turn == 0) {
    fileKing = gF(winston);
    rankKing = gR(winston);
  }
  else {
    fileKing = gF(charles);
    rankKing = gR(charles);
  }
  //essentially, we want to check here for two options.
  //(1) Can the king move somewhere where he is not in check?
  //(2) Can any other figure of the team move somewhere where the King is not in check
  //That is, we want to simulate all the possible moves of each team that is in check
  //and check whether the King is still in Check after.
  //If there is nowhere he can go, we have the checkMate condition will evaluate
  //as true.


  //Condition 1+2: Moves of the other team members and the king
  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
      if ((square[i][c] != NULL) && (square[i][c]-> getColour() != turn)) {
	       for (int n = 0; n < 20; n++) {
	          tempMove = square[i][c]->getValidMove(n);
	          if(simMove(tempMove, i, c, steal) == true)
		    //simMove returns true if the King is still in chess after the simulated move
	           result = true;
	          else
	           return false;
	           }
           }
         }
       }

  return result;
  }


bool ChessBoard::simMove(string simPos, int i, int c, bool steal) {
  bool result;
  string oldPos = getPosition(square, i, c);
  FigurePtr temp;

  if (((i == gF(simPos)) && (c == gR(simPos))) || (simPos == "")) //nothing will change if we simulate a move to the own position
    return true;

  //We don't have to check the validity of the moves when we simulate,
  //as we only simulate the moves that have previously been validated

  //Make move
  temp = square[gF(simPos)][gR(simPos)]; //temporary pointer to avoid memory leak
  square[gF(simPos)][gR(simPos)] = square[i][c];
  square[i][c] = NULL;

  square[gF(simPos)][gR(simPos)]-> updatePosition(square, oldPos, simPos, turn, winston, charles);
  updateMoves(steal);

  //The board is now in a state where the move we want to simulate has been made

  //Check whether the King is still in Check
  if(checkCheck() == true)
  result = true;
  else
  result = false;

  //Revert move
  square[i][c] = square[gF(simPos)][gR(simPos)];
  square[gF(simPos)][gR(simPos)] = temp;
  temp = NULL;

  square[i][c]->updatePosition(square, simPos, oldPos, turn, winston, charles);
  updateMoves(steal);
//Function

  return result;//only temporary
}


bool ChessBoard::checkCheck() {
  for(int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
      if (square[i][c] != NULL) {
	if (square[i][c]->checkCheck(square, i, c, turn, winston, charles) == true)
	  return true;

	//Function checks the valid moves only of the opponent figures

      }
    }
  }
  return false;
}

void ChessBoard::printCheckMate(bool turn) {
  if (turn == 0)
    cout << "Black is in checkmate" << endl;
  else
    cout << "White is in checkmate" << endl;
}


void ChessBoard::printCheck(bool turn) {
  if (turn == 0)
    cout << "Black is in check" << endl;
  else
    cout << "White is in check" << endl;
}

void ChessBoard::updateMoves(bool &steal) {
  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
      if (square[i][c] != NULL)  {
	string newPos;
	string currPos = getPosition(square, i, c);
	int count = 0;

	for (int n = 0; n < 8; n++) {
        for (int h = 0; h < 8; h++) {

	  bool condition1, condition2;
	  newPos = createNewPos(n, h);

	  if ((square[n][h] == NULL) || (square[n][h]->getColour() != square[i][c]->getColour())) {
	    //condition checks for the destination
	    condition1 = square[i][c]-> validRoute(square, currPos, newPos);
	    condition2 = square[i][c]-> validMove(square, currPos, newPos);

	    if ((condition1 == true) && (condition2 == true)) {
	      square[i][c]->writeMove(count, newPos); // = newPos;
	      count++;
	    }
	  }
	}
	}
  }
  }
  }
}



      string ChessBoard::createNewPos(int i, int c)  {
        string File; //Note that this is deliberately temporarily overloading the variable name
        string Rank;
        string output;

        File = i + 65; //corresponds to ASCII table letter
        Rank = c + 49; //corresponds to ASCII table digits
        output = File + Rank;

        return output;
      }

    void ChessBoard::checkMove(string currPos, string newPos, bool &steal) {
      error_code = 0; //reset error_code from previous checks
      //Check WRONG_MOVE
      if (square[gF(currPos)][gR(currPos)] == NULL) {
        error_code = NO_PIECE;
        cerr << "There is no piece at position " << currPos << "!" << endl;
        return;
      }

      //Check OUT_OF_BOUNDS
      if ((checkInput(currPos) == false) || (checkInput(newPos) == false)) {
        error_code = OUT_OF_BOUNDS;
        cerr << "Wrong input!" << endl;
        return;
      }


      //Check WRONG_TURN
      if (square[gF(currPos)][gR(currPos)]-> getColour() != turn) {
        error_code = WRONG_TURN;
        if (turn == 1) {
        cerr << "It is not White's turn to move" << endl;
        return;
      }
        else {
        cerr << "It is not Black's turn to move" << endl;
        return;
      }

    }

      square[gF(currPos)][gR(currPos)]-> validStep(square, currPos, newPos, error_code, turn, steal);

  }

  bool ChessBoard::checkInput(string input) {
    int number = gR(input);
    int letter = gF(input);

    if ((number < 0) || (number > 7) || (letter < 0) || (letter > 7))
      return false;

    return true;
  }

    void ChessBoard::switchTurn() {
      if (turn == 0)
        turn = 1;
      else
        turn = 0;
    }

    void ChessBoard::printMoveMessage(string currPos, string newPos, bool &steal)  {
      square[gF(currPos)][gR(currPos)]-> printColour();
      cout << "'s ";
      cout << square[gF(currPos)][gR(currPos)]-> getType();
      cout << " moves from " << currPos << " to " << newPos;

      if (steal == true) {
        cout << " taking ";
        square[gF(newPos)][gR(newPos)]->printColour();
        cout << "'s " << square[gF(newPos)][gR(newPos)]->getType() << endl;
      }
      else
        cout << endl;
      }

    void ChessBoard::resetBoard()  {


      for (int i = 0; i < 8; i++) {
        for (int c = 0; c < 8; c++) {
          if (square[i][c] != NULL)
            delete square[i][c]; // Imperial College?
          }
      }

      turn = 0; //White always begins
      error_code = 0;

      square[4][0] = new King("King", 0, 4, 0);
      square[4][7] = new King("King", 1, 4, 7);
      square[3][0] = new Queen("Queen", 0, 3, 0);
      square[3][7] = new Queen("Queen", 1, 3, 7);
      square[0][0] = new Rook("Rook", 0, 0, 0);
      square[7][0] = new Rook("Rook", 0, 7, 0);
      square[0][7] = new Rook("Rook", 1, 0, 7);
      square[7][7] = new Rook("Rook", 1, 7, 7);
      square[1][0] = new Knight("Knight", 0, 1, 0);
      square[6][0] = new Knight("Knight", 0, 6, 0);
      square[1][7] = new Knight("Knight", 1, 1, 7);
      square[6][7] = new Knight("Knight", 1, 6, 7);
      square[2][0] = new Bishop("Bishop", 0, 2, 0);
      square[5][0] = new Bishop("Bishop", 0, 5, 0);
      square[2][7] = new Bishop("Bishop", 1, 2, 7);
      square[5][7] = new Bishop("Bishop", 1, 5, 7);

      for (int i = 0; i<8; i++)
        square[i][1] = new Pawn("Pawn", 0, i, 1);

      for (int c = 0; c < 8 ; c++)
        square[c][6] = new Pawn("Pawn", 1, c, 6);

      for (int i = 0; i < 8 ; i++) {
        for (int c = 2;   c < 6; c++)
          square[i][c] = NULL;
        }

        winston = "E1";
        charles = "E8";

      cout << "A new chess game is started!" << endl;
    }

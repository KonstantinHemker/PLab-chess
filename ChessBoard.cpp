/*Implementation file for the chessboard*/

#include "ChessBoard.h"
#include "Figure.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Field.h"

using namespace std;

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


  //Set the positions of the Kings
  winston = "E1";
  charles = "E8";
  
    cout << "A new chess game is started" << endl;
}

ChessBoard::~ChessBoard() {

  for (int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
      if (square[i][c] != NULL)
        delete square[i][c]; // Imperial College?
    }
  }
}

    FigurePtr ChessBoard::getPosition(string pos) {
      //
    }


    void ChessBoard::submitMove(string currPos, string newPos) {
      
      //Check move
      checkMove(currPos, newPos);
      if (error_code != 0) {
         return;
      }
       if (square[gF(newPos)][gR(newPos)] != NULL)
	byeFigure();
      


      //Make move
    	square[gF(newPos)][gR(newPos)] = square[gF(currPos)][gR(currPos)];
	    square[gF(currPos)][gR(currPos)] = NULL;
      square[gF(newPos)][gR(newPos)]->updatePosition(square, newPos);

      checkCheck();
      
      printMoveMessage(currPos, newPos);

      switchTurn();
    }


bool ChessBoard::checkCheck() {
  for(int i = 0; i < 8; i++) {
    for (int c = 0; c < 8; c++) {
      if (square[i][c] != NULL) {
	square[i][c]->checkCheck(square, i, c, turn, winston, charles);
      
      	//Function checks the valid moves only of the opponent figures
	    
	  }
	}
      }
  return false;
}
      


void ChessBoard::byeFigure()  {

 //overload exertion operator
 
}

    void ChessBoard::checkMove(string currPos, string newPos) {
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


      //Check NO_PIECE
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

    square[gF(currPos)][gR(currPos)]-> validStep(square, currPos, newPos, error_code);

  }

  bool ChessBoard::checkInput(string input) {
    int number = gR(input);
    int letter = gF(input);

    if ((number < 0) || (number > 7) || (letter < 0) || (letter > 7))
      return false;

    return true;
  }

    bool ChessBoard::getTurn() {
      return turn;
    }

    void ChessBoard::switchTurn() {
      if (turn == 0)
        turn = 1;
      else
        turn = 0;
    }

    void ChessBoard::printMoveMessage(string currPos, string newPos)  {
      square[gF(newPos)][gR(newPos)]-> printColour();
      cout << "'s ";
      cout << square[gF(newPos)][gR(newPos)]-> getType();
      cout << " moves from " << currPos << " to " << newPos << endl;
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
        for (int c = 2; c < 6; c++)
          square[i][c] = NULL;
        }

      winston = "E1";
      charles = "E8";
      
      cout << "A new chess game is started" << endl;
    }

    void ChessBoard::printBoard() {
      return;
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

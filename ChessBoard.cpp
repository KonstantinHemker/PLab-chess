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

  for (int i = 0; i<8; i++)
    square[i][1] = new Pawn("Pawn", 0, i, 1);

  for (int c = 0; c < 8 ; c++)
    square[c][6] = new Pawn("Pawn", 1, c, 6);

  for (int i = 0; i < 8 ; i++) {
    for (int c = 2; c < 6; c++)
      square[i][c] = NULL;
    }

    cout << "A new chess game is started" << endl;
}

    FigurePtr ChessBoard::getPosition(string pos) {
      //

    }


    void ChessBoard::submitMove(string currPos, string newPos) {
      //Check move
      checkMove(currPos, newPos);
      if (error_code != 0) {
	       error_code = 0;
         return;
      }
      //Make move
    	square[gR(newPos)][gF(newPos)] = square[gR(currPos)][gF(currPos)];
	    square[gR(currPos)][gF(currPos)] = NULL;
      square[gR(newPos)][gF(newPos)]->updatePosition(newPos);

      printMoveMessage(currPos, newPos);

      switchTurn();
    }


    void ChessBoard::checkMove(string currPos, string newPos) {

      //Check WRONG_MOVE
      if (square[gR(currPos)][gF(currPos)] == NULL) {
        error_code = NO_PIECE;
        cerr << "There is no piece at position " << currPos << "!" << endl;
        return;
      }

      //Check NO_PIECE
      if (square[gR(currPos)][gF(currPos)]-> getColour() != turn) {
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

    /*Check Figure specifics*/

    //Movement
    if (square[gR(currPos)][gF(currPos)]->validMove(newPos, currPos) == false) {
      error_code = INVALID_MOVE;
      cerr << "Invalid move of " << square[gR(currPos)][gF(currPos)]->getType();
      cerr << " from " << currPos << " to " << newPos << endl;
    }
    //Route

    //Destination
    if (square[gR(currPos)][gF(currPos)]->validDestination(square, newPos, currPos) == false)  {
      square[gR(currPos)][gF(currPos)]->DestinationError(square, newPos, currPos);
      error_code = INVALID_DESTINATION;
      return;
    }

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
      square[gR(newPos)][gF(newPos)]-> printColour();
      cout << "'s ";
      cout << square[gR(newPos)][gF(newPos)]-> getType();
      cout << " moves from " << currPos << " to " << newPos << endl;
    }

    void ChessBoard::resetBoard()  {
      return;
    }

    void ChessBoard::printBoard() {
      return;
    }


    int gR (string str) {
      char target;
      target = str[0];
      return target-65;
    }

    int gF (string str) {
      char temp = str[1];
      int x = temp - '0';
      return x-1;
    }

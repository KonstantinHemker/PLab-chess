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

  square[4][0] = new King("King", 'W', 4, 0);
  square[4][7] = new King("King", 'B', 4, 7);
  square[3][0] = new Queen("Queen", 'W', 3, 0);
  square[3][7] = new Queen("Queen", 'B', 3, 7);
  square[0][0] = new Rook("Rook", 'W', 0, 0);
  square[7][0] = new Rook("Rook", 'W', 7, 0);
  square[0][7] = new Rook("Rook", 'B', 0, 7);
  square[7][7] = new Rook("Rook", 'B', 7, 7);
  square[1][0] = new Knight("Knight", 'W', 1, 0);
  square[6][0] = new Knight("Knight", 'W', 6, 0);
  square[1][7] = new Knight("Knight", 'B', 1, 7);
  square[6][7] = new Knight("Knight", 'B', 6, 7);
  square[2][0] = new Bishop("Bishop", 'W', 2, 0);
  square[5][0] = new Bishop("Bishop", 'W', 5, 0);
  square[2][7] = new Bishop("Bishop", 'B', 2, 7);
  square[5][7] = new Bishop("Bishop", 'B', 5, 7);

  for (int i = 0; i<8; i++)
    square[i][1] = new Pawn("Pawn", 'W', i, 1);

  for (int c = 0; c < 8 ; c++)
    square[c][6] = new Pawn("Pawn", 'B', c, 6);

  for (int i = 0; i < 8 ; i++) {
    for (int c = 2; c < 7; c++)
      square[i][c] = NULL;
    }
  }

    FigurePtr ChessBoard::getPosition(string pos) {
      cout << pos[0] << endl;

    }

    int getRank (string str) {
      char target;
      target = str[0];
      return target-65;
    }

    int getFile (string str) {
      char temp = str[1];
      int x = temp - '0';
      return x;
      /*
      char temp = str[1];
      int temp2;
      //const char* temp2 = str[1];
      temp2 = atoi(temp);
      temp2 -= 1;
      return temp2;*/
    }
    void ChessBoard::submitMove(string currPos, string nextPos) {
      //Check move
      cout << getRank(currPos) << " " << getFile(currPos) << endl;
      //Make move
      //square[getRank(nextPos)][getFile(nextPos)] = square[getRank(currPos)][getFile(currPos)];
      //square[getRank(currPos)][getFile(currPos)] = NULL;
    }


    void ChessBoard::resetBoard()  {
      return;
    }

    void ChessBoard::printBoard() {
      return;
    }




  /*
  bKing = &king[1];
  wQueen = &queen[0];
  bQueen = &queen[1];
  wRook[0] = &rook[0];
  wRook[1] = &rook[1];
  bRook[0] = &rook[2];
  bRook[1] = &rook[3];
  wBishop[0] = &bishop[0];
  wBishop[1] = &bishop[1];
  bBishop[0] = &bishop[2];
  bBishop[1] = &bishop[3];
  wKnight[0] = &knight[0];
  wKnight[1] = &knight[1];
  bKnight[0] = &knight[2];
  bKnight[1] = &knight[3];

//white pawns
  for (int i = 0; i < 8; i++)
    wPawn[i] = &pawn[i];

  for (int i = 8; i < 16; i++)
    bPawn[i-8] = &pawn[i];
  //Create the figures and initialise them on the board


  for (int n = 0; n < 8; n++)  {
    for (int c = 0; c < 8; c++)
    square[n][c] = &field[n][c];
  }
*/
  //setFigures();


/*
void ChessBoard::setFigures()  {
  //Create white team
   wKing->setPosition('E', 1, wKing, square, mapping);
   wQueen->setPosition('D',1, wQueen, square, mapping);
   wRook[0]->setPosition('A', 1, wRook[0], square, mapping);
   wRook[1]->setPosition('H', 1, wRook[1], square, mapping);
   wBishop[0]->setPosition('C', 1, wBishop[0], square, mapping);
   wBishop[1]->setPosition('F', 1, wBishop[1], square, mapping);
   wKnight[0]->setPosition('B', 1, wKnight[0], square, mapping);
   wKnight[1]->setPosition('G', 1, wKnight[1], square, mapping);

  for (int i = 65; i < 73; i++) {
    wPawn[i-65]->setPosition(i, 2, wPawn[i-65], square, mapping); //where 65 and 73 refer to the ASCII values
    }


  //Create black team
  //Note that the positions are indexed to 1
  bKing->setPosition('E', 8, bKing, square, mapping);
  bQueen->setPosition('D',8, bQueen, square, mapping);
  bRook[0]->setPosition('A', 8, bRook[0], square, mapping);
  bRook[1]->setPosition('H', 8, bRook[1], square, mapping);
  bBishop[0]->setPosition('C',8, bBishop[0], square, mapping);
  bBishop[1]->setPosition('F', 8, bBishop[1], square, mapping);
  bKnight[0]->setPosition('B',8, bKnight[0], square, mapping);
  bKnight[1]->setPosition('G',8, bKnight[1], square, mapping);

  for (int i = 65; i < 73; i++) {
    bPawn[i-65]->setPosition(i, 7, bPawn[i-65], square, mapping);
}
}
*/



//void ChessBoard::printPosition(string pos) {

//}

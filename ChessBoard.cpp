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
  King king[2];
  Queen queen[2];
  Rook rook[4];
  Bishop bishop[4];
  Knight knight[4];
  Pawn pawn[16];
  //Create the chessboard in a 2D array of pointers to objects
//initialise pointers
/*
FigurePtr wKing = new King;
FigurePtr bKing = new King;
FigurePtr wQueen = new Queen;
FigurePtr bQueen = new Queen;
FigurePtr wRook[0] = new Rook;
FigurePtr wRook[1] = new Rook;
FigurePtr bRook[0] = new Rook;
FigurePtr bRook[1] = new Rook;
FigurePtr wBishop[0] = new Bishop;
FigurePtr wBishop[1] = new Bishop;
FigurePtr bBishop[0] = new Bishop;
FigurePtr bBishop[1] = new Bishop;
FigurePtr wKnight[0] = new Knight;
FigurePtr wKnight[1] = new Knight;
FigurePtr bKnight[0] = new Knight;
FigurePtr bKnight[1] = new Knight;

for (int i = 0; i<8; i++)
  FigurePtr wPawn[i] = new Pawn;

for (int c = 0; c<8; c++)
  FigurePtr bPawn[i] = new Pawn;
*/

  wKing = &king[0];
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

  Field field[8][8];

  for (int n = 0; n < 8; n++)  {
    for (int c = 0; c < 8; c++)
    square[n][c] = &field[n][c];
  }

  set_figures();

}

void ChessBoard::set_figures()  {
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


FigurePtr ChessBoard::getPosition(char pos[]) {
  cout << pos[0] << endl;
  cout << pos[1] << endl;
  cout << mapping[square[0][1]] << endl;
  //return mapping[square[getRank(pos[0])][getFile(pos[1])]];
}

int getRank (char character) {
  return character-65;
}

int getFile (char number) {
  return number-1;
}


//void ChessBoard::printPosition(string pos) {

//}



void ChessBoard::submitMove(string currentPosition, string nextPosition) {
  return;
}

void ChessBoard::resetBoard()  {
  return;
}

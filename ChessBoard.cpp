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
  set_figures();

  Field field[8][8];

  for (int n = 0; n < 8; n++)  {
    for (int c = 0; c < 8; c++)
    square[n][c] = &field[n][c];
  }

}

void ChessBoard::set_figures()  {
  //Create white team
   wKing->set_position('E', 1, wKing, square, mapping);
   wQueen->set_position('D',1, wQueen, square, mapping);
   wRook[0]->set_position('A', 1, wRook[0], square, mapping);
   wRook[1]->set_position('H', 1, wRook[1], square, mapping);
   wBishop[0]->set_position('C', 1, wBishop[0], square, mapping);
   wBishop[1]->set_position('F', 1, wBishop[1], square, mapping);
   wKnight[0]->set_position('B', 1, wKnight[0], square, mapping);
   wKnight[1]->set_position('G', 1, wKnight[1], square, mapping);

  for (int i = 65; i < 73; i++) {
    wPawn[i-65]->set_position(i, 2, wPawn[i-65], square, mapping); //where 65 and 73 refer to the ASCII values
    }

  //Create black team
  bKing->set_position('E', 8, bKing, square, mapping);
  bQueen->set_position('D',8, bQueen, square, mapping);
  bRook[0]->set_position('A', 8, bRook[0], square, mapping);
  bRook[1]->set_position('H', 8, bRook[1], square, mapping);
  bBishop[0]->set_position('C',8, bBishop[0], square, mapping);
  bBishop[1]->set_position('F', 8, bBishop[1], square, mapping);
  bKnight[0]->set_position('B',8, bKnight[0], square, mapping);
  bKnight[1]->set_position('G',8, bKnight[1], square, mapping);

  for (int i = 65; i < 73; i++) {
    bPawn[i-65]->set_position(i, 7, bPawn[i-65], square, mapping);
}
}
/*
void ChessBoard::set_map()  {
  mapping[wKing] = square[E][1];
  mapping[wQueen] = square[D][1];
  mapping[wRook[0]] = square[A][1];
  mapping[wRook[1]] = square[A][1];
  mapping[wBishop[0]] = square[C][1];
  mapping[wBishop[1]] = square[F][1];
  mapping[wKnight[0]] = square[B][1];
  mapping[wKnight[1]] = square[G][1];
  for (int i = 65; i<73; i++)
    mapping[bPawn[i-65]] = square[i][2];

  mapping[bKing] = square[E][1];
  mapping[bQueen] = square[D][1];
  mapping[bRook[0]] = square[A][1];
  mapping[bRook[1]] = square[A][1];
  mapping[bBishop[0]] = square[C][1];
  mapping[bBishop[1]] = square[F][1];
  mapping[bKnight[0]] = square[B][1];
  mapping[bKnight[1]] = square[G][1];
  for (int i = 65; i<73; i++)
    mapping[bPawn[i-65]] = square[i][2];


}
*/
void ChessBoard::submitMove(string currentPosition, string nextPosition) {
  return;
}

void ChessBoard::resetBoard()  {
  return;
}

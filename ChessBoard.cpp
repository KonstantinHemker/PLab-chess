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

ChessBoard::ChessBoard () {
  //Create the chessboard in a 2D array of pointers to objects

  //Create the figures and initialise them on the board
  set_figures();

}

void ChessBoard::set_figures()  {
  //Create white team
  King wKing('E', 1);
  Queen wQueen('D',1);
  Rook wRook1('A', 1);
  Rook wRook2 ('H', 1);
  Bishop wBishop1('C', 1);
  Bishop wBishop2('F', 1);
  //Knight wKnight1('B', 1);
  //Knight wKnight2 ('G', 1);
/*
  for (int i = 65; i == 73; i++) {
    Pawn wPawn_i('i', 2); //where 65 and 73 refer to the ASCII values
    }
*/
  //Create black team
  King bKing('E', 8);
  Queen bQueen('D',8);
  Rook bRook1('A', 8);
  Rook bRook2('H', 8);
  Bishop bBishop1('C',8);
  Bishop bBishop2('F', 8);
  //Knight bKnight1('B',8);
  //Knight bKnight2('G',8);
/*
  for (int i = 65; i == 73; i++) {
    Pawn bPawn_i('i', 7);
}
*/
}

void ChessBoard::submitMove(string currentPosition, string nextPosition) {
  return;
}

void ChessBoard::resetBoard()  {
  return;
}

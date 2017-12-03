/*Header file for the chessboard*/
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>

using namespace std;


//Forward declaration of classes:
class King;
class Rook;
class Pawn;
class Bishop;
class Queen;
class Knight;
class Figure;
class Field;


class ChessBoard {
protected:
  King *wKing, *bKing;
  Queen *wQueen, *bQueen;
  Rook *wRook[2], *bRook[2];
  Bishop *wBishop[2], *bBishop[2];
  Knight *wKnight[2], *bKnight[2];
  Pawn *wPawn[8], *bPawn[8];

  Field *square[8][8]; //two-dimensional array of pointers to the chess board

public:
  ChessBoard ();
  void submitMove(string currentPosition, string nextPosition);
  void resetBoard();
  //virtual void valid_move ();
  void set_figures ();
  //friend ostream& operator << (ostream)
};


#endif

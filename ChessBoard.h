/*Header file for the chessboard*/
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<map>

using namespace std;

class King;
class Rook;
class Pawn;
class Bishop;
class Queen;
class Knight;
class Figure;
class Field;

typedef Figure* FigurePtr;
typedef Field* FieldPtr;

class ChessBoard {
protected:
  King *wKing, *bKing;
  Queen *wQueen, *bQueen;
  Rook *wRook[2], *bRook[2];
  Bishop *wBishop[2], *bBishop[2];
  Knight *wKnight[2], *bKnight[2];
  Pawn *wPawn[8], *bPawn[8];
  FieldPtr square[8][8]; //two-dimensional array of pointers to the chess board
  map<FigurePtr,FieldPtr> mapping;
  //map<char, int> mapping;

public:
  ChessBoard ();
  void submitMove(string currentPosition, string nextPosition);
  void resetBoard();
  //virtual void valid_move ();
  void set_figures ();
  //friend ostream& operator << (ostream)
};


#endif

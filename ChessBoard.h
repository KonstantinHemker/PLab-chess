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
enum Ranks {A,B,C,D,E,F,G,H};

class ChessBoard {
protected:
/*
  Figure *wKing, *bKing;
  Figure *wQueen, *bQueen;
  Figure *wRook[2], *bRook[2];
  Figure *wBishop[2], *bBishop[2];
  Figure *wKnight[2], *bKnight[2];
  Figure *wPawn[8], *bPawn[8];*/
  FieldPtr square[8][8]; //two-dimensional array of pointers to the chess board
  map<Field, Figure> mapping;


public:
  ChessBoard ();
  FigurePtr getPosition(char* pos);
  void submitMove(string currentPosition, string nextPosition);
  void resetBoard();
  //virtual bool valid_move ();
  void set_figures ();
  int getRank (char character);
  int getFile (char number);
  //friend ostream& operator << (ostream)
};


#endif

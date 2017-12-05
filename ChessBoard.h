/*Header file for the chessboard*/
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
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
  FigurePtr square[8][8]; //two-dimensional array of pointers to the chess board

public:
  ChessBoard ();
  FigurePtr getPosition(string pos);
  void submitMove(string currPos, string nextPos);
  void resetBoard();
  //virtual bool valid_move ();
  void setFigures ();
  int getRank(string str);
  int getFile(string str);
  void printBoard();
  //friend ostream& operator << (ostream)
};


#endif

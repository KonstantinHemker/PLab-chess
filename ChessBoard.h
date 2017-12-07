/*Header file for the chessboard*/
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<map>
#include<cmath>

//Error Codes
#define WRONG_TURN -1;
#define NO_PIECE -2;
#define INVALID_MOVE -3;
#define INVALID_ROUTE -4;
#define INVALID_DESTINATION -5;

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

//General Helper functions
int gR(string str); //abbrev. for getRank
int gF(string str); //abbrev. for getFile

class ChessBoard {
friend class Figure;
protected:
  FigurePtr square[8][8]; //two-dimensional array of pointers to the chess board
  bool turn; //0 --> White's turn || 1 --> black's turn
  int error_code;
public:
  ChessBoard ();
  virtual ~ChessBoard();
  FigurePtr getPosition(string pos);
  void submitMove(string currPos, string nextPos);
  void resetBoard();
  //virtual bool valid_move ();
  void setFigures ();
  void printBoard();
  void checkMove(string currPos, string nextPos);
  void switchTurn();
  void printMoveMessage(string currPos, string nextPos);
  bool getTurn();
  //friend ostream& operator << (ostream)
};


#endif

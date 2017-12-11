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
#define OUT_OF_BOUNDS -2;
#define NO_PIECE -3;
#define INVALID_MOVE -4;
#define INVALID_ROUTE -5;
#define INVALID_DESTINATION -6;


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
  string winston, charles; //Winston is the position of the white king, charles that of the black king
public:
  ChessBoard ();
  virtual ~ChessBoard();
  FigurePtr getPosition(string pos);
  void submitMove(string currPos, string nextPos);
  void resetBoard();
  //virtual bool valid_move ();
  void updateMoves();
  void setFigures ();
  void printBoard();
  string createNewPos(int i, int c);
  string getPosition(int i, int c);
  void checkMove(string currPos, string nextPos);
  bool checkInput (string input);
  void switchTurn();
  void printMoveMessage(string currPos, string nextPos);
  bool getTurn();
  //friend ostream& operator << (ostream)
};


#endif

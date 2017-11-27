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

class ChessBoard {
protected:
  King* wking1;

  
  /*
Create pointers to classes
  King wKing, bKing;
  Queen wQueen, bQueen;
  Rook wRook1, wRook2, bRook1, bRook4;
  Bishop wBishop1, wBishop2, bBishop1, bBishop2;
  Knight wKnight1, wKnigth2, bKnight1, bKnight2;
*/

public:
  ChessBoard ();
  void submitMove(string currentPosition, string nextPosition);
  void resetBoard();
  //virtual void valid_move ();
  void set_figures ();
  //friend ostream& operator << (ostream)
};


#endif

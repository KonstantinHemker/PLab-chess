/*Header file for the chessboard*/
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

//Forward declaration of classes:
class King;
class Rook;
class Pawn;
class Bishop;
class Queen;
class Knight;

class ChessBoard {
protected:
/*
  King wKing, bKing;
  Queen wQueen, bQueen;
  Rook wRook1, wRook2, bRook1, bRook4;
  Bishop wBishop1, wBishop2, bBishop1, bBishop2;
  Knight wKnight1, wKnigth2, bKnight1, bKnight2;
*/

public:
  ChessBoard ();
  //void submitMove(string currentPosition, string nextPosition);
  void resetBoard();
  //virtual void valid_move ();
  void set_figures ();


  //friend ostream& operator << (ostrea)
};


#endif

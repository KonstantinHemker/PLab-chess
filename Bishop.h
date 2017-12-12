//Header file for bishop
#ifndef BISHOP_H
#define BISHOP_H

//#include "ChessBoard.h"
#include "Figure.h"

class Bishop : public Figure {
 private:
   //char symbol = "♔";
 public:
   Bishop(string type, bool c, int a, int b);
   bool validMove (FigurePtr square[][8], string currPos, string newPos) override;
   static bool diagonalMove(FigurePtr square[][8], string currPos, string newPos, int rank, int file);
   bool validRoute(FigurePtr square[][8], string currPos, string newPos) override;
   static bool diagonalRoute(FigurePtr square[][8], string currPos, string newPos, int rank, int file);
};

#endif

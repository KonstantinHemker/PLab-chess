//Header file for bishop
#ifndef BISHOP_H
#define BISHOP_H

//#include "ChessBoard.h"
#include "Figure.h"

class Bishop : public Figure {
 private:

 public:
   Bishop(string type, bool c, int a, int b);
   bool validMove (FigurePtr square[][8], string currPos, string newPos) override;
   bool validRoute(FigurePtr square[][8], string currPos, string newPos) override;
};

#endif

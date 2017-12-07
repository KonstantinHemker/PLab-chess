//Header file for knight
#ifndef KNIGHT_H
#define KNIGHT_H

//#include "ChessBoard.h"
#include "Figure.h"

class Knight : public Figure  {
 private:
 public:
  Knight(string type, bool c, int a, int b);
  bool validMove (FigurePtr square[][8], string currPos, string newPos) override;
};

#endif

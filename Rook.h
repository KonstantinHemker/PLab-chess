#ifndef ROOK_H
#define ROOK_H

//#include "ChessBoard.h"
#include "Figure.h"

class Rook : public Figure  {
 private:
 public:
  Rook(string type, bool c, int a, int b);
  bool validMove(FigurePtr square[][8], string currPos, string newPos) override;
  bool validRoute(FigurePtr square[][8], string currPos, string newPos) override;
};

#endif

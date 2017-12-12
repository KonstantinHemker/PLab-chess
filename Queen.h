//Header File for queen
#ifndef QUEEN_H
#define QUEEN_H

//#include "ChessBoard.h"
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"

class Queen : public Figure{
 private:
//converted ASCII characters
 public:
  Queen(string type, bool c, int a, int b);
  bool validMove (FigurePtr square[][8], string currPos, string newPos) override;
  bool validRoute(FigurePtr square[][8], string currPos, string newPos) override;
};
#endif

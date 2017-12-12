#ifndef ROOK_H
#define ROOK_H

//#include "ChessBoard.h"
#include "Figure.h"

class Rook : public Figure  {
 private:
 public:
  Rook(string type, bool c, int a, int b);
  bool validMove(FigurePtr square[][8], string currPos, string newPos) override;
  static bool straightMove(FigurePtr square[][8], string currPos, string newPos, int rank, int file);
  bool validRoute(FigurePtr square[][8], string currPos, string newPos) override;
  static bool straightRoute(FigurePtr square[][8], string currPos, string newPos, int rank, int file);
};

#endif

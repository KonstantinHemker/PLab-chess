//Header File for queen
#ifndef QUEEN_H
#define QUEEN_H

//#include "ChessBoard.h"
#include "Figure.h"

class Queen : public Figure {
 private:
  int rank;
  int file; //converted ASCII characters
 public:
  Queen(char a, int b);
};
#endif

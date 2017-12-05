//Header file for pawn
#ifndef PAWN_H
#define PAWN_H

//#include "ChessBoard.h"
#include "Figure.h"

class Pawn : public Figure  {
 private:
 public:
  Pawn (string type, char c, int a, int b);
};

#endif

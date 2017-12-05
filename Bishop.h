//Header file for bishop
#ifndef BISHOP_H
#define BISHOP_H

//#include "ChessBoard.h"
#include "Figure.h"

class Bishop : public Figure {
 private:

 public:
   Bishop(string type, bool c, int a, int b);
   bool validMove (string currPos, string newPos) override;
};

#endif

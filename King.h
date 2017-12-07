#ifndef KING_H
#define KING_H

#include "Figure.h"


class King : public Figure  {
 private:

 public:
  King(string type, bool c, int a, int b);
  bool validMove  (FigurePtr square[][8], string currPos, string newPos) override;
};

#endif

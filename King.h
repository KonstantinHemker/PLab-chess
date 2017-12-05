#ifndef KING_H
#define KING_H

#include "Figure.h"


class King : public Figure  {
 private:

 public:
  King(string type, bool c, int a, int b);
  bool validMove  (string currPos, string newPos) override;
};

#endif

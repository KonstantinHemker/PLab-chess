#ifndef KING_H
#define KING_H

#include "ChessBoard.h"


class King  {
 private:
  char rank;
  int file; //converted ASCII characters
 public:
  King(char input_rank, int input_file_);
};

#endif

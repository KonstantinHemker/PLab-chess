#ifndef ROOK_H
#define ROOK_H

#include "ChessBoard.h"


class Rook  {
 private:
  int rank;
  int file; //converted ASCII characters
 public:
  Rook(char input_rank, int input_file_);
};

#endif

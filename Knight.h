//Header file for knight
#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessBoard.h"


class Knight  {
 private:
  char rank;
  int file; //converted ASCII characters
 public:
  Knight(char input_rank, int input_file_);
};

#endif

//Header File for queen
#ifndef QUEEN_H
#define QUEEN_H

#include "ChessBoard.h"


class Queen {
 private:
  int rank;
  int file; //converted ASCII characters
 public:
  Queen(char input_rank, int input_file_);
};
#endif

//Header file for bishop
#ifndef BISHOP_H
#define BISHOP_H
#include "ChessBoard.h"

class Bishop{
 private:
  char rank;
  int file; //converted ASCII characters
 public:
  Bishop(char input_rank, int input_file_);
};

#endif

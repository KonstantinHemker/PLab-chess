//Header file for pawn
#ifndef PAWN_H
#define PAWN_H

#include "ChessBoard.h"


class Pawn  {
 private:
  int rank;
  int file; //converted ASCII characters
 public:
  Pawn(char input_rank, int input_file_);
};

#endif

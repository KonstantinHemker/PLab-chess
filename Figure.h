#ifndef KNIHGT_H
#define KNIGHT_H

#include "ChessBoard.h"
//Abstract parent class for the chess figures

class Figure  {
protected:
  char rank;
  int file;
  char colour;
public:
  Figure(char input_rank, int input_file);
};


#endif

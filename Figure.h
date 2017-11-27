#ifndef FIGURE_H
#define FIGURE_H

//#include "ChessBoard.h"
//Abstract parent class for the chess figures

class Figure  {
protected:
  char rank;
  int file;
  char colour;
public:
  Figure(char input_rank, int input_file);
  //virtual void valid_move();
};


#endif

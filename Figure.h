#ifndef FIGURE_H
#define FIGURE_H

#include "ChessBoard.h"
//Abstract parent class for the chess figures

class Figure  {
protected:
  char rank;
  int file;
  char colour;
public:
  //Figure (char input_rank, int input_file);
  void set_position(char input_rank, int input_file, FigurePtr figure,
  FieldPtr field[][8], std::map<FieldPtr, FigurePtr> &mapping);
  string get_position();
  //virtual void valid_move();
};


#endif

#ifndef FIGURE_H
#define FIGURE_H

#include "ChessBoard.h"
//Abstract parent class for the chess figures

class Figure  {
protected:
  string type;
  char rank; //horizontal position
  int file; //vertical position
  char colour;
public:
  Figure (string input_type, char input_colour, int input_rank, int input_file);
  string getType();
  void setPosition(char input_rank, int input_file, FigurePtr figure,
  FieldPtr field[][8], std::map<FieldPtr, FigurePtr> &mapping);
  string getPosition();
  //virtual void valid_move();
};


#endif

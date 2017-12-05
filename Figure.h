#ifndef FIGURE_H
#define FIGURE_H

#include "ChessBoard.h"
//Abstract parent class for the chess figures

class Figure  {
protected:
  string type;
  char rank; //horizontal position
  int file; //vertical position
  bool colour; //0 --> white || 1--> black
public:
  Figure (string input_type, bool input_colour, int input_rank, int input_file);
  string getType();
  void setPosition(char input_rank, int input_file, FigurePtr figure,
  FieldPtr field[][8], std::map<FieldPtr, FigurePtr> &mapping);
  string getPosition();
  bool getColour();
  void printColour();
  //virtual void valid_move();
};


#endif

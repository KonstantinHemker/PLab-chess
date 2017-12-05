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
  void updatePosition(string newPos);
  bool validDestination(FigurePtr square[][8], string newPos, string currPos);
  void DestinationError (FigurePtr square[][8], string newPos, string currPos);
  //virtual bool validRoute();
  virtual bool validMove(string currPos, string newPos) = 0;
  string getType();
  string getPosition();
  bool getColour();
  void printColour();
  //virtual void valid_move();
};


#endif

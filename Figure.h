#ifndef FIGURE_H
#define FIGURE_H

#include "ChessBoard.h"
//Abstract parent class for the chess figures

class Figure  {
protected:
  string type;
  int rank; //horizontal position
  int file; //vertical position
  bool colour; //0 --> white || 1--> black
public:
  Figure (string input_type, bool input_colour, int input_rank, int input_file);
  void updatePosition(string newPos);
  //Function that checks whether the destination is either a
  bool validDestination(FigurePtr square[][8], string newPos, string currPos);
  void DestinationError (FigurePtr square[][8], string newPos, string currPos);

  //Functiont that checks for three conditions. 1) Is the destination valid?
  //2) Is the move legal for the figure? 3) Is the route to the destination valid?
  //(all fields on the way must be vacant, except for the knight)
  //Note that for the knight, the pawn and the king, the second check is not necessary,
  //because they don't pass any other fields before their destination (e.g. only can)
  //move one step
  void validStep(FigurePtr square[][8], string newPos, string currPos, int error_code);

  virtual bool validRoute(FigurePtr square[][8], string currPos, string newPos);
  virtual bool validMove(FigurePtr square[][8], string currPos, string newPos) = 0;
  //virtual bool validRoute(FigurePtr square[][8], string currPos, string newPos);
  string getType();
  string getPosition();
  bool getColour();
  void printColour();
};


#endif

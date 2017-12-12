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
  string legalMove[50];
public:
  Figure (string input_type, bool input_colour, int input_rank, int input_file);
  void updatePosition(FigurePtr square[][8], string newPos, bool turn);
  void getValidMoves(FigurePtr square[][8], bool turn);
  string createNewPos(int i, int c);
  //Function that checks whether the destination is either a
  bool validDestination(FigurePtr square[][8], string newPos, string currPos, bool turn, bool &steal);
  bool validDestPositions(FigurePtr square[][8], string currPos, string newPos, bool turn, bool &steal);
  void DestinationError (FigurePtr square[][8], string newPos, string currPos);

  //Functiont that checks for three conditions. 1) Is the destination valid?
  //2) Is the move legal for the figure? 3) Is the route to the destination valid?
  //(all fields on the way must be vacant, except for the knight)
  //Note that for the knight, the pawn and the king, the second check is not necessary,
  //because they don't pass any other fields before their destination (e.g. only can)
  //move one step
  bool validStep(FigurePtr square[][8], string newPos, string currPos, int &error_code, bool turn, bool &steal);
  void writeMove(int count, string newPos);
  virtual bool validRoute(FigurePtr square[][8], string currPos, string newPos);
  virtual bool validMove(FigurePtr square[][8], string currPos, string newPos) = 0;
  //virtual bool validRoute(FigurePtr square[][8], string currPos, string newPos);
  string getType();
  string getPosition();
  string getValidMove(int n);
  bool getColour();
  void printColour();
  int getFile();
  int getRank();
  bool checkCheck(FigurePtr square[][8], int i, int c, bool turn, string winston, string charles);
  int getArraySize();
};


#endif

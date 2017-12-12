#ifndef FIGURE_H
#define FIGURE_H

#include "ChessBoard.h"
//Abstract parent class for the chess figures, whick pools a number of common
//attributes and operations that apply to all chess figures/pieces

class Figure  {
protected:
  string type;
  int rank; //horizontal position
  int file; //vertical position
  bool colour; //0 --> white || 1--> black
  string legalMove[30];
public:
  //Constructor for each figure. This sets the rank and file value as of the starting
  //Position of the board and defines their colour and their type
  Figure (string input_type, bool input_colour, int input_rank, int input_file);

  //Function that checks for three conditions. 1) Is the destination valid?
  //2) Is the move legal for the figure? 3) Is the route to the destination valid?
  //(all fields on the way must be vacant, except for the knight)
  //Note that for the knight, the pawn and the king, the second check is not necessary,
  //because they don't pass any other fields before their destination (e.g. only can)
  //move one step
  bool validStep(FigurePtr square[][8], string newPos, string currPos, int &error_code, bool turn, bool &steal);


  //Virtual function for condition(2) of the above. The route only need to be
  //checked for the Pawn (on its first move), the queen, the rook and the bishop
  //Hence, this will evaluate as "true" for all other types of chess pieces
  virtual bool validRoute(FigurePtr square[][8], string currPos, string newPos);

  //Pure virtual function that specifies the legal/valid moves for each chess piece
  //As these move are very different for the majority of chess pieces, this does
  //not carry a default value and is thus a pure virtual member
  virtual bool validMove(FigurePtr square[][8], string currPos, string newPos) = 0;

  //Precondition: Is given the current position, position of the move, the current
  //state of the board and other necessary input
  //Postcondition: Updates the file and rank attributes after the move and also
  //adjusts the value of the King position tracker from the ChessBoard if necessary
  void updatePosition(FigurePtr square[][8], string currPos, string newPos, bool turn, string &winston, string &charles);

  //Precondition: Is given the current state of the chessboard
  //Postcondition: Initialises the array of potential moves that every figure can
  //make given the current state
  void getValidMoves(FigurePtr square[][8], bool turn);


  //Precondition: Is given the current state of the board and the position of
  //the two Kings as a string
  //Postcondition: Checks whether the current position of the King of that coulour
  //that did not move is within the set of possible moves of the colour that moved
  //If this is the case, the function will return "true", i.e. that the other colour
  //is in check
  bool checkCheck(FigurePtr square[][8], int i, int c, bool turn, string winston, string charles);

  //Precondition: Is given the current state of the board and the details of the move
  //Postcondition: Checks whether the destination of the move, i.e. position "newPos"
  //is valid. That is, the function will return "true" is the destination is either
  //an opponent chess piece or an empty field
  bool validDestination(FigurePtr square[][8], string newPos, string currPos, bool turn, bool &steal);

  //Postconditon: Outputs a text string containing error information if the
  //destination entered is invalid
  void DestinationError (FigurePtr square[][8], string newPos, string currPos);

  //Precondition: Is called when a valid move of a figure has been detected
  //Postcondition: Writes n-th (count) element of the array of valid moves for
  //each figure
  void writeMove(int count, string newPos);

  //Postcondition: Returns the type of a figure as a string
  string getType();

  //Postcondition: returns the n-th element of the array of valid moves of the figure
  string getValidMove(int n);

  //Postcondition: Returns the boolean value of the private member "colour"
  bool getColour();

  //Postcondition: Prints out the colour of a figure as a string
  void printColour();

  //Postcondition: Returns the integer value of file of the figure
  int getFile();

  //Postcondition: Returns the integer value of rank of the figure
  int getRank();


};


#endif

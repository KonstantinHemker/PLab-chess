/*Header file for the chessboard*/
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<map>
#include<cmath>

//Error Codes
#define WRONG_TURN -1;
#define OUT_OF_BOUNDS -2;
#define NO_PIECE -3;
#define INVALID_MOVE -4;
#define INVALID_ROUTE -5;
#define INVALID_DESTINATION -6;


using namespace std;

class King;
class Rook;
class Pawn;
class Bishop;
class Queen;
class Knight;
class Figure;

typedef Figure* FigurePtr;
enum Ranks {A,B,C,D,E,F,G,H};

//General Helper functions
int gR(string str); //abbrev. for getRank
int gF(string str); //abbrev. for getFile
string getPosition(FigurePtr square[][8], int i, int c);

class ChessBoard {
friend class Figure;
protected:
  FigurePtr square[8][8]; //two-dimensional array of pointers to the chess board
  bool turn; //0 --> White's turn || 1 --> black's turn
  int error_code;
  string winston, charles; //Winston is the position of the white king, charles that of the black king
public:

  //Constructor of the ChessBoard which creates instantiation of every figure on
  //the heap. The board is set according to the setup of standard chess rules
  //referring to the constructors of the chess pieces
  ChessBoard ();

  //Destructor of the ChessBoard which deletes the pointers to the chess pieces
  //from the heap
  virtual ~ChessBoard();


  void submitMove(string currPos, string nextPos);

  //Deletes the figures created on the heap and recreates them in order of the
  //initial chessboard setup
  void resetBoard();

  //Precondition: Knows about the current state of the board, i.e. the position
  //of figures
  //Postcondition: Loops through every field on the board and all the possible fields
  //that it could move to. If a figure can move to a field, according to the three
  //main conditions (destination, route, move), this field is added to the list of
  //valid moves of the figure
  void updateMoves(bool &steal);

  //Precondition: Is called if check evaluates as true
  //Postcondition: Simulates the set of possible moves for every of the own team's
  //chess pieces and checks for every simulation whether the King is still in Check
  //If this simulation evaluates as true for every possible move, the King has no
  //way to escape the check and is thus in checkMate
  bool checkMate(bool steal);


  //Precondition: Function is called after each move was submitted and the other
  //player is not in check.
  //Postcondition: Checks whether any of the figures of the other player have
  //any valid moves left. The function returns true if this is the case
  bool staleMate();

  //Postconditon: Prints out error message corresponding to stalemate 
  void printStaleMate();


  //Precondition: Is called as part of the check whether a colour is in checkmate`
  //Postcondition: Operates in three steps (1) Move figure to on of its valid
  //positions and update its valid positions (2) check whether the King is still
  //in check and (3) return the figure to its initial position and reverse its
  //valid positions back to "normal"
  //The function will evaluate "true" if the King is still in Check after the
  //simulate move and "false" otherwise.
  bool simMove(string simPos, int i, int c, bool steal);


  //Postcondition: Returns a position corresponding to the 0-indexed values of
  //i and c
  string createNewPos(int i, int c);

  //Precondition: Is given the information of the current move and knows about
  //the state of the board
  //Postcondition: Checks for wrong input (out of bounds, no piece at the position)
  // and whether the wrong player takes a turn.
  //Moreover, it then checks the relevant figure for correctness of its destination,
  //the move and the route (see Figure class)
  void checkMove(string currPos, string nextPos, bool &steal);


  //Precondition: Is given an input string
  //Postcondition: Returns false of the input is out of the dimensions of the 8x8
  //chessboard. Note that the numbers in this test are 0-indexed
  bool checkInput (string input);

  //Postcondition: Switches the current turn after every move submitted
  void switchTurn();

  //Precondition: Is given the information of the current move and knows about
  //the state of the board
  //Postcondition: Prints out message which figure moved to what position and
  //whether it takes an opponent figure
  void printMoveMessage(string currPos, string nextPos, bool &steal);

  //Precondition: Is called after every move to check whether the King of the side
  //that did not make the move is in Check
  //Postcondition: The chessboard constantly keeps track of the current position
  //of the two King (Winston and Charles) and returns true if either King falls
  //within the set of valid move for any opponent figure
  bool checkCheck();

  //Precondition: Is called when checkMate evaluates as true
  //Postcondition: Prints output message containing that the relevant player is
  //in check
  void printCheckMate(bool turn);


  //Precondition: Is called when checkMate evaluates as true
  void printCheck(bool turn);


};


#endif

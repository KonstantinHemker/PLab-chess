//Header file for field class
#ifndef FIELD_H
#define FIELD_H
#include "ChessBoard.h"

class Field {
private:
  bool empty;

public:
  //Function that checks whether the square is empty
  bool is_empty();
  //Function that sets the private member "empty" to the boolean value specified
  //as the argument
  void set_empty(bool input);
};

#endif

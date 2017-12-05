//Implementation file for Bishop
#include "Bishop.h"

Bishop::Bishop(string type, bool c, int a, int b) : Figure (type, c, a, b) {
//tbc
}

bool Bishop::validMove(string currPos, string newPos) {
  int horizontal = file - gF(newPos);
  int vertical = rank - gR(newPos);
  cout << "Vertical steps: " << vertical << endl;
  cout << "Horizontal steps: " << horizontal << endl;

  if ((abs(horizontal)) == (abs(vertical)))
    return true;

  return false;
}

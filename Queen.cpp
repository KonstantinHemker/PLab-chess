//Implementation file for queen
#include "Queen.h"

Queen::Queen(string type, bool c, int a, int b) : Figure (type, c, a, b)  {
//deliberately empty
}

bool Queen::validMove(FigurePtr square[][8], string currPos, string newPos) {

    if (Rook::straightMove(square, currPos, newPos, rank, file) == true)
      return true;

    if (Bishop::diagonalMove(square,currPos, newPos, rank, file) == true)
      return true;


  return false;
}


bool Queen::validRoute(FigurePtr square[][8], string currPos, string newPos) {

  if (Rook::straightRoute(square, currPos, newPos, rank, file) == true)
    return true;

  if (Bishop::diagonalRoute(square, currPos, newPos, rank, file) == true)
    return true;


return false;


}

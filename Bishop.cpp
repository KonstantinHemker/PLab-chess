//Implementation file for Bishop
#include "Bishop.h"

Bishop::Bishop(string type, bool c, int a, int b) : Figure (type, c, a, b) {
//deliberately empty
}


bool Bishop::validMove(FigurePtr square[][8], string currPos, string newPos) {
  return diagonalMove(square, currPos, newPos, rank, file);
}


bool Bishop::diagonalMove(FigurePtr square[][8], string currPos, string newPos, int rank, int file)  {
  int horizontal = gF(newPos)-file;
  int vertical = gR(newPos)-rank;

  if (abs(horizontal) == abs(vertical))
    return true;

  return false;
}

bool Bishop::validRoute(FigurePtr square[][8], string currPos, string newPos) {
  return diagonalRoute(square, currPos, newPos, rank, file);
  }


  bool Bishop::diagonalRoute(FigurePtr square[][8], string currPos, string newPos, int rank, int file)  {
    int horizontal = gF(newPos)-file;
    int vertical = gR(newPos)-rank;
    bool result = false;

    //We want to check the route only for cases in which the Bishop moves more than 1 field
    if (abs(horizontal) == 1)
     return true;


   else {

   /*Possibility 1: Bishop moves in a "double positive" diagonal */

   if ((horizontal > 1) && (vertical > 1)) { //>1 because if we only move by one, this will be checked by the
     //destination check
     for (int i = 1; i < abs(horizontal); i++) {
       if (square[file+i][rank+i] == NULL)
         result = true;
       else
         return false;
     }
   }
     if (result == true)
       return result;

   /*Possibility 2: Bishop moves in a "positive/negative" diagonal */

     if ((horizontal > 1) && (vertical < -1)) {
     for (int i = 1; i < abs(horizontal); i++) {
       if (square[file+i][rank-i] == NULL)
         result = true;
       else
         return false;
     }
   }
     if (result == true)
       return result;

   /*Possibliity 3: Bishop moves in a "negative/positive" diagonal */

     if ((horizontal < -1) && (vertical > 1)) {
     for (int i = 1; i < abs(horizontal); i++) {
       if (square[file-i][rank+i] == NULL)
         result = true;
       else
         return false;
       }
     }
     if (result == true)
       return result;

     /*Possibliity 4: Bishop moves in a "double negative" diagonal */
       if ((horizontal < -1) && (vertical < -1)) {
       for (int i = 1; i < abs(horizontal); i++) {
         if (square[file-i][rank-i] == NULL)
           result = true;
         else
           return false;
         }
       }
   }
     return result;
}

//Implementation file for the figure class

#include "Figure.h"

Figure::Figure(char input_rank, int input_file) {
  rank = input_rank;
  file = input_file;

  if ((file == 1) || (file == 2))
    colour = 'W';
  else
    colour = 'B';
}


string Figure::get_position()  {
  string temp;
  temp = rank + file;
  return temp;
}

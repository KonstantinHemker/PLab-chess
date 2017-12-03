//Implementation file for the figure class

#include "Figure.h"


void Figure::set_position(char input_rank, int input_file, FigurePtr figure,
FieldPtr field[][8], std::map<FigurePtr, FieldPtr> &temp_map )  {
  rank = input_rank;
  file = input_file;
  temp_map[figure] = field[rank-65][file-2];

  cout << figure << " was mapped to " << field[rank-65][file-1] << endl;
  cout << rank-65 << " " << file-1 << endl;


  cout << "At position c1 is: " << temp_map.find(field[2][0])->mapping2 << endl;

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

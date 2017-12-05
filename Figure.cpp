//Implementation file for the figure class

#include "Figure.h"


void Figure::setPosition(char input_rank, int input_file, FigurePtr figure,
FieldPtr field[][8], std::map<FieldPtr, FigurePtr> &mapping )  {
  rank = input_rank;
  file = input_file;

  mapping[field[rank-65][file-1]] = figure;

  //cout << figure << " was mapped to " << field[rank-65][file-1] << endl;
  //cout << rank-65 << " " << file-1 << endl;

  //map<FigurePtr, FieldPtr> mapping2 (temp_map.begin(), temp_map.end());
  //map<FigurePtr, FieldPtr>::iterator result;

  cout << "Mapped at position " << rank << " " << file << " is " << mapping[field[rank-65][file-1]] << endl;

  //result = temp_map.find(&field[2][0]);

  //cout << "At position c1 is: " << temp_map.find(&field[2][0])->mapping2 << endl;

  if ((file == 1) || (file == 2))
    colour = 'W';
  else
    colour = 'B';
}

string Figure::getPosition()  {
  string temp;
  temp = rank + file;
  return temp;
}

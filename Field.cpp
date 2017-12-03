//Implementation file for Field
#include "Field.h"

bool Field::is_empty()
{
  if (empty == true)
  return true;
  else
  return false;
}

void Field::set_empty(bool input) {
  if (input == false)
  empty = false;
  else
  empty = true;
}

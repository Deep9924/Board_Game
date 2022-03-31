#include "CenterDouble.h"
#include <sstream>

string centerDouble (double value)
{
  return centerDouble(value, 79);
}

string centerDouble (double value, unsigned int width)
{
  stringstream convDouble;
  cout : convDouble << value;
  string stringValue = convDouble.str();

  if (stringValue.length() >= width)
    return stringValue;
  else 
  {
    int strSpace = width - stringValue.length();
    int halfStrSpace = strSpace / 2;
    char c1 = ' ';

    if (strSpace % 2 == 0)
    { 
      string tempSpace(halfStrSpace, c1);
      stringValue = tempSpace + stringValue + tempSpace;
      return stringValue;
    }
    else 
    {
      string tempSpace(halfStrSpace, c1);
      stringValue = " " + tempSpace + stringValue + tempSpace;
      return stringValue;
    }
  }
}
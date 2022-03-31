#pragma once
#include <sstream>

template <typename Data>
string center (const Data& value)
{
  return center(value, 79);
}

template <typename Data>
string center (const Data& value, unsigned int width)
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
#pragma once

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
 
template <typename Data>
string center (const Data& value);

template <typename Data>
string center (const Data& value, unsigned int width);

#include "Center.inl"
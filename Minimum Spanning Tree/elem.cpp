// CS311 Yoshii - defines node element level functions for a Node for dgraph2 use
// ------------------------------------------------------------

// ====================================
// EC related element definition
// NAME: Tyler Gerritsen
// File: elem.cpp for graph algorithms
// ====================================

#include "elem.h"

// regular constructor - blank element
el_t::el_t()
{
  name = ' ';
  weight = 0;
}

// special constructor - initialize element with name and weight
el_t::el_t(char name, int weight)
{
  this->name = name;
  this->weight = weight;
}

// defines == for elements during search
// based on the name part only
bool el_t::operator==(el_t OtherOne)
{
  if(this->name == OtherOne.name) {
   return true;
  }
  return false;
}

// overload cout for el_t 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.name << "+" << E.weight;
  return os;  
}  


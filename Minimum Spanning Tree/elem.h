//========================================
// header for the MST element
// name: Tyler Gerritsen
// compiler: g++
//========================================
#ifndef ELEM_H
#define ELEM_H

#include <iostream>
#include <string>
using namespace std;

// list node element type to be defined by the client
class el_t
{
 private:
  // parts of an element to be defined by the client of this class
  // this time, it has the name and weight.
  char name;    // name of a vertex
  int  weight;  // weight on the edge to it

 public:

  el_t();  // blank element can be created
  el_t(char, int);  // initialized element can be created

// Functions needed to make llist and slist work ----

  bool operator==(el_t); // compares two el_t 
                         // elements in search

  // This overloads cout for the el_t object
  // This is a friend function since the receiver object for it
  // is not el_t
  friend ostream& operator<<(ostream&, const el_t&);  

  friend class dgraph;
};

#endif

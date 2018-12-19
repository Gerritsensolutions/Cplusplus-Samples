// CS311 Yoshii - this class defines Elem type for a Node
// Because it now has multiple parts, operator== and cout
// must be defined for the list classes to work.
// The client (dgraph2)
// gets to use this class for its node Elem.
// DO NOT CHANGE!!
// -----------------------------------------------------
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

  friend class dgraph;  // dgraph2 is the client of this class
                         // so it is able to use the private parts
};

#endif

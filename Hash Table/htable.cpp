// CS311 Yoshii - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Tyler Gerritsen
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"

// default constructor
htable::htable()
{}

// default destructor
htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
// PURPOSE: hashes a key
// PARAMS: int key - the key to be hashed
// REUTRN: int - integer result of the hash function
int htable::hash(int key)
{ 
  return (key % TSIZE);
}

// PURPOSE: adds the element to the table and returns slot#
// PARAMS: el_t element - element object to be added
// RETURN: int - slot number of the hashed element
int htable::add(el_t element )
{
  int slot = hash(element.key);  // hash with the key part
  table[slot].addRear(element);
  return slot;
}

// PURPOSE: finds element using the skey and returns the found element itself
//          or a blank element
// PARAMS: int skey - key of the el_t to be searched for
// RETURN: el_t - element found, or a blank element if not found
el_t htable::find(int skey)
{ 
 el_t E; // a blank element
 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.key = skey; // initialize it with just the skey
 E = table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return E; // return the found element from here
}

// PURPOSE: displays the entire table with slot#s too
// PARAMS: none
// RETURN: none
void htable::displayTable()
{
  cout << endl << "Current Table" << endl;
  cout << "------- -----" << endl << endl;
  for (int i = 0; i < 37; i++)
    { cout << "\t" << i << ":";   
      table[i].displayAll(); // call slist's displayAll
    }
  cout << endl;
}

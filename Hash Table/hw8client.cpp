// CS311 Yoshii - complete ** for HW8 client
// Note that the client knows about elem.h functions.
// It can create el_t objects.
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Tyler Gerritsen
// File type: client hw8client.cpp
//===========================================

using namespace std;
#include "htable.h"
#include <iostream>

// note that the second constructor of el_t can be used to
// create key+name to add to the table.
int main()
{
  // declare a hash table object
  htable hash;

  /*
  Loop:  
   Interactively add about 20 keys and names to the table,
     making sure some of them  collide. (function add)
     You can create el_t containing a key and name using a constructor. */
  cout << "Enter keys and names to populate the table, then enter -1 to signify the end of your input" << endl;
  cout << "Key: ";
  int key;
  cin >> key;
  
  cout << "Name: ";
  string name;
  cin >> name;
  
  // loop to enter values
  while ( key != -1 ) {
    el_t elem(key, name);
    hash.add(elem);

    cout << "Key: ";
    cin >> key;
    
    if ( key != -1 ) {
      cout << "Name: ";
      cin >> name;
    }
  }
  key = 0;

  // DisplayTable.
  hash.displayTable();
 
 /*
 Loop:
  Interactively look up names using keys. (function find)
  Display the key + name if found else error message. */ 
  cout << "Now enter any key to look for in the list. Enter -1 to finish." << endl;
  
  cout << "Key: ";
  cin >> key;
  
  // search key
  while ( key != -1 ) {
    el_t result = hash.find(key);
    cout << endl << "RESULT: " << endl;
    if ( result == el_t() ) {
      cout << "Not Found!" << endl; 
    }
    else {
      cout << "\t" << result << endl << endl;
    }

    cout << "Key: ";
    cin >> key;
  }
 }

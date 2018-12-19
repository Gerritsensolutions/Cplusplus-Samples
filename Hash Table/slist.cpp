// CS311 Complete all functions with their comments

//=============================================
//HW#: HW3P1 slist
//Your name: Tyler Gerritsen
//Compiler: g++
//File type: slist.cpp implementation file
//=============================================

using namespace std;
#include<iostream>
#include "slist.h"

// Make sure llist constructor and destructors have couts in them

// default constructor
slist::slist() {
  //cout << "slist constructor: " << endl;
} 

// PURPOSE: search takes one argument to search the linked list's nodes' Elems for
// PARAMS: key - the Elem to be searched for
// RETURN: int - Ith node whose Elem is the key, 0 if not found
int slist::search(el_t key) {
  int index = 1;
  Node* P = Front;
  if ( P == NULL ) {
      return 0;
    }
  while ( !(P->Elem == key) ) {
    P = P->Next;
    index++;
    if ( P == NULL ) {
      return 0;
    }
  }
  return index;
}

// PURPOSE: search takes one argument to search the linked list's nodes' Elems for
// PARAMS: key - the Elem to be searched for
// RETURN: el_t - Ith node whose Elem is the key, 0 if not found
el_t slist::search2(el_t key) {
  int index = 1;
  Node* P = Front;
  el_t ret;
  if ( P == NULL ) {
      return ret;
    }
  while ( !(P->Elem == key) ) {
    P = P->Next;
    index++;
    if ( P == NULL ) {
      return ret;
    }
  }
  return P->Elem;
}

// PURPOSE: replaces the Elem in a note at a given position with a new Elem
//          specified by the caller
// PARAMS: element - new value for Elem
//         pos - position of node to be accessed
// RETURN: none
void slist::replace(el_t element, int pos) {
  if ( pos < 1 || pos > Count ) {
    throw OutOfRange();
  }
  Node *P = Front;
  for ( int i = 1; i < pos; i++ ) {
    P = P->Next;
  }
  P->Elem = element;
}

// PURPOSE: overloaded == operator for llist comparison
// PARAMS: OtherOne - a llist object reference to compare this object to
// RETURN: bool - true if the list elements are all the same
bool slist::operator==(const slist& OtherOne) {
  if ( this->Count != OtherOne.Count ) {
    return false;
  }
  
  Node *P = this->Front;
  Node *P2 = OtherOne.Front;
  while ( P != NULL ) {
    if ( !(P->Elem == P2->Elem) ) {
      return false;
    }
    P = P->Next;
    P2 = P2->Next;
  }
  return true;
}

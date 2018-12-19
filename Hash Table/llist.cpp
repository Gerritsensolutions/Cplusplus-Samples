//CS311
//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  control-K cuts and control-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Tyler Gerritsen
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist() {
  //cout << "Calling llist constructor" << endl;
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist() { 
  //cout << "Calling llist destructor" << endl;
  el_t num;
  while ( !isEmpty() ) {
    deleteFront(num);
  }
}

//PURPOSE: isEmpty takes no parameters, and simply checks rear, front and count to see if
//         the list is empty. If front and rear are NULL, and count == 0, then the list is
//         empty.
//PARAMETER: None
bool llist::isEmpty() {
  if (Front == NULL && Rear == NULL && Count == 0) {
    return true;
  }
  return false;
}

//PURPOSE: displayAll displays all the values held by each node in the llist,
//         in sequential order and in a format that is easily readable.
//PARAMETER: None
void llist::displayAll() { 
  if ( isEmpty() ) {
    cout << "[ empty ]" << endl;
    return;
  }
  Node *P = Front;
  cout << "[ ";
  while ( P != NULL ) {
    cout << P->Elem << " ";
    P = P->Next;
  }
  cout << "]" << endl;
}
  
//PURPOSE: addRear appends the llist with a new node holding
//         the value of its argument as Elem
//PARAMETER: NewNum - the value to be held in the new node
void llist::addRear(el_t NewNum) { 
  // special case - first node
  if ( isEmpty() ) {
    Front = new Node;
    Rear = Front;
    Rear->Next = NULL;
    Front->Elem = NewNum;
    Count++;
  }
  // regular case - existing nodes
  else {
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
    Count++;
  }
}

//PURPOSE: adds and element to the front of the linked list
//PARAMETER: NewNum - the value of the Elem in the new node
//           to be added
void llist::addFront(el_t NewNum) { 
  // special case - first node
  if ( isEmpty() ) {
    Front = new Node;
    Rear = Front;
    Rear->Next = NULL;
    Front->Elem = NewNum;
    Count++;
  }
  // regular case - existing nodes
  else {
    Node *P = new Node;
    P->Next = Front;
    Front = P;
    Front->Elem = NewNum;
    Count++;
  }
}

//PURPOSE: deletes the node at the front of the llist
//PARAMETER: OldNum - gets the value of the deleted node's Elem
void llist::deleteFront(el_t& OldNum) { 
  // error case
  if ( isEmpty() ) { throw Underflow(); }  
  // special case
  else if ( Front->Next == NULL ) {
    OldNum = Front->Elem;
    delete Front;
    Count--;
    Front = NULL;
    Rear = NULL;
  } 
  // regular case
  else {
    Node* P = Front->Next;
    OldNum = Front->Elem;
    delete Front;
    Front = P;
    Count--;
  }
}

//PURPOSE: delete the last node in the llist 
//PARAMETER: OldNum - gets the value of the deleted node's Elem
void llist::deleteRear(el_t& OldNum) { 
  // error case
  if ( isEmpty() ) {
    throw Underflow();
  }
  // special case
  else if ( Front == Rear ) {
    OldNum = Rear->Elem;
    delete Rear;
    Rear = NULL;
    Front = NULL;
    Count--;
  }
  // regular case
  else {
    Node *P = Front;
    while ( P->Next != Rear  ) {
      P = P->Next;
    }
    OldNum = Rear->Elem;
    delete Rear;
    Rear = P;
    Rear->Next = NULL;
    Count--;
  }
}

//PURPOSE: Deletes the node at index I
//PARAMETER: I - the index of the node to be deleted
//           OldNum - value of the Elem in the Ith node
void llist::deleteIth(int I, el_t& OldNum) { 
  // error case
  if ( I > Count || I < 1 ) {
    throw OutOfRange();
  }
  // special case
  else if ( I == 1) { 
    deleteFront(OldNum);
    return;
  }
  else if ( I == Count ) { 
    deleteRear(OldNum);
    return;
  }
  // regular case
  else {
    Node *P = Front;
    for ( int i = 1; i <= I - 2; i++  ) {
      P = P->Next;
    }
    Node *P2 = P->Next;
    P->Next = P2->Next;
    OldNum = P2->Elem;
    delete P2;
    Count--;
  }
}

//PURPOSE: inserts a node at the user-specified Ith index
//PARAMETER: I - user specified index
//           NewNum - value of the Elem of the node to be inserted
void llist::insertIth(int I, el_t NewNum) { 
  // error case
  if ( I > Count + 1 || I < 1 ) {
    throw OutOfRange();
  }
  // special case
  else if ( I == 1 ) {
    addFront(NewNum);
  } 
  else if ( I == Count + 1 ) {
    addRear(NewNum);
  }
  // regular case
  else {
    Node *P = Front;
    for ( int i = 1; i <= I - 2; i++  ) {
      P = P->Next; 
      }
    Node *P2 = new Node;
    P2->Elem = NewNum;
    P2->Next = P->Next;
    P->Next = P2;
    Count++;
  }
}

//PURPOSE: Copy constructor
//PARAMETER: Original - the object to be copied
llist::llist(const llist& Original) { 
  Front = NULL;
  Rear = NULL;
  Count = 0;

  el_t bs; 
  if (&Original != this) {
    while ( !this->isEmpty() ) {
      deleteRear(bs);
    }
    Node* P;
    P = Original.Front;
    while ( P != NULL ) {
      this->addRear(P->Elem);
      P = P->Next;
      }
  } // end of if
}

//PURPOSE: Overloaded assignment operator for use in the copy constructor
//PARAMETER: OtherOne - other llist object which all the nodes in this will be equal to
llist& llist::operator=(const llist& OtherOne) { 
  el_t bs; 
  if (&OtherOne != this) {
    while ( !this->isEmpty() ) {
      this->deleteRear(bs);
    }
    Node* P;
    P = OtherOne.Front;
    while ( P != NULL ) {
      this->addRear(P->Elem);
      P = P->Next;
      }
  } // end of if
  return *this;
}


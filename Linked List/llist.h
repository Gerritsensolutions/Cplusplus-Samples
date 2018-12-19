//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Tyler Gerritsen
// Compiler:  g++ 
// File type: header file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  // PURPOSE: checks if llist is empty
  // PARAMS: none
  bool isEmpty();
    
  // PURPOSE: displays all elements in the llist in an easily readable format
  // PARAMS: none
  void displayAll();

  // PURPOSE: adds an element to the front of the llist
  // PARAMS: el_t element to be added
  void addFront(el_t);
    
  // PURPOSE: adds an element to the rear of the llist
  // PARAMS: el_t element to be added
  void addRear(el_t);

  // PURPOSE: deletes the element at the front of the list
  // PARAMS: el_t& reference to return removed element
  void deleteFront(el_t&);
    
  // PURPOSE: deletes the element at the rear of the list
  // PARAMS: el_t& reference to return removed element
  void deleteRear(el_t&);
    
  // PURPOSE: deletes Ith element
  // PARAMS: int the specified Ith element
  //         el_t& reference to return removed element
  void deleteIth(int, el_t&);

  // PURPOSE: inserts Ith element
  // PARAMS: int the specified Ith element
  //         el_t& reference to return inserted element    
  void insertIth(int, el_t);

  //Copy Constructor to allow pass by value and return by value
  llist(const llist&);
  
  //Overloading of = 
  llist& operator=(const llist&); 

};

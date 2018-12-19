// =======================================================
// stack
// Your name: Tyler Gerritsen
// Compiler:  g++ 
// File type: headher file stack.h
//=======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 10;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef int el_t;     // the el_t type is int for now

//-------------------------------------------------------


class stack
{ 
  
 private: // to be hidden from the client
  
   el_t     el[MAX];       // el is  an array of el_t's
   int      top;           // top is index to the top of stack

 public:  // available to the client
  
  // Add exception handling classes here  
   class Overflow{};  // empty class thrown as overflow exception
   class Underflow{};  // empty class thrown as underflow exception
  
  // prototypes to be used by the client
  // Note that no parameter variables are given

  stack();   // constructor to create an object
  ~stack();  // destructor  to destroy an object
  
  // PURPOSE: if not full, enters an element at the top;
  //          otherwise throws an exception - Overflow
  // PARAMETER: pass the element to be pushed
  void push(el_t);
  
  // PURPOSE: if not empty, removes and gives back the top element;
  //          otherwise throws an exception - Underflow
  // PARAMETER: provide variable to receive the popped element (by ref)
  void pop(el_t&);
  
  // PURPOSE: if not empty, gives the top element without removing it;
  //          otherwise, throws an exception - Underflow
  // PARAMETER: variable passed by reference which is the top of the stack
  void topElem(el_t&);
  
  // ** Must add good comments for each function - See Notes1B

  // PURPOSE: returns true if the stack is empty, false otherwise
  //
  // PARAMETER: none
  bool isEmpty();

  // PURPOSE: returns true if the stack is full, false otherwise
  //
  // PARAMETER: none
  bool isFull();

  // PURPOSE: prints a visual representation of all elements in the stack
  // 
  // PARAMETER: none
  void displayAll();

  // PURPOSE: clear the stack of all elements
  // 
  // PARAMETER: none
  void clearIt();
  
};  


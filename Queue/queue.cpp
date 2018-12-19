//INSTRUCTION:
//Look for ** using control-S
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P2 queue
//Your name: Tyler Gerritsen
//Complier:  g++
//File type: Implementation  queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
  count = 0;
  front = 0;
  rear = -1;
}

//destructor 
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if ( count == 0 ) { return true; }
  else { return false; }
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{ 
  if ( count == MAX_SIZE) { return true; }
  else {return false; }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
  if ( isFull() ) { throw Overflow(); }
   rear = (rear + 1) % MAX_SIZE; 
   el[rear] = newElem; 
   count++; 
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{ 
  if ( isEmpty() ) { throw Underflow(); }
  removedElem = el[front]; 
  front = (front + 1) % MAX_SIZE; 
  count--; 
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{ 
  if ( isEmpty() ) { throw Underflow(); }
  theElem = el[front]; 
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{ return count; }

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  int j = front;
  cout << "[";
   for (int i = 1; i <= count; i++)
     { 
       cout << el[j];
       j = ( j + 1 ) % MAX_SIZE; 
     }
   if ( isEmpty() ) { cout << " empty "; }
   cout << "]" << endl;   

}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{   
  if ( isEmpty() ) { throw Underflow(); } 
  if ( count > 1 ) {
    el_t temp;
    remove(temp);
    add(temp);
  }
}


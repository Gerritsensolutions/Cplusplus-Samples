

// CS311 Yoshii - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Tyler Gerritsen
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
void pqueue::insertjob(int j)
{
  // ** add the job j at the rear
  cout << "Adding: " << j << endl;
  Q[count] = j;
  count++;
  trickleup(); // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "printing: " << Q[0] <<endl;
  reheapify();
  count--;
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // ** loop to display jobs from slot 0 to slot count-1 horizontally
  for ( int i = 0; i < count - 1; i++ ) {
    cout << Q[i] << " ";
  }
  cout << Q[count - 1] << " " << endl;
} 

// Utility functions follow: ------------------


// Purpose: to make the very last job trickle up to the right location 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job location
  // ** while x is > 0
  while ( x > 0 ) {
    // compare Q[x] with the parent and if the parent is bigger swap & update x. Otherwise stop.
    // You can call getParent to get the location of the parent
    //cout << "Qx: " << Q[x] << " - parent: " << Q[getParent(x)] << endl; 
    if ( Q[x] < Q[getParent(x)] ) {
      //cout << "Qx < parent" << endl;
      int temp = Q[x];
      Q[x] = Q[getParent(x)];
      Q[getParent(x)] = temp;
      x = getParent(x);
    }
    else {
      return;
    }
  }
}

// Purpose: find the location of the parent 
// The child location is given.  Need to call even.
int pqueue::getParent(int child)
{  // ** return the parent location
  if ( even(child) ) {
    return ((child - 2) / 2);
  }
  return ((child - 1) / 2);
}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }


// Purpose: to reheapify the Pqueue after printing
void pqueue::reheapify()
{ 
  // move the last job to the front
  Q[0] = Q[count - 1];
  
  // ** start at the root and repeat the following:
  // find the location of the smaller child if you have not fallen off the tree yet
  // if the smaller child is smaller than the parent, swap
  int i = 0;
  while ( getSmallerChild(i) < count ) {
    //cout << "child: " << getSmallerChild(i) << endl;
    if ( Q[getSmallerChild(i)] < Q[i] ) {
      int temp = Q[i];
      Q[i] = Q[getSmallerChild(i)];
      Q[getSmallerChild(i)] = temp;
      i = getSmallerChild(i);
    }
    //  else stop
    else {
      return;
    }
  } 
}

// Purpose: to find the location of the smaller child
// where children at locations 2*i+1 and 2*i+2
int pqueue::getSmallerChild(int i)
{
  // ** return the location of the smaller child
  if ( Q[2*i+2] > Q[2*i+1] ) {
    return (2*i+1);
  }
  return (2*i+2);
}



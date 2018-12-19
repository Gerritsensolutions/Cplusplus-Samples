//======================================================
// dgraph.cpp
// Name: Tyler Gerritsen
// File Type: Implementation
// represents a directed graph
//========================================================

using namespace std;
#include <iostream>
#include "dgraph.h"

// default constructor
// PURPOSE: initializes Gtable values and countUsed
dgraph::dgraph() { // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
  for ( int i = 0; i < SIZE; i++ ) {
    Gtable[i].visit = 0;
    Gtable[i].vertexName = ' ';
  }
  countUsed = 0;
}

// default destructor
dgraph::~dgraph() { 
  
}

// filltable()
// PURPOSE: Populate Gtable with information from table.txt
// PARAMS: None
// RETURN: None
void dgraph::fillTable() { // be sure to read from a file
  ifstream table;
  table.open("table.txt");
  
  char elem;

  while ( table >> Gtable[countUsed].vertexName ) { // If I can read the name
    table >> Gtable[countUsed].outDegree;
    for ( int i = 0; i < Gtable[countUsed].outDegree; i++ ) {
      table >> elem;
      (Gtable[countUsed].adjacentOnes).addRear(elem); // slist function from HW3
    }
    countUsed++;
  }
  table.close();
}

// displayGraph()
// PURPOSE: Displays all elements in the Gtable in an aesthetically pleasing way
// PARAMS: None
// RETURN: None
void dgraph::displayGraph() { // be sure to display
  // in a really nice format -- all columns
  cout << endl;
  cout << setw(12) << left << "Vertex" 
       << setw(12) << left << "Out Degree" 
       << setw(12) << left << "Visit" 
       << setw(12) << left << "Adjacents" << endl;
  cout << setw(12) << left << "------" 
       << setw(12) << left << "----------" 
       << setw(12) << left << "-----" 
       << setw(12) << left << "---------" << endl;
  for ( int i = 0; i < countUsed; i++) {
    cout << setw(12) << left << Gtable[i].vertexName
	 << setw(12) << left << Gtable[i].outDegree 
	 << setw(12) << left << Gtable[i].visit;
    (Gtable[i].adjacentOnes).displayAll();
  }
  cout << endl;
}

// findoutDegree(char)
// PURPOSE: gets the number of adjacent nodes going out of this one
// PARAMS: char V - the name of the node to access
// RETURN: int - the number of outward paths to adjacent nodes
int dgraph::findOutDegree(char V) { // throws exception
  // does not use a loop
  if ( (int)V < 65 || (int)V > 73 ) {
    throw BadVertex();
  }
  V = (int)V - 65;
  return Gtable[V].outDegree;
}

// findAdjacency(char)
// PURPOSE: gets the slist object of adjacent nodes
// PARAMS: char V - the name of the node to access
// RETURN: slist - slist object containing the adjacent vertices
slist dgraph::findAdjacency(char V) { // throws exception
  // does not use a loop
  if ( (int)V < 65 || (int)V > 73 ) {
    throw BadVertex();
  }
  V = (int)V - 65;
  return Gtable[V].adjacentOnes;
}

// visit(int, char)
// PURPOSE: assign a visit number to a node
// PARAMS: int x - value to be assigned to visit data member
//         char V - name of node to check
// RETURN: None
void dgraph::visit(int x, char V) {
  // does not use a loop
  if ( (int)V < 65 || (int)V > 73 ) {
    throw BadVertex();
  }
  V = (int)V - 65;
  Gtable[V].visit = x;
}

// isMarked(char)
// PURPOSE: check if node is marked
// PARAMS: char V - name of the node to check
// RETURN: true if visit value is greater than 0
bool dgraph::isMarked(char V) {
    // does not use a loop
  if ( (int)V < 65 || (int)V > 73 ) {
    throw BadVertex();
  }
  V = (int)V - 65;
  return (Gtable[V].visit > 0) ? true : false;
} 

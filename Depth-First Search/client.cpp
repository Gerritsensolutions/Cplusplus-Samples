//==========================================
// DFS client using dgraph.h
// Name: Tyler Gerritsen
// File type: client
//==========================================

// Be sure to include dgraph, slist and stack
#include "dgraph.h"
#include "stack.h"
#include <iostream>

using namespace std;

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  dgraph graph;
  stack s;
  // use the algorithm (read carefully) in the HW7
  // assignment sheet
  
  // these variables will come in handy in the loop. They enhance readability
  // and make the code more concise
  char vertex = 'A';
  int degree = graph.findOutDegree('A');
  bool isMarked = graph.isMarked(vertex);
  slist adjacency = graph.findAdjacency('A');
  int visitNumber = 1;
  char adjacentVertex;

  graph.fillTable();
  graph.displayGraph();
  s.push(vertex);
  
  while ( !s.isEmpty() ) {
    s.pop(vertex);
    //degree = graph.findOutDegree(vertex);
    //isMarked = graph.isMarked(vertex);
    cout << "Removed " << vertex << " from the stack" << endl;
    if ( !graph.isMarked(vertex) ) {
      //cout << "isMarked is no" << endl; 
      graph.visit(visitNumber, vertex);
      cout << "Visit " << vertex << " as " << visitNumber << endl;
      visitNumber++;
      adjacency = graph.findAdjacency(vertex);
      if ( adjacency.isEmpty() ) {
	cout << "Deadend reached - backup" << endl;
      }
      else { 
	cout << "pushing... ";
	adjacency.displayAll();
	while ( !adjacency.isEmpty() ) {
	  adjacency.deleteRear(adjacentVertex);
	  //cout << "Adjacent vertex: " << adjacentVertex << endl;
	  s.push(adjacentVertex);
	}
	cout << "Current Stack: " << endl;
	s.displayAll();
      }
    }
    else { 
      cout << vertex << " has been visited already - backup" << endl;
      cout << "Current Stack: " << endl;
      s.displayAll();
      cout << endl;
    }
    graph.displayGraph();
  }

}

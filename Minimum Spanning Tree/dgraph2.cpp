// ========================================
// MST
// Name: Tyler Gerritsen
// File: dgraph2.h implementation
// Given defined nodes for a directed graph, generates a minimum spanning tree
// =========================================

using namespace std;
#include "dgraph2.h"
#include <fstream>
#include <string>
#include <iomanip>

dgraph::dgraph()
{ count = 0; }

dgraph::~dgraph() 
{ count = 0;}

// fill the table with a file content
void dgraph::filltable()
{
  string filename;
  ifstream fin;
  cout << "Enter the input file name: ";
  cin >> filename;
  fin.open(filename.c_str(), ios::in);

  char n;
  int w;
  
  while( fin >> G[count].Name ) {
    fin >> G[count].Out;
    G[count].DistTo = 0;
    G[count].Kind = ' ';
    G[count].From = ' ';
    for ( int i = 0; i < G[count].Out; i++ ) {
      fin >> n;
      fin >> w;
	(G[count].Adj).addRear(el_t(n,w));
    }
    cout << "Read " << G[count].Name << " ";
    count++;
  } 
  cout << endl;
  fin.close();
  displayTable();
}

// display the table in a very readable format
void dgraph::displayTable()
{
  cout << setw(5) << left << "Name " << setw(5) << left << "Kind " << setw(5) << left << "Dist " << setw(5) << left << "From " << endl;
  for ( int i = 0; i < count; i++ ) {
    cout << setw(5) << left << G[i].Name << setw(5) << left << G[i].Kind << setw(5) << left << G[i].DistTo << setw(5) << left << G[i].From << flush;
    (G[i].Adj).displayAll();
  } 
}


// is everyone in the Tree?
bool dgraph::allTree()
{
  //**
  for ( int i = 0; i < count; i++ ) {
    if ( !(G[i].Kind == 'T') ) {
      return false;
    }
  }
  return true;
}

// find the edges in the MST (at the end)
void dgraph::displayMST()
{ cout << "Edges in the MST are:" << endl;
  //**
  for ( int i = 1; i < count; i++ ) {
    cout << "From " << G[i].From << " to " << G[i].Name << " with " << G[i].DistTo << endl;
  }
}

// retrieve and display the shortest path to V 	(at the end)
void dgraph::displayPath(char V)
{ cout << "Edges in the shortest path are:" << endl;
  //**
  
}


// find the fringe vertex with the smallest DISTO. 
// return the location in the table.
int dgraph::findSmallest()
{ //**
  int smallestIndex = 0;
  
  // find an initial fringe to compare the others with
  for (int i = 0; i < count; i++) {
    if ( G[i].Kind == 'F' ) {
      smallestIndex = i;
      break;
    }
  }
  // start comparing
  for (int i = 0; i < count; i++) {
    if ( G[i].Kind == 'F' ) {
      if ( G[i].DistTo < G[smallestIndex].DistTo ) {
	smallestIndex = i;
      }
    }
  }
  return smallestIndex;
}
   
// Adding i's vertex to tree (T)
// causing more Fringe vertices to be added
void dgraph::makeTree(int i)
{ 
  cout << "Adding " << G[i].Name << " to tree" << endl; 
  G[i].Kind = 'T'; //** Make it T
  slist l = G[i].Adj; //** get all adjacent vertices
  l.displayAll();
  el_t arg;
  for ( int j = 0; j < G[i].Out; j++ ) { //** calls makeFringe on each adjacent vertex
    l.deleteFront(arg);
    makeFringe(arg, G[i].Name, 0);
  }
}

// Utility: Enter or update the DISTO of a fringe vertex
void dgraph::makeFringe(el_t X, char V)
{ 
  // X is the fringe vertex (a node's Elem from slist)
  // V is which tree vertex the edge came from

  //**
  X.name = (int)X.name - 65;
    if ( G[X.name].Kind != 'T' ) {
      if ( G[X.name].Kind == 'F' ) {
	cout << "Old Fringe: " << (char)((int)X.name + 65) << " with edge cost: " << X.weight << endl;
	cout << "... update to better distance" << endl;
      }
      else {
	cout << "New Fringe: " << (char)((int)X.name + 65) << " with weight: " << X.weight << endl;
      }
      G[X.name].From = V;
      G[X.name].DistTo = X.weight;
      G[X.name].Kind = 'F';
    }
}



// ================================================
// dgraph client 
// Name: Tyler Gerritsen
// File type: Client
// ================================================

#include "dgraph.h"
using namespace std;

//**
// This client for the Gtable creates and populates a Gtable object from an
// input .txt file (table.txt), diplays the table in a comfortable format, and
// displays any user-specified vertices.
int main()
{ //**
  dgraph table; //0.Declare table object
  table.fillTable(); //1.fillTable()
  table.displayGraph(); //2.displayGraph()
    /*
  while (the user does not want to stop)
    a.the user will specify which vertex     
    b.findOutDegree of the vertex and display the result
    b.findAdjacency of the vertex and display the result
    c.catch exception to display error mesg but do not exit
  */
  char in;
  int degree;
  slist adjacency;  

    while ( 1 == 1 ) {
      try {
	cout << "enter your desired vertex (enter Z to exit): ";
	cin >> in;
	if ( in == 'Z' ) { break; }
	degree = table.findOutDegree(in);
	adjacency = table.findAdjacency(in);
	cout << endl << "Data: " << endl
	     << setw(13) << "\tDegree: " <<  degree << endl
	     << setw(12) << "\tAdjacency: ";
	adjacency.displayAll();
	cout << endl;
      }
      catch (dgraph::BadVertex E) {
	cout << "That vertex doesn't exist! Pick a different one." << endl;
      }
    }

}

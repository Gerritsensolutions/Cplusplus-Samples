//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application
//Your name: Tyler Gerritsen
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: use a stack data structure to implement processing of postfix mathematical expressions
//Algorithm: push operands in the expression onto the stack until an operator is encountered.
//           Then, two operands are popped for the operator calculation and the result is pushed again.
//           This process is repeated until the end of input.
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char

	 // ** do all the steps in the algorithm given in Notes-1

	 if ( (item - 48) >= 0 && (item - 48) <= 9 ) {
	   postfixstack.push(item - 48);
	   cout << "STACK" << endl;
	   postfixstack.displayAll();
	 }

	else if (item == '*' ) {
	 postfixstack.pop(box2);
	 postfixstack.pop(box1);
	 postfixstack.push(box1 * box2);
	 cout << "STACK" << endl;
	 postfixstack.displayAll();
	}	 
	 
	else if (item == '+' ) {
	 postfixstack.pop(box2);
	 postfixstack.pop(box1);
	 postfixstack.push(box1 + box2);
	 cout << "STACK" << endl;
	 postfixstack.displayAll();
	}		 

	else if (item == '-' ) {
	 postfixstack.pop(box2);
	 postfixstack.pop(box1);
	 postfixstack.push(box1 - box2);
	 cout << "STACK" << endl;
	 postfixstack.displayAll();
	}

	else {
	  throw "One of the inputs is invalid. It doesn't make any sense!";
	}

       } // this closes try
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{ cerr << "Too many items are in the stack. It's full!" << endl; exit(1); }
      catch (stack::Underflow)
	{ cerr << "The stack is already empty. You can't pop it again!" << endl; exit(1); }
      catch (char const* errormsg ) // for invalid item case
	{ cerr << "Error has occurred: " << errormsg << endl; exit(1); }

      // go back to the loop after incrementing i
     i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
  postfixstack.pop(box1);
  cout << "The final result is: " << box1 << endl;
 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
  if (!postfixstack.isEmpty()) {
    cout << "The expression was incomplete. Check your input!" << endl;
  }

}// end of the program

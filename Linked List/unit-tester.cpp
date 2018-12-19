using namespace std;
#include <iostream>
#include "slist.h"
#include <stdlib.h>

int main() {
  int x;
  slist list1;
  slist list2;
  list1.addRear(1); list1.addRear(2); list1.addRear(3); list1.addRear(4);
  list1.displayAll();
  list1.deleteRear(x);
  cout << "deleteRear test: " << x << endl;
  //list2.addRear(1); list2.addRear(2); list2.addRear(4);
  //list1.displayAll();
  //list1.displayAll();
  //list1.addRear(3);
  //list1.displayAll();
}

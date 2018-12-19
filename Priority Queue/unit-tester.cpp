// hw5 unit tester

using namespace std;
#include <iostream>
#include "pqueue.h"

int main() { 
  pqueue queue;
  queue.insertjob(20);
  queue.displayAll();
  queue.insertjob(12);
  queue.displayAll();
  queue.insertjob(30);
  queue.displayAll();
  queue.insertjob(1);
  queue.displayAll();
  //queue.printjob();
  //queue.displayAll();
  return 0;
}


#include<iostream>
using namespace std;

//----------------------------------------
//Partition
//Name: Tyler Gerritsen
//Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r)
{
  int beg = f; // pointer from the left
  int end = r; // pointer from the right 

  while ( beg <= end ) {  // loop for finding out of place pair and swap them
    //cout << "loop" << endl;
    if ( a[beg] >= pivot && a[end] < pivot ) {
	int temp = a[beg];
	a[beg] = a[end];
	a[end] = temp;
	//cout << "swap loop" << endl;
    }
    if ( a[beg] < pivot ) {
      beg++;
      //cout << "beg++ " << beg << endl;
    }
    if ( a[end] >= pivot ) {
      end--;
      //cout << "end--" << end << endl;
    }
  }
  //cout << "ret " << beg << endl;
  // return the partition point where
  // those smaller than pivot are before what is returned
  if ( beg < 1 ) { return 1; }
  else return beg;
}

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;
  int part = partition(nums[0], nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

}

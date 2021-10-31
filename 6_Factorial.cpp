/* ==================================================
   Exersice. Pointers.
   Authors: I.Kulakov; M.Zyzak
   ================================================== */

// Will this program work? Find 2 bugs. Fix them with minimum changes in the program code.

#include<iostream>
using namespace std;

const int N = 10;

  // Get set of the factorials of the first N numbers
int* GetFactorials(){
  int* a = new int[N]; // Important to be allowed to get the array to the main
  //int a[N];          // Not in use due to the row above

  a[0] = 1;
  for( int i = 1; i < N; ++i )
    a[i] = i*a[i-1];

  return a;
}

int main() {
    // Get set of the factorials of the first N numbers
  int* b = new int[N]; //A new pointer to get the a of the function
  b = GetFactorials(); //Renamed a to b to get rid of the warning message

    // print it
  for( int i = 0; i < N; ++i )
    cout << b[i] << endl;

  delete[] b;
  
  return 0;
}


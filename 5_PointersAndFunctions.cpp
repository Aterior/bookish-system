/* ==================================================
   Exersice. Pointers.
   Authors: I.Kulakov; M.Zyzak
   ================================================== */

// Will this program work? Find and fix 2 bugs.

#include<iostream>
using namespace std;

void piPointer1(float* pi) {
  *pi = 3.14;
}

float* piPointer2() {
  float* pi = new float; // Needs to be a dynamic pointer, because the pointer has to 
  *pi = 3.1415;          // to be freed after the functions' end.
  return pi;
}

int main() {
  float* pi1 = new float; // Needs to be a dynamic pointer, because the pointer is
  piPointer1(pi1);        // initialized in the piPointer1 function.
  cout << *pi1 << endl;
  delete pi1;             // Because of the dynamic piPointer1, pi1 has to be deleted
                          // as well.
  float* pi2 = piPointer2(); // This is a local pointer which has to get its value
  cout << *pi2 << endl;      // of a function (dynamic pointer) to stop the 
  delete pi2;                // segmentation fault.
    
  return 0;
}


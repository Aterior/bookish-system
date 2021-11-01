/* ==================================================
   Exersice. Templates.
   Authors: I.Kulakov; M.Zyzak
   ================================================== */

// The machine epsilon can be found as the smallest value of E, such that (1 + E) is not equal to 1.
// see http://en.wikipedia.org/wiki/Machine_epsilon for more information

// Estimate (with precision < 100%) the machine epsilon for float, double, long double types. Use templates.

#include <iostream>
#include <iomanip>
using namespace std;


// TODO template function -> DONE || The formular of wikipedia
template <typename T>
T FindMachineEpsilon(T a){
  T prev_epsilon = 1;
  while ((1 + a)!= 1){
    prev_epsilon = a;
    a /= 2;
  }
  return prev_epsilon;
}

int main () { // Just the required outputs
  cout << "Machine epsilon for double is: " << FindMachineEpsilon<double>(1) << endl;
  cout << "Machine epsilon for long double is: " << FindMachineEpsilon<long double>(1)<< endl;
  cout << "Machine epsilon for float is: " << FindMachineEpsilon<float>(1) << endl;
  cout << "Machine epsilon for int is: " << FindMachineEpsilon<int>(1) << endl;

  return 0;
}



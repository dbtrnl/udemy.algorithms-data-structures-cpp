#include <iostream>

using namespace std;

int headFactorial(int n) {
  cout << "Head function called with n = " << n << endl;
  if (n == 1) return 1;
  return n * headFactorial(n-1);
}

int tailFactorial(int n, int result) {
  cout << "Tail function called with n = " << n << endl;
  if (n == 1) return 1;
  return tailFactorial(n-1, n*result);
}

int main() {
  tailFactorial(154343, 1);
  headFactorial(154343);
  /*
    How to benchmark this? 
   */
}
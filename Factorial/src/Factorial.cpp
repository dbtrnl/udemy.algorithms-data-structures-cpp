#include <iostream>

using namespace std;

int factorial(int n) {
  if(n == 1) return 1;
  return n*factorial(n-1);
}

int factorialAccumulator(int n, int accumulator) {
  if (n == 1) return accumulator;
  return factorialAccumulator(n-1, n*accumulator);
}

int main() {
  cout << factorial(10) << endl;
  return 0;
}
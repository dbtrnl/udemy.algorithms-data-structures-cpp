#include "FibonacciProblem.h"
#include <iostream>
using std::cout;

int main() {
  FibonacciAlgorithm fibonacciAlgorithm;
  cout << fibonacciAlgorithm.fibonacciMemoize(30) << '\n';
  // cout << fibonacciAlgorithm.fibonacciExponential(30) << '\n';
  return 0;
}
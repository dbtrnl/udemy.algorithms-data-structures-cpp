#ifndef FibonacciAlgorithm_h
#define FibonacciAlgorithm_h

#include <vector>
using std::vector;

class FibonacciAlgorithm {
  vector<int> memoizeTable;

public:
  FibonacciAlgorithm();
  int fibonacciMemoize(int n);
  int fibonacciExponential(int n);
};

#endif
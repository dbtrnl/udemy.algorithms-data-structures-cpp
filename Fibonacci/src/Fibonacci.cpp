#include <iostream>

using namespace std;

int fibonacci(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  /* Is this any different from line 15? The video is not clear.
  int fib1 = fibonacci(n-1);
  int fib2 = fibonacci(n-2);
  return fib1 + fib2;
  */

  return fibonacci(n-1)+fibonacci(n-2);
}

int main() {
  cout << fibonacci(10) << endl;
  return 0;
}
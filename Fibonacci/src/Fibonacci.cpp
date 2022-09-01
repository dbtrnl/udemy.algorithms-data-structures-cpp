#include <bits/stdc++.h>
#include <chrono>
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
  /* 
    Source - https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
    At 5. Using chrono::high_resolution_clock in C++.
   */
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);

  cout << fibonacci(43) << endl;

  auto end = chrono::high_resolution_clock::now();
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9);
    cout << " sec" << endl;

  return 0;
}
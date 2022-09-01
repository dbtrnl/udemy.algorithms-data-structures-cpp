#include <bits/stdc++.h>
#include <chrono>
#include <iostream>

using namespace std;

int fibonacci(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  /* This isn't faster.
  Runs at fib(45): 9.061590 sec and 8.789460 sec
  int fib1 = fibonacci(n-1);
  int fib2 = fibonacci(n-2);
  return fib1 + fib2;
  */
  return fibonacci(n-1)+fibonacci(n-2); // Runs at fib(45): 8.611968 sec and 8.899689 sec... Slightly faster?
}

long int fibonacciTail(long int n, long int a, long int b) {
    if(n==0) return a;
    if(n==1) return b;
    return fibonacciTail(n-1,b,a+b);
}

int main() {
  /* 
    Source - https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
    At 5. Using chrono::high_resolution_clock in C++.
   */
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);

  cout << fibonacciTail(5000, 0, 1) << endl;

  auto end = chrono::high_resolution_clock::now();
    double time_taken = 
      chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  
    time_taken *= 1e-9;
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9);
    cout << " sec" << endl;

  return 0;
}
### General C++ stuff
`g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src/Factorial.o" "src/Factorial.cpp"`

Incremental build (executed by the instructors Eclipse)

Then `g++ -o Factorial "src/Factorial.o"` or `g++ src/Factorial.o -o build/Factorial`

To compile and run *NQueensProblem*: `g++ src/main.cpp src/NQueensProblem.h src/NQueensProblem.cpp -o build/main && ./build/main`

### Video 6
What is the problem with head recursion?
- It may use too many frames in the stack (stack overflow)
- The function is called until the base case is hit. Then it returns the result of each function call
- It uses twice as much memory as an *iterative* approach
- Tail recursion can avoid stackoverflow, because there is always only one function call on the stack

### Video 24 - Coloring problem introduction
It's again an **NP-complete** problem.

*Approaches to solve this problem:*
1 - Greedy: finds a solution, but not necessarily the best one (with least colors) **not covered**;
2 - Backtracking: discard and reject multiple bad states with a single iteration;
3 - Powell-Welsh algorithm - relies on sorting the nodes based on the degree (number of edges) **not covered**.


### Video 27 - Knight's tour problem introduction
Knight's tour problem has `O(2^3^(n*n))` (exponential) running time complexity.
But it can be solved in `O(n)` (linear) using divide-and-conquer approach (not covered in this course).

For `M x N` chessboard, closed knight tour is always feasible unless:
- *M* and *N* are both odds;
- *M* = 1, 2 or 4;
- *M* = 3 AND *N* = 4, 6 or 8.

### Video 33 - Knapsack problem introduction
**Divisible knapsack problem**
  - Greedy approach can be used > sort items according to values O(n log n) then take as much as possible of the most valuable item;
  - Overall time complexity is O(n log^n) + O(n) = O(n log n).
**0-1 knapsack problem** (item is or isn't included)
  - Brute force approach is O(2^n);
  - Greedy algorithm will not provide the optimal result;
  - Dynamic programming can optimize this problem (More info on the slides);
    - Running time is O(nM) > pseudo-polynomial time.


### Fibonacci benchmark

With head recursion:

`fib(43) = 3.528755 sec`
`fib(44) = 5.643611 sec`
`fib(45) = 8.301543 sec`

---

With tail recursion:

`fibonacciTail(45) = 0.000039 sec`
`fibonacciTail(450) = 0.000047 sec`
`fibonacciTail(45000) = 0.000921 sec`
`fibonacciTail(99990) = 0.001971 sec`

Values greater than dump the core (changing fibonacciTail to double does nothing).
Values much lower are already overflowing (such as `fib(5000)`)

---

`fib(5000) with int = -1846256875`
`fib(5000) with long int = 535601498209671957`
`fib(5000) with double = inf` (wtf)

But in reality is a 1045 digit number (source: https://zeptomath.com/tools/fibonaccinumbers.php?number=5000&hl=en)

---

## Makefiles

to run, just type `make` and to clean, `make clean`
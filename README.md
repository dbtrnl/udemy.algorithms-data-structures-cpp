## General C++ stuff
`g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src/Factorial.o" "src/Factorial.cpp"`

Incremental build (executed by the instructors Eclipse)

Then `g++ -o Factorial "src/Factorial.o"` or `g++ src/Factorial.o -o build/Factorial`

To compile and run *NQueensProblem*: `g++ src/main.cpp src/NQueensProblem.h src/NQueensProblem.cpp -o build/main && ./build/main`

---

## Notes about the videos:

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

### Video 38 - What are array data structures?
  - Array is contiguous in memory. So any item can be accessed in O(1) by it's index. *Random access*
  - Array beginning in 0x100 > index 1 = 0x116 > index 2 = 0x132, and so on... (with 4 bytes = 32 bits = 16 in hex)
  - **Memory address = array's address + (index * data size)**
  - A Matrix also has O(1) access time.

### Video 39 - Array introduction - operations
*1. Adding items*
  - Memory and running time trade-off also apply;
  - Using a huge array wastes memory, but saves time, as it doesn't need to be resized;
  - Resizing an array due to lack of space consumes O(n) time.

*2. Adding numbers to arbitrary positions*
  - Has worst-case execution time of O(n), as items need to be shifted.

*3. Removing last item*
  - O(1) running time.

*4. Removing item from arbitrary position;*
  - Need to remove item and then deal with the "hole" in the data structure;
  - Execution time of O(n) to find item, then O(1) to remove then O(n) to shift all items.

Disadvantage: Size of array must be known at compile time.

---

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
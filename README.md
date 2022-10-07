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

### Video 41/42 - What are linked lists?/Linked list theory - operations
  - There are no holes in a linked list, because every node stores data + reference to next node;
  - No random indexing, as numbers aren't stored next to each other in memory;
  - Base structure for stacks and queues;
  - Insertion/removal to beginning (head node) is O(1);
  - Insertion/removal to arbitrary/end node is O(n);
  *Advantages*
    - They are **dynamic data structures** - they can acquire memory at runtime by inserting new nodes;
    - No need to resize the data structure (like in arrays);
    - The size of the structure can be unknown at runtime;
    - Can store different sized items (unlike arrays);
  *Disadvantages*
    - Needs more memory (references to head/next nodes);
    - No random access (only head node is easily accessible);
    - Can't go backwards (previous node is unknown);
    - **not predictable** > application runtime depends on the operations done by the users;
    - The problem remains: "how to search for arbitrary items faster than O(n)?".

### Stacks - Videos 46 - 51
- It's an *abstract data type* that can be implemented with arrays or linked lists;
- Basic operations are `pop()`, `push()` and `peek()`
- Most modern languages are stack-oriented;
Applications:
  - graph algorithms (depth-first search);
  - finding Eulerian cycles in a G(V,E) graph;
  - finding strongly connected components in a given G(V,E) graph.

**Stack memory x Heap memory**
Stack > small, fast, stores function calls and local variables, not fragmented;
Heap > larger, slower, stores objects and can become fragmented.

### Queues - Videos 52, 53
- Useful when a resource is shared with several consumers (i.e. threads);
- Important in CPU scheduling;
- Important when data is transfered asynchronously between two processes;
- *breadth-first search* algorithm uses queues.

### Arrays x Linked Lists
Search                  = A > O(1)  / LL > O(n)
Insert at the start     = A > O(n)  / LL > O(1)
Insert at the end       = A > O(1)  / LL > O(n)
Wasted space            = A > 0     / LL > O(n)
Search Arbitrary item   = both O(n)

- Searching for arbitrary item on arrays/linked lists takes O(N)
**What if the array is sorted?**
- Search for arbitrary item can take O(logN) time complexity;
**Trees**
  - Is a G(Vertices,Edges) undirected graph in which any two vertices are connected by exactly one path or
    equivalently *a conected acyclic undirected graph*
  - Tree nodes can have more than 2 children

### Binary search trees
Running times:
Space complexity > O(N) avg / O(N) worst
Insertion > O(logN) avg / O(N) worst
Deletion > O(logN) avg / O(N) worst
Search > O(logN) avg / O(N) worst

- Each node can have at most 2 children;
- The left child is smaller than the parent node;
- THe right child is greater than the parent node;
  *Height of a tree* - number of edges on the longest downward path between the ROOT and a LEAF NODE.
    The number of layers the tree contains.
    Layer H will have 2^h-1 nodes
    *How many N nodes are there in a complete binary search tree with H height?*
    2^h-1 = N;
    log2^(2^h-1) = log2^N; <!-- Apply log2 to both sides -->
    h = log2^N+1;
    h = O(logN); This is important because only when the tree is balanced the running time is O(logN);
  - Unbalanced tree can even have a running time of O(N) (best case);
  - Balanced tree will always have a running time of O(logN);
*Tree traversal* > pre-order, post-order and in-order
  - Pre-order > visit the root node then the left subtree recursively, then the right subtree recursively;
  - Post-order > visit the left subtree recursively, then the right subtree recursively, then the root node;
  - In-order > visit the left subtree of the binary tree then the root node then the right subtree in a recursive manner;
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
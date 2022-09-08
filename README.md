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
### General C++ stuff
`g++ -O0 -g3 -Wall -c -fmessage-length=0 -o "src/Factorial.o" "src/Factorial.cpp"`

Incremental build (executed by the instructors Eclipse)

Then `g++ -o Factorial "src/Factorial.o"` or `g++ src/Factorial.o -o build/Factorial`

### Video 6
What is the problem with head recursion?
- It may use too many frames in the stack (stack overflow)
- The function is called until the base case is hit. Then it returns the result of each function call
- It uses twice as much memory as an *iterative* approach
- Tail recursion can avoid stackoverflow, because there is always only one function call on the stack
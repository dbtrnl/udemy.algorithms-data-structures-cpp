### Video 6
What is the problem with head recursion?
- It may use too many frames in the stack (stack overflow)
- The function is called until the base case is hit. Then it returns the result of each function call
- It uses twice as much memory as an *iterative* approach
- Tail recursion can avoid stackoverflow
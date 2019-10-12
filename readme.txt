Compile normally (only STL library used) :

g++ JumpingJim.cpp


Program expects to read input from a file named "input.txt"
First two parameters in the file should be the number of rows then the number of columns. After that, the value of every trampoline should be place in order. For the original problem, the input.txt would look like:

7 7
3 6 4 3 2 4 3
2 1 2 3 2 5 2
2 3 4 3 4 2 3
2 4 4 3 4 2 2
4 5 1 3 2 5 4
4 3 2 2 4 5 6
2 5 2 5 6 1 0


Program will only see the first node as the starting node and last node as the exit. Adjustments can very easily be made to change the starting and exit position to any node.
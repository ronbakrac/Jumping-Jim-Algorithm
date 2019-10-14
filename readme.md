# Description of Problem
This problem is based on the “Jumping Jim” maze problem (from “MAD MAZES: Intriguing Mind Twisters for Puzzle Buffs, Game Nuts and Other Smart People” by Robert Abbott). The text of the problem is quoted below. 

“A diagram of the maze is provided separately. Jumping Jim is about to begin his grand performance at the circus, but his jealous enemy, Dastardly Dan, has restrung all the trampolines. The number on each trampoline indicates how tightly strung each one is; in other words, the number indicates how far Jim will have to move (horizontally or vertically, but NOT diagonally) when he bounces off the trampoline. Jim begins his routine by leaping onto the trampoline at the upper left. He must get to the Goal at the lower right, where he will take his bow. How can he get there? The diagram shows all of the trampolines with each represented as a square. Begin on the square at the upper left. That square is marked 3. From there you could, for example, move three squares down to a square marked 2. From there, you might move two squares right to a square marked 4, and from there you could move four squares right to another square marked 2. That path, incidentally, won’t get you to the goal.” 

<img src



# Program Inputs/Outputs
Program expects to read input from a file named _"input.txt"_
The contents of this input should follow the following:
* Number of row (r)
* Number of columns (c)
* r*c matrix of trampoline values

For the original problem, the input.txt would look like


<br>`7 7`</br>
`3 6 4 3 2 4 3`
<br>`2 1 2 3 2 5 2`</br> 
`2 3 4 3 4 2 3`
<br>`2 4 4 3 4 2 2`</br> 
`4 5 1 3 2 5 4`
<br>`4 3 2 2 4 5 6`</br> 
`2 5 2 5 6 1 0`



Program will only see the <strong>first</strong> node as the starting node and <strong>last</strong> node as the exit. Adjustments can very easily be made to change the starting and exit position to any node.

The program will output the directions needed to reach exit by pasting cardinal directions in a document _"output.txt"_.
# How to Compile
`g++ JumpingJim.cpp`

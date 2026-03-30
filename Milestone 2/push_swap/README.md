*This project has been created as part of the 42 curriculum by kzhu.*

# Push_swap

## Description

The goal was to build a complex algorithm to arrange disordered array of numbers on one stack, with the help with the secondary empty stack and a set of given mechanical operations. While sorting the numbers in ascending order on stack A, trying to have the absolute minumum moves as possible.

Before even start sorting the stacks, the project also requires a parser to defend against invalid input (non-integers, duplicates, overflows) while ensuring absolutely 0 memory leaks.

## Instructions

There're different approaches for this project, the algorithm i've chosen is Turk Algorithm, reccommanded by Yogun from 42-Heibronn. As after watching few algorithmn videos online, i found myself understanding this approach better than others.

The logic map for this algorithm:
1. Build stack B: push all but 3 numbers left from stack A to stack B, then sort the remaning 3 numbers in Stack A, so it works as an anchor.
2. Mark the target: go through all the numbers that are existing in stack B, and assign them the closest bigger number from A (if its the max number then it should sit on top of the minumum number), that will mark the destination where numbers in stack B later would be placed.
3. Caculate the price: with the target nodes marked, it is possible to caculate the cost of arranging each nodes, and we mark out the cheapest one.
4. Optimiztion: to be able to reduce the moves, we utilised the function 'rr' and 'rrr' while the node on stack B and the target node on stack A are on the same side of the stack (above or below median).
5. Execution: find the one with absolute cheapest cost, execute the calculated rotations, when both desire nodes are on the top of the stacks, we do the push from B to A until B is empty, then we align stack A to make sure the minimum number goes om top.

To compile the project, run the following command at the root of the repository:
make
./push_swap "where you insert your random numbers array"

## Resources & AI Usage

1. push_swap TUTORIAL! https://www.youtube.com/watch?v=wRvipSG4Mmk
I watched this video to have a general understanding on this project, and have a basic knowledge on how the Turk algorithm works.
2. Push Swap — A journey to find most efficient sorting algorithm https://medium.com/@ayogun/push-swap-c1f5d2d41e97
I read this article from the algorithm himself to have a deeper understanding how this approach would work.

AI Usage:
Gemini was used as an interactive tutor and debugging assistant throughout this project:
Identify and explain complex C double-pointer traps and Segmentation Faults.
Assist in refactoring mathematical cost-calculation functions to comply strictly with the 42 Norminette (maximum 25 lines per function).
Help visualize and map out the overall flow of the sorting logic.
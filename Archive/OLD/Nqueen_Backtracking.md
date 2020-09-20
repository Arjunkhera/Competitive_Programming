Task : Find positions on a chess board such that no queen can attack each other
Type : Backtracking Algorithm
Running Time : Exponential  
Data Structure used : 2d Array

Pseudocode :
```
1.Start in the leftmost column
2.If all queens are placed
    return true
3.Try all rows in the current column.  Do following for every tried row.
    a) If the queen can be placed safely in this row then mark this [row,
        column] as part of the solution and recursively check if placing  
        queen here leads to a solution.
    b) If placing queen in [row, column] leads to a solution then return
        true.
    c) If placing queen doesn't lead to a solution then umark this [row,
        column] (Backtrack) and go to step (a) to try other rows.
4.If all rows have been tried and nothing worked, return false to trigger
    backtracking.
```

1. [youtube : Tushar Roy](https://youtu.be/xouin83ebxE)
2. [Wikipedia](https://en.wikipedia.org/wiki/Eight_queens_puzzle)
3. [In Depth stanford handout](https://see.stanford.edu/materials/icspacs106b/H19-RecBacktrackExamples.pdf)
4. [Geeksforgeeks](http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/)

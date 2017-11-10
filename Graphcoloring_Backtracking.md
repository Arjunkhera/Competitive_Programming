Task : Color vertices of a graph such that no two adjacent vertices have the same color
Type : Backtracking Algorithm
Running Time : Exponential  
Data Structure used : 2d Array

Pseudocode :
```
1.Number the solution variables [v0 v1, …, vn-1].

2.Number the possible values for each variable [c0 c1, …, ck-1].

3.Start by assigning c0 to each vi.

4.If we have an acceptable solution, stop.

5.If the current solution is not acceptable, let i = n-1.

6.If i < 0, stop and signal that no solution is possible.

7.Let j be the index such that vi = cj. If j < k-1, assign cj+1 to vi and go back to step 4.

8.But if j ≥ k-1, assign c0 to vi, decrement i, and go back to step 6.

```

1. [youtube : Saurabh School](https://www.youtube.com/watch?v=Cl3A_9hokjU)
2. [Wikipedia](https://en.wikipedia.org/wiki/Graph_coloring)
3. [Extra](https://secweb.cs.odu.edu/~zeil/cs361/web/website/Lectures/npprobs/pages/ar01s01s01.html)
4. [Geeksforgeeks](http://www.geeksforgeeks.org/backttracking-set-5-m-coloring-problem/)

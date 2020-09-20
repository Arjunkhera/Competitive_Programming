Task : Find solution for 0/1 knapsack
Type : Branch and Bound
Running Time :  
Data Structure used : 2d array

Pseudocode :
```
ALGORITHM BestFirstBranchAndBound (Weights [1 … N], Values [1 … N)
// Input: Array Weights contains the values of all items
Array Values contains the values of all items
// Output: An array that contains the best solution and its MaxValue
// Precondition: The items are sorted according to their value-to-weight ratios
PriorityQueue<nodeType> PQ
nodeType current, temp
Initialize the root
PQ.enqueue(the root)
MaxValue = value(root)
while(PQ is not empty)
current = PQ.GetMax()
if (current.nodeBound > MaxValue)
Set the left child of the current node to include the next item
8
if (the left child has value greater than MaxValue) then
MaxValue = value (left child)
Update Best Solution
if (left child bound better than MaxValue)
PQ.enqueue(left child)
Set the right child of the current node not to include the next item
if (right child bound better than MaxValue)
PQ.enqueue(right child)
return the best solution and it’s maximum value
```

1. [youtube : Tushar Roy]()
2. [Wikipedia]()
3. [Various 0/1 solutions](http://www.micsymposium.org/mics_2005/papers/paper102.pdf)
4. [Geeksforgeeks](http://www.geeksforgeeks.org/branch-and-bound-set-1-introduction-with-01-knapsack/)

### Trivia : thoughts on dfs and backtracking

[stackoverflow 1](https://stackoverflow.com/questions/1294720/whats-the-difference-between-backtracking-and-depth-first-search)

For me, the difference between backtracking and DFS is that backtracking handles an implicit tree and DFS deals with an explicit one. This seems trivial, but it means a lot. When the search space of a problem is visited by backtracking, the implicit tree gets traversed and pruned in the middle of it. Yet for DFS, the tree/graph it deals with is explicitly constructed and unacceptable cases have already been thrown, i.e. pruned, away before any search is done.

So, backtracking is DFS for implicit tree, while DFS is backtracking without pruning.

[stackoverflow 2](https://stackoverflow.com/questions/2709030/explain-bfs-and-dfs-in-terms-of-backtracking/3156208#3156208)


1. [Combination Sum](https://leetcode.com/problems/combination-sum/description/)
  - backtracking O(2^n)
  - dp O()

2. [Combination Sum 2](https://leetcode.com/problems/combination-sum-ii/description/)
  - same as above
3. [Combination Sum 3](https://leetcode.com/problems/combination-sum-iii/description/)
  - same as above
4. [Combinations](https://leetcode.com/problems/combinations/description/)
  - same as letter number or generate permutations

5. [generate parenthesis](https://leetcode.com/problems/generate-parentheses/description/)
  -
6. [gray code](https://leetcode.com/problems/gray-code/description/)
  - [iterative solution : just magical ](http://www.drdobbs.com/architecture-and-design/logic-101-gray-codes/196604129)
  - [backtracking]()
  though both have same run times

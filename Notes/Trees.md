### Common Terminology ?



### Applications of Tree's ?

1. Manipulate hierarchical data.
2. Make information easy to search (see tree traversal).
3. Manipulate sorted lists of data.
4. As a workflow for compositing digital images for visual effects.
5. Router algorithms
6. Form of a multi-stage decision-making (see business chess).


### Good Reads
1. [Light intro](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Trees/trees.html)
2. [All in one : a heavy read](http://liacs.leidenuniv.nl/~deutzah/DS/september28.pdf)

### Questions :

1. [Inorder traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)
  - iterative O(n),O(n) using stacks  
  - recursive O(n),O(n)
  - morris traversal O(n),O(1) [gfg](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/)
  - **The above three can be made to work for pre and post order traversal also**
  - some useful reads [threaded tree](https://en.wikipedia.org/wiki/Threaded_binary_tree)
2. [Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
  - using queue O(n),O(level with max nodes)
3. [Zig Zag level order ](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)
  - using two stacks
  - using a deque
4. [Maximum Depth of Tree][https://leetcode.com/problems/maximum-depth-of-binary-tree/description/]
  - Just remember to check whether they are asking for nodes or edges !
5. [Same tree](https://leetcode.com/problems/same-tree/description/)
6. [Symmetric tree](https://leetcode.com/problems/symmetric-tree/)
  - know both iterative(awesome solution) and recursive solutions
7. [Construct binary tree from inorder and preorder](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
  - good question, try to understand both the iterative and recursive versions
8. [Construct binary tree from inorder and postorder](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/)
  - extremely similar to the above question
9. [making next level pointers ](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/)  
  - just a small change to levelorder traversal, but does not use constant space
10. [making next level pointers  2](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/)
 - same as above, only here the tree is not perfect, but levelorder solution works for all cases
 - the iterative solution uses O(1) space, keep that in mind for an optimised solution
11. [Invert Binary tree](https://leetcode.com/problems/invert-binary-tree/description/)
  - works on the same principle as mirror image
12. [Path sum](https://leetcode.com/problems/path-sum/description/)
  - simple recursion
13. [Path sum 2](https://leetcode.com/problems/path-sum-ii/description/)
  - just a mix of backtracking, remember to pass by reference
14. [Min depth](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)
  - simple recursion, just take care of the edge cases
15. [balanced binary tree](https://leetcode.com/problems/balanced-binary-tree/description/)
  - top down is O(n^2)
  - bottom up is O(n) similar to the fast diameter method
16. [flatten btree to linked list](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)
  - just a small nice change to morris traversal,and it works beautifully
17. [Least common ancestor](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)
  - using path calculation in vector O(n)
  - using bottom up recursion O(n)
18. [Least common ancestor of bst]()

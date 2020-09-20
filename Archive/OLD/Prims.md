Task : Find minimum spanning tree  
Type : Greedy Algorithm
Running Time : O(Elog(E))  
Data Structure used : Priority Queue

Pseudocode :
```
Make a queue (Q) with all the vertices of G (V);
  For each member of Q set the priority to INFINITY;
  Only for the starting vertex (s) set the priority to 0;
  The parent of (s) should be NULL;
  While Q isn’t empty
     Get the minimum from Q – let’s say (u); (priority queue);
     For each adjacent vertex to (v) to (u)
        If (v) is in Q and weight of (u, v) < priority of (v) then
           The parent of (v) is set to be (u)
           The priority of (v) is the weight of (u, v)
```

1. [youtube : Tushar Roy](https://youtu.be/oP2-8ysT3QQ)
2. [Wikipedia](https://en.wikipedia.org/wiki/Prim%27s_algorithm)
3. [All in one](https://www-m9.ma.tum.de/graph-algorithms/mst-prim/index_en.html)
4. [Stoimen](http://www.stoimen.com/blog/2012/11/19/computer-algorithms-prims-minimum-spanning-tree/)
5. [Geeksforgeeks](http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/)

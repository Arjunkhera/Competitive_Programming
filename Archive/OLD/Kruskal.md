Task : Find minimum spanning tree  
Type : Greedy Algorithm
Running Time : O(Elog(E))  
Data Structure used : Disjoint Sets

Pseudocode :
```
KRUSKAL(G):
1 A = ∅
2 foreach v ∈ G.V:
3    MAKE-SET(v)
4 foreach (u, v) in G.E ordered by weight(u, v), increasing:
5    if FIND-SET(u) ≠ FIND-SET(v):
6       A = A ∪ {(u, v)}
7       UNION(u, v)
8 return A
```

1. [youtube : Tushar Roy](https://youtu.be/fAuF0EuZVCk)
2. [Wikipedia](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)
3. [All in one](https://www-m9.ma.tum.de/graph-algorithms/mst-kruskal/index_en.html)
4. [Geeksforgeeks](https://www-m9.ma.tum.de/graph-algorithms/mst-kruskal/index_en.html)

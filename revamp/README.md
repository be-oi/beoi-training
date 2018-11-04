# Revamped modules proposal
A *unit* is the material for one lesson.
A *module* is a set of two related units, one for Saturday and one for Sunday.
Modules are separated in three different categories\: basic, intermediate and advanced.

## Basic 
Basic modules don't have any algorithmic prerequisites and the idea is to constantly rotate them, so that newcomers can just join seamlessly and follow 3 consecutive camps.

* STL usage (not internal workings)
  1. data structures: vector/queue/stack/deque, priority_queue/set/map
  2. algorithms: iterators, find, binary\_search, reverse/sort/nth\_element/reverse/next_permutation, min/max, probably others
* Graphs 1
  1. graph representation (in a practical and not mathematical fashion, code is mandatory, explain how to transform from one representation to the other is very useful too), bfs (because it's the simplest algorithm that solves a practical problem newcomers probably are aware of), dfs (traversal, connected components, flood fill)
  2. Dijkstra, Floyd-Warshall (applications are fine but please no formal proof that it works)
* Recursion and Dynamic Programming 1
  1. Recursive backtracking (with a decent example problem, IMO knapsack is perfect)
  2. From backtracking to top-down DP (knapsack, coin change at least) + explain classes of algorithms (bf, dp, greedy, d&c)

## Slightly advanced modules

* Brute force techniques and divide and conquer (rationale: binary search often doesn't come alone)
  1. Brute force techniques, basic binary search (powers of 2), implementation tricks (all subsets, |^~&<<>> operators, difference between &/| and &&/|| for boolean operands)
  2. BSTA, D&C (merge sort mostly), **gdb usage**
* UnionFind and graphs 2
  1. UnionFind (explaining rank heuristic because it can be useful (\*beCP\*))
  2. MST and various algorithms: trees, toposort, Kosaraju SCCs
* Range operations
  1. Simple static: prefix sums, two pointers, sliding min/max (stack/deque) and sliding window (fixed query size)
  2. Range static/dynamic: segment trees 1 (building, range query, point update, range update/point query, lazy)
* Dynamic Programming 2
  1. Bottom up, bitmask (TSP), drop one parameter, probably a few others
  2. Reduce amount of states to further optimize, data structures (segment trees)
* (debatable) Treaps
  1. BST and heap internal workings, BBST implementation with treaps
  2. More operations (index, range operations), implicit treaps

## Advanced (incomplete)

* Segment tree 2 and 3
  * Segment tree 2: Monoids, iterative segment trees
  * Segment tree 3: Persistent, 2D, merge sort trees
* Dynamic programming 3: optimizations, optimizations everywhere
* Others

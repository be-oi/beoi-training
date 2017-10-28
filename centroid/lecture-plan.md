# Centroid decomposition: lecture plan
(based on Algorithms Live: http://algorithms-live.blogspot.be/2017/03/episode-12-divide-and-conquer-on-trees.html)

For each step, try and make the students find the key elements on their own (some of them should be able to)

- Introduce simplified version of Yin-Yang paths (http://www.usaco.org/index.php?page=viewproblem2&cpid=286, *without rest stops*), draw a reasonably-sized example graph to support the argument (you can use `in1` to get a good one).
- Brainstorm ideas.
- Consider how to check efficiently whether a path (i,j) forms a balanced path: count the number of black and white edges, use LCA and sparse table to get O(n^2) in total.
- Study the problem of counting those paths that go through the root, introduce the concept of balance (e.g. +1 for black, -1 for white), and see how opposite balances form balanced paths.
- Discuss potential overcounting problems using the most naive approach (nodes within a subtree). Multiple possible solutions, including counting at root then removing at its children.
- Live-code the solution to this restricted problem, using an occurrence vector that keeps the occurrence of each previous root child (+ the root itself with balance 0), and adding to the occurrence vector only after you've done the counting for the current child. Use pointer magic to handle negative indices (see code attached, ignore the centroid decomposition part). Test it on your example tree (it should be 11).

- Show why we can't do this at every level to get the full answer. Draw a graph with a long path that gives O(n^2).
  - Someone might suggest some kind of heavy-light decomposition (maintain occurrence vectors at every level, merging small children into large ones). This should indeed work if done right, but likely a bit more tricky to implement (in particular because of the negative indices). Kindly ask them to listen anyway.
  - When choosing a suitable root, someone might suggest taking the longest path and cutting it in two (taking the center). This is O(n\*sqrt(n)) (thanks Arthur for the example): consider a star-shaped graph with paths of length 1,3,5,...,k going out of a central node (the graph then has k^2+1 nodes). The heuristic will repeatedly cut off the largest branch right next to the central node, which will give O(k^3) = O(n\*sqrt(n)).
- Show that we would like to divide the tree into parts of equal size, by taking the merge sort analogy, (O(log n) levels, O(n) at each level).
- Introduce the concept of centroid (min max size of subtree), show that this max size is <= floor(n/2).
- Conclude that if we choose it every time it's good. Explain again why every path is counted exactly once with this method.
- Live-code this by modifying the previous code. Look up the `centroid()` method beforehand. Code it by first just using it for the size then later modifying it to find the centroid (to make it clear how it's used to spare some code).
  - Test it on your example tree (it should be 16). Do a live-debug because that'll be necessary.

- Give the full Yin-Yang Paths problem as an exercise. A bit complicated maybe. Give them the code because otherwise they'll have significant trouble but insist that they don't just copy-paste it and try to rebuild it by themselves.

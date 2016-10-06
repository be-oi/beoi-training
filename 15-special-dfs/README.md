# Unit 15: Specialized DFS
This unit covers some extensions to DFS and the problems they solve:
- Opened/closed node states
- Edge types (tree, back, cross)
- Cycle check
- Node timestamps and visibility (`dfs_num` and `dfs_low`)
- Bridges
- Articulation points

Tarjan's SCC algorithm was left out for the time being because it is more complex and difficult to remember than Kosaraju's.

## Prerequisites
- Unit 6: [Graph basics](../06-graph-basics)
- Unit 14: [Graph traversal](../14-traversal)

## Practice problems

### Basic
- UVa 315 - [Network](https://uva.onlinejudge.org/external/3/315.pdf) (articulation points)
- UVa 796 - [Critical Links](https://uva.onlinejudge.org/external/7/796.pdf) (bridges, assume `N <= 10000`, input tricky, don't hesitate to ask for help!)

### Variants
- UVa 610 - [Street Directions](https://uva.onlinejudge.org/external/6/610.pdf) (very interesting!)
- UVa 10765 - [Doves and Bombs](https://uva.onlinejudge.org/external/107/10765.pdf)

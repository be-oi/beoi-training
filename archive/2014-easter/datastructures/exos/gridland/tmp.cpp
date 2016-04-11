#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define MAX_Q 1000000

int n, m, q;
char types[MAX_Q];
int x1[MAX_Q];
int y_1[MAX_Q];
int x2[MAX_Q];
int y2[MAX_Q];

bool grid[MAX_N][MAX_N]; // initialized at 0 !
class UnionFind {
  int rank[MAX_N*MAX_N];
  int leader[MAX_N*MAX_N];
  public:
  UnionFind(int n) {
    memset(rank, 0, n * sizeof(int));
    for(int i = 0; i < n; i++) leader[i] = i;
  }
  int find(int a) {
    if(a != leader[a])
      leader[a] = find(leader[a]);
    return leader[a];
  }
  void do_union(int a, int b) {
    int leaderA = find(a);
    int leaderB = find(b);
    if(leaderA == leaderB) return;
    if(rank[leaderA] > rank[leaderB]) {
      do_union(leaderB, leaderA); return;
    }
    leader[leaderA] = leaderB;
    if (rank[leaderA] == rank[leaderB])
      rank[leaderB]++;
  }
};

void gridland() {
}

int main () {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < q; i++) {
    while ((types[i] = getchar()) != 'a' && types[i] != 'c');
    scanf("%d %d", &x1[i], &y_1[i]);
    if (types[i] == 'c') {
      scanf("%d %d", &x2[i], &y2[i]);
    }
  }
  gridland();
}

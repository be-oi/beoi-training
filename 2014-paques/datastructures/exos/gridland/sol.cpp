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
  int *rank;
  int *leader;
  public:
  UnionFind(int n) {
    rank = new int[n];
    leader = new int[n];
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

#define MAP(x, y) x*m+y
int deltas[4][2] = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1}
};
void gridland() {
  UnionFind uf(n*m);
  for (int k = 0; k < q; k++) {
    x1[k]--;
    y_1[k]--;
    x2[k]--;
    y2[k]--;
    if (types[k] == 'c') {
      int a = MAP(x1[k], y_1[k]);
      int b = MAP(x2[k], y2[k]);
      printf("%d\n", uf.find(a) == uf.find(b) ? 1 : 0);
    } else {
      int x = x1[k], y = y_1[k];
      if (!grid[x][y]) {
        grid[x][y] = true;
        for (int i = 0; i < 4; i++) {
          int xa = x+deltas[i][0], ya = y+deltas[i][1];
          if (xa >= 0 && xa < n && ya >= 0 && ya < m && grid[xa][ya]) {
            uf.do_union(MAP(xa, ya), MAP(x, y));
          }
        }
      }
    }
    /*fprintf(stderr, "|--------------\n");
    for (int i = 0; i < n; i++) {
      fprintf(stderr, "|");
      for (int j = 0; j < m; j++) {
        fprintf(stderr, "%2d%c", grid[i][j], j+1 == m ? '\n' : ' ');
      }
    }
    fprintf(stderr, "|--------------\n");
    for (int i = 0; i < n; i++) {
      fprintf(stderr, "|");
      for (int j = 0; j < m; j++) {
        fprintf(stderr, "%2d%c", uf->find(MAP(i, j)), j+1 == m ? '\n' : ' ');
      }
    }
    fprintf(stderr, "|--------------\n");*/
  }
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

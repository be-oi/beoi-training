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

int main () {
  int n = 1, m = 1, q = 10;
  srand(time(NULL));
  printf("%d %d %d\n", n, m, q);
  for (int i = 0; i < q; i++) {
    if (rand() % 2 == 0) {
      int xa = rand() % n; xa++;
      int ya = rand() % m; ya++;
      int xb = rand() % n; xb++;
      int yb = rand() % m; yb++;
      printf("c %d %d %d %d\n", xa, ya, xb, yb);
    } else {
      int xa = rand() % n; xa++;
      int ya = rand() % m; ya++;
      printf("a %d %d\n", xa, ya);
    }
  }
}

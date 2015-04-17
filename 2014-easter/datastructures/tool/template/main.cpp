#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <iostream>
#include <string.h>
#include <utility>
#include <algorithm>

using namespace std;

//#define debug
#ifdef debug
#include <assert.h>
#else
#define assert(s)
#endif

#define FORO(i, n) FOROS((i), 0, (n))
#define FOROS(i, a, n) for ((i) = (a); (i) < (n); ++(i))
#define FOR(i, n) FORIS((i), 0, (n))
#define FORS(i, a, n) for (int (i) = (a); (i) < (n); ++(i))

#define G(n) cin >> n
#define D(n) cout << #n << " = " << n << endl
#define P(n) cout << n << endl
#define PESP(a, i, n) cout << a << (i + 1 == n ? '\n' : ' ');

#define loo long long int

int main () {
}

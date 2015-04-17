#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int main()
{
    int n = 100000;
    cout << 1 << endl << n << endl;
    for (int i=0; i<n; i++)
    {
        double d = rand()-1000000000;
        d /= 10000000;
        if (i != 0)
            cout << ' ';
        cout << exp(d);
    }
    cout << endl;
}

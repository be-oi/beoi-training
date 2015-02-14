#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    int n,k;
    while (cin >> n >> k, n || k)
    {
        int kp = (2*k > n)?(n-k):k;
        ll c = 1;
        for (int i=1; i<=k; i++)
        {
            c *= n-k+i;
            c /= i;
        }
        printf("%d things taken %d at a time is %lld exactly.\n", n, k, c);
    }
}

#include <iostream>

#define MAXN 7500

using namespace std;
typedef long long ll;

int ncoins=5;
ll coin[5] = {1,5,10,25,50};
ll ways[6][MAXN];

int main()
{
    ways[0][0] = 1;
    for (int i=1; i<MAXN; i++)
    {
        ways[0][i] = 0;
    }
    for (int i=0; i<ncoins; i++)
    {
        for (int j=0; j<MAXN; j++)
        {
            for (int k=0; j+k*coin[i] < MAXN; k++)
            {
                ways[i+1][j+k*coin[i]] += ways[i][j];
            }
        }
    }
    int n;
    while(cin >> n)
    {
        cout << ways[ncoins][n] << endl;
    }
}

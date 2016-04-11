#include<bits/stdc++.h>
using namespace std;

#define MAX_M 100
#define MAX_S MAX_M*500

int n, m, S;
int v[MAX_M];
int memo[MAX_M][MAX_S+1];

int dp(int i, int money1) {
    if(i == m)
        return abs(S - 2*money1);
    if(memo[i][money1] != -1)
        return memo[i][money1];
    return memo[i][money1] = min(dp(i+1, money1 + v[i]), dp(i+1, money1));
}

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &m);
        S = 0;
        for(int i = 0; i < m; ++i) {
            scanf("%d", &v[i]);
            S += v[i];
        }

        for(int i = 0; i < m; ++i)
            for(int j = 0; j <= S; ++j)
                memo[i][j] = -1;
        
        printf("%d\n", dp(0, 0));
    }
}


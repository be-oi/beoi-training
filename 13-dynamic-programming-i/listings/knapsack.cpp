int C, n;
int w[n], v[n];
int memo[n][C];

int solve(int i, int wtaken) {
    if(i == n) {
        // we cannot take any object anymore
        return 0; 
    } else if(wtaken > C) {
        // knapsack is invalid
        return -INF;
    }

    if(memo[i][wtaken] != -1)
        return memo[i][wtaken];
    else {
        memo[i][taken] = max(solve(i+1, wtaken), v[i] + solve(i+1, wtaken - w[i]));
        return memo[i][taken];
    }
}


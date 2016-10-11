int C, n;
int w[n], v[n];
int memo[n][C];

int solve(int i, int wtaken) {
    if(wtaken > C)
        return -INF;
    else if(i == n)
        return 0;

    if(memo[i][wtaken] != -1)
        return memo[i][wtaken];
    else {
        memo[i][wtaken] = max(solve(i+1, wtaken), v[i] + solve(i+1, wtaken + w[i]));
        return memo[i][wtaken];
    }
}


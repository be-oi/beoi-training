int n, C;
int w[n], v[n];

int knapsack() {
    int best[n][C+1];

    // solve the base case (easier sub-problems)
    for(int c = 0; c <= C; ++c)
        if(c < w[0])
            best[0][c] = 0;
        else
            best[0][c] = v[0];

    // iterate in the right order and solve all sub-problems
    for(int i = 1; i < n; ++i)
        for(int c = 0; c <= C; ++c) 
            if(c < w[i])
                best[i][c] = best[i-1][c];
            else
                best[i][c] = max(best[i-1][c], v[i] + best[i-1][c - w[i]]);

    // return biggest problem
    return best[n-1][C];
}


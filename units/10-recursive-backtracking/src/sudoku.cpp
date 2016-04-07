#include <bits/stdc++.h>
using namespace std;

typedef int Grid[9][9];
bool correct(Grid& grid) {
    //Simple, but can be faster
    //Does not consider 3x3 boxes
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            for (int k = j + 1; k < 9; k++)
                if (grid[i][j] <= 0 || grid[i][j] > 9
                        || grid[i][k] <= 0 || grid[i][k] > 9
                        || grid[j][i] <= 0 || grid[j][i] > 9
                        || grid[k][i] <= 0 || grid[k][i] > 9
                        || grid[i][j] == grid[i][k]
                        || grid[j][i] == grid[k][i])
                    return false;
    return true;
}

bool solve_slow(Grid& grid, int i=0, int j=0) {
    if (i >= 9)
        return correct(grid);

    int nextj = (j + 1) % 9;
    int nexti = i + ((j + 1) / 9);

    if (grid[i][j] == 0) { //Not yet filled
        for (int val = 1; val <= 9; val++) {
            grid[i][j] = val;
            if (solve_slow(grid, nexti, nextj))
                return true;
        }
        grid[i][j] = 0;
        return false;
    } else {
        return solve_slow(grid, nexti, nextj);
    }
}

//The better way:

bool good(Grid& grid, int r, int c) {
    for (int i = 0; i < 9; i++) {
        if (i != r && grid[i][c] == grid[r][c])
            return false;
        if (i != c && grid[r][i] == grid[r][c])
            return false;
    }
    return true;
}

bool solve(Grid& grid, int i=0, int j=0) {
    if (i >= 9)
        //Check happens before going to the next cell
        //So we have found a solution
        return true;

    int nextj = (j + 1) % 9;
    int nexti = i + ((j + 1) / 9);

    if (grid[i][j] == 0) { //Not yet filled
        for (int val = 1; val <= 9; val++) {
            grid[i][j] = val;
            //Short circuiting to the rescue
            if (good(grid, i, j) && solve(grid, nexti, nextj))
                return true;
        }
        grid[i][j] = 0;
        return false;
    } else {
        return solve(grid, nexti, nextj);
    }
}

int main() {
    Grid grid = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    cout << solve(grid) << endl;
    //cout << solve_slow(grid) << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

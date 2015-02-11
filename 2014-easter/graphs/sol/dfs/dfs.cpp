#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int R,C;
string grid[1000]; // Actually 2D array of char
int startI, startJ, chocI, chocJ;
bool visited[1000][1000];
queue<pair<int,int> > path; // Log of the steps, queue to keep the order

// All four directions, as differences in i and j
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

// Returns true if it has found the chocolate
bool dfs(int i, int j)
{
    // We add the current position to the log
    path.push(make_pair(i,j));
    // Alice can only now see if she's visited this square already
    if(visited[i][j])
        return false;
    visited[i][j] = true;
    if(grid[i][j] == 'C')
        return true;

    for(int d=0; d<4; d++)
    {
        int newI = i+dir[d][0], newJ = j+dir[d][1];
        if(grid[newI][newJ] != '#')
        {
            // If it finds the chocolate, no need to search further
            if(dfs(newI, newJ))
                return true;
            // Otherwise, backtracking
            else
                path.push(make_pair(i,j));
        }
    }
}

int main()
{
    cin >> R >> C;
    for(int i=0; i<R; i++)
    {
        cin >> grid[i]; // Reads a whole word (here, the whole line)
        for(int j=0; j<C; j++)
        {
            if(grid[i][j] == 'S')
            {
                startI = i;
                startJ = j;
            }
        }
    }

    dfs(startI, startJ);

    cout << path.size()-1 << endl; // The path contains both start and end
    while(!path.empty())
    {
        pair<int,int> coord = path.front();
        cout << coord.first << " " << coord.second << endl;
        path.pop();
    }
}

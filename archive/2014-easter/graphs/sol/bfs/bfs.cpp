#include<iostream>
#include<queue>
#include<stack>

using namespace std;
// Alias type: allows using node instead of pair<int,int>
typedef pair<int,int> node;

int R,C;
string grid[1000]; // Actually 2D array of char
bool visited[1000][1000];
node parent[1000][1000]; // The "source" node
node start, choc; // Starting point and chocolate point
queue<node> q; // Waiting list
stack<node> path; // Path found, stack to reverse the order

// All four directions, as differences of i and j
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

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
                start.first = i;
                start.second = j;
            }
        }
    }

    q.push(start);
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        int i = cur.first, j = cur.second;
        if(cur == choc)
            break;
        if(visited[i][j])
            continue;
        visited[i][j] = true;

        for(int d=0; d<4; d++)
        {
            int newI = i+dir[d][0], newJ = j+dir[d][1];
            // Checking that the node has not been visited is necessary here
            // to avoid overwriting the source
            if(grid[newI][newJ] != '#' && !visited[newI][newJ])
            {
                node next(newI, newJ);
                parent[newI][newJ] = cur;
                q.push(next);
            }
        }
    }
    // Going back to retrace the path; choc iterates back to start
    while(choc != start)
    {
        path.push(choc);
        choc = parent[choc.first][choc.second];
    }
    // Let us output the size while it's correct
    cout << path.size() << endl;
    path.push(start);
    // Going back down the stack
    while(!path.empty())
    {
        cout << path.top().first << ' ' << path.top().second << endl;
        path.pop();
    }
}

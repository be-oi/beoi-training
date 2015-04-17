#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M;
int i,j,w;
// Parallel arrays:
// - neigh[i][j] is the jth neighbour of i
// - weight[i][j] is the negative weight of the corresponding edge
vector<int> neigh[100000];
vector<int> weight[100000];
bool visited[100000];
// Pairs with negative distance and node id; shortest distance at the front
priority_queue<pair<int,int> > closest;

int main()
{
    cin >> N >> M;
    for(int e=0; e<M; e++)
    {
        cin >> i >> j >> w;
        neigh[i].push_back(j);
        weight[i].push_back(-w);
        neigh[j].push_back(i);
        weight[j].push_back(-w);
    }

    closest.push(make_pair(0,0)); // Node 0 is at distance 0
    while(true)
    {
        pair<int,int> cur = closest.top();
        closest.pop();
        int dist=cur.first, i=cur.second;

        if(visited[i])
            continue;
        visited[i] = true;
        
        if(i == N-1)
        {
            cout << -dist << endl;
            return 0;
        }
        // For each neighbour
        for(int j=0; j<neigh[i].size(); j++)
            // We add the weight of the edge to the total distance
            closest.push(make_pair(dist+weight[i][j], neigh[i][j]));
    }
}

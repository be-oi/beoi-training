#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,total=0;
int parent[1001],ran[1001];
vector< pair<int, pair<int, int> > > G, M;

int find(int x,int *parent) {
    if(parent[x]!=x)
        parent[x]=find(parent[x],parent);
    return parent[x];
}

void uni(int x,int y) {
    if(ran[y]<ran[x])
        parent[y]=x;
    else
        parent[x]=y;
    if(ran[x]==ran[y])
        ran[y]++;
}

void Kruskal() {
    int x,y;
    sort(G.begin(), G.end());
    for(int i=0;i<m;i++) {
        x = find(G[i].second.first,parent);
        y = find(G[i].second.second,parent);
        if(x!=y) {
            M.push_back(G[i]);
            total += G[i].first;
            uni(x,y);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i = 0; i < n + 1; i++) {
        parent[i]=i;
        ran[i]=-1;
    }
    for(int i  = 0; i < m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        G.push_back(make_pair(w,make_pair(u,v)));
    }
    Kruskal();
    cout<<total;
    return 0;
}


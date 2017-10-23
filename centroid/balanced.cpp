#include <bits/stdc++.h>
#define int long long
#define V vector
#define H(x) {if (debug) cout<<#x<<": "<<x<<endl;}
using namespace std;
const bool debug = 0;

struct edge {
    int v,t;
};
vector<vector<edge>> adj;
vector<bool> vis;

int centroid(int u, int par, int n, int &out) {
    if (vis[u]) return 0;
    int s = 1, ma = 0;
    for (edge e : adj[u]) if (e.v != par) {
        int sv = centroid(e.v, u, n, out);
        s += sv; ma = max(ma, sv);
    }
    if (max(ma, n-s) <= n/2) out = u;
    return s;
}

void dfs(int u, int par, int bal, vector<int> &bals) {
    if (vis[u]) return;
    bals.push_back(bal);
    for (edge e : adj[u]) if (e.v != par)
        dfs(e.v, u, bal + e.t, bals);
}

int compute(int root, int n) {
    int tot=0;
    V<int> _occ(2*n-1, 0);
    int *occ = &_occ[n-1];
    occ[0]++;
    for (edge e : adj[root]) {
        V<int> bals;
        dfs(e.v, root, e.t, bals);
        for (int bal : bals) {
            tot += occ[-bal];
            H(bal)
        }
        for (int bal : bals) {
            H(bal)
            occ[bal]++;
        }
    }
    return tot;
}

int cd(int u) {
    if (vis[u]) return 0;
    int tot=0, root=-1, sz = centroid(u, -1, 0, root);
    centroid(u, -1, sz, root);
    tot += compute(root, sz); // all paths that go through root
    vis[root] = true;
    for (edge e : adj[root])
        tot += cd(e.v);
    return tot;
}

signed main() {
    int n; cin>>n;
    adj.resize(n);
    for (int i=1; i<n; i++) {
        int p,type; cin>>p>>type; // 1 or -1
        adj[p].push_back({i,type});
        adj[i].push_back({p,type});
    }
    vis.assign(n, false);
    cout<<cd(0)<<"\n";
}

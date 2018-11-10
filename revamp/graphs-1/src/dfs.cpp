vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
  if(visited[u])
    return;
  visited[u] = true;

  // Do something with u

  for(int v : adj[u]) {
    dfs(v);
  }
}

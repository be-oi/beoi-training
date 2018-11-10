vector<vector<int>> adj;

void bfs(int n, int start) {
  vector<int> dist(n, 1e9); // 1e9 is infinity
  queue<int> q;
  // Add start
  q.push(start);
  dist[start] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    // Do something with v
    for(int v : adj[u]) {
      if(dist[v] == 1e9) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

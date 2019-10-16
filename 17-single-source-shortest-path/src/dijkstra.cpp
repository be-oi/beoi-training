#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    // graph contains pairs of (node, weight) for edges, as an adjacency list

    // return the shortest distances to every other node
    // -1 indicates infinity
    vector<int> dist(graph.size(), -1);

    // Add vector<int> parent here for path reconstruction

    // We use std::greater to have the smallest cost first, since by default priority_queue is a max heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push(make_pair(0, start));

    while (!q.empty()) {
        pair<int, int> tmp = q.top();
        q.pop();
        int cost = tmp.first;
        int node = tmp.second;

        // Avoid too much work
        if (cost > dist[node]) continue;

        // You can stop early here if you have a target instead of calculating to every other node

        for (pair<int, int> neigh : graph[node]) {
            int newnode = neigh.first;
            int newcost = cost + neigh.second;
            if (dist[newnode] == -1 || newcost < dist[newnode]) {
                // update parent[newnode]  if doing path reconstruction
                
                dist[newnode] = newcost;
                q.push(make_pair(newcost, newnode));
            }
        }
    }

    return dist;
}

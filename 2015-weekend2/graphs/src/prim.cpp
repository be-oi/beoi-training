#include <cstdio>
#include <set>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
struct node{
	node(int index, int cost, int edge_start){
		this->index = index;
		this->cost = cost;
		this->edge_start = edge_start;
	}
	int index;
	int cost;
	int edge_start;
	bool operator<(const node &n)const{
		return this->cost > n.cost;
	}
};
map<int, map<int, int> > neighbours;
set<pair<int, int> > prim(int start_node){
	priority_queue<node> pq;
	pq.push(node(start_node, 0, start_node));
	set<int> tree;
	set<pair<int, int> > edges;
	while(!pq.empty()){
		node t = pq.top();
		pq.pop();
		if(tree.find(t.index) != tree.end())
			continue;
		tree.insert(t.index);
		if(t.index != t.edge_start)
			edges.insert(make_pair(t.index, t.edge_start));
		for(map<int, int>::iterator it = neighbours[t.index].begin(); it != neighbours[t.index].end(); ++it){
			node n(it->first, it->second, t.index);
			pq.push(n);
		}
	}
	return edges;
}
int main(){
	int N;
	cin >> N;
	int M;
	cin >> M;
	for(int i = 0; i < M; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		neighbours[a][b] = c;
		neighbours[b][a] = c;
	}
	set<pair<int, int> > edges = prim(0);
	int total_cost = 0;
	for(set<pair<int, int> >::iterator it = edges.begin(); it != edges.end(); ++it){
		cout << "Edge from " << it->first << " to " << it->second << " (cost: " << neighbours[it->first][it->second] << ")" << endl;
		total_cost += neighbours[it->first][it->second];
	}
	cout << "Total cost: " << total_cost << endl;
	
	return 0;
}

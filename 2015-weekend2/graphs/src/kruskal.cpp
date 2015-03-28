#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
#define MAXN 10000
int parent[MAXN];
int rank[MAXN];
struct edge{
	int from;
	int to;
	int cost;
	edge(int f, int t, int c){
		this->from = f;
		this->to = t;
		this->cost = c;
	}
	bool operator<(const edge &e)const{
		return this->cost < e.cost;
	}
};
vector<edge> edges;
int N;
int find_parent(int a){
	if(parent[a] == a)
		return a;
	parent[a] = find_parent(parent[a]);
	return parent[a];
}
bool is_same_tree(int a, int b){
	return find_parent(a) == find_parent(b);
}
void merge(int a, int b){
	int parent_a = find_parent(a);
	int parent_b = find_parent(b);
	if(rank[parent_a] < rank[parent_b]){
		parent[parent_a] = parent_b;
	}else{
		parent[parent_b] = parent_a;
		if(rank[parent_a] == rank[parent_b])
			rank[parent_a]++;
	}
}


vector<edge> kruskal(){
	for(int i = 0; i < N; ++i){
		rank[i] = 1;
		parent[i] = i;
	}
	sort(edges.begin(), edges.end());
	vector<edge> mst_edges;
	for(vector<edge>::iterator it = edges.begin(); it != edges.end(); ++it){
		if(is_same_tree(it->from, it->to)){
			continue;
		}
		merge(it->from, it->to);
		mst_edges.push_back(*it);
	}
	return mst_edges;
}

int main(){
	cin >> N;
	int M;
	cin >> M;
	for(int i = 0; i < M; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back(edge(a, b, c));
	}
	vector<edge> mst = kruskal();
	int total_cost = 0;
	for(vector<edge>::iterator it = mst.begin(); it != mst.end(); ++it){
		cout << "Edge from " << it->from << " to " << it->to << " (Cost " << it->cost << ")" << endl;
		total_cost += it->cost;
	}
	cout << "Total cost " << total_cost << endl;
	return 0;
}

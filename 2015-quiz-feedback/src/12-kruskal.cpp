#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
struct union_find{
	map<string, string> parent;
	map<string, int> rank;
	union_find(set<string> &cities){
		for(set<string>::iterator it = cities.begin(); it != cities.end(); ++it){
			rank[*it] = 1;
			parent[*it] = *it;
		}
	}
	void merge(string a, string b){
		string parent_a = find_parent(a);
		string parent_b = find_parent(b);
		if(rank[parent_a] > rank[parent_b]){
			parent[parent_b] = parent_a;
		}else{
			parent[parent_a] = parent_b;
			if(rank[parent_a] == rank[parent_b]){
				rank[parent_b]++;
			}
		}
	}
	bool is_same_tree(string a, string b){
		return find_parent(a) == find_parent(b);
	}
	string find_parent(string id){
		if(parent[id] != id)
			parent[id] = find_parent(parent[id]);
		return parent[id];
	}
};
struct edge{
	string city1, city2;
	int distance;
	edge(string city1, string city2, int distance){
		this->city1 = city1;
		this->city2 = city2;
		this->distance = distance;
	}
	bool operator<(const edge &e)const{
		return this->distance < e.distance;
	}
};
void kruskal(vector<edge> &edges, set<string> &cities){
	sort(edges.begin(), edges.end());
	union_find uf(cities);
	int total_cost = 0;
	for(vector<edge>::iterator it = edges.begin(); it != edges.end(); ++it){
		if(uf.is_same_tree(it->city1, it->city2))
			continue;
		uf.merge(it->city1, it->city2);
		total_cost += it->distance;
		cout << it->city1 << " " << it->city2 << endl;
	}
	cout << "Total cost: " << total_cost << endl;
}
	
int main(){
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	set<string> cities;
	for(int i = 0; i < N; ++i){
		string name;
		cin >> name;
		cities.insert(name);
	}
	int M;
	cin >> M;
	vector<edge> edges;
	for(int i = 0; i < M; ++i){
		string city1, city2;
		int distance;
		cin >> city1 >> city2 >> distance;
		edges.push_back(edge(city1, city2, distance));
	}
	kruskal(edges, cities);
	return 0;
}

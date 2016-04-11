#include <iostream>
#include <map>
#include <string>
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

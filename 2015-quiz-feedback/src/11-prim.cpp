#include <iostream>
#include <set>
#include <string>
#include <map>
#include <list>
#include <queue>

using namespace std;

struct node{
	string identifier;
	int distance;
	string coming_from;
	node(string id, int d, string coming_from){
		this->identifier = id;
		this->distance = d;
		this->coming_from = coming_from;
	}
	bool operator<(const node &n)const{
		return this->distance > n.distance;
	}
};

void prim(map<string, list<pair<string, int > > > &neighbours, set<string> cities){
	priority_queue<node> pq;
	pq.push(node(*cities.begin(), 0, ""));
	set<string> visited;
	int total_cost = 0;
	while(!pq.empty()){
		node n = pq.top();
		pq.pop();
		if(visited.count(n.identifier))
			continue;
		if(n.coming_from != ""){
			cout << n.identifier << " to " << n.coming_from << endl;
			total_cost += n.distance;
		}
		visited.insert(n.identifier);
		for(list<pair<string, int> >::iterator it = neighbours[n.identifier].begin(); it != neighbours[n.identifier].end(); ++it){
			if(visited.count(it->first))
				continue;
			pq.push(node(it->first, it->second, n.identifier));
		}
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
	map<string, list<pair<string, int> > > neighbours;
	for(int i = 0; i < M; ++i){
		string name1, name2;
		int distance;
		cin >> name1 >> name2 >> distance;
		neighbours[name1].push_back(make_pair(name2, distance));
		neighbours[name2].push_back(make_pair(name1, distance));
	}
	prim(neighbours, cities);
	return 0;
}

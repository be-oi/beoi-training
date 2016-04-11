#include <cstdio>
#include <stack>
#include <queue>
#include <list>
#include <vector>


using namespace std;

struct node{
	int index;
	int distance;
	int from;
	bool operator<(const node &n) const{
		return this->distance > n.distance;
	}
	node(int index, int distance, int from){
		this->index = index;
		this->distance = distance;
		this->from = from;
	}
};

pair<int, vector<int> > dijkstra(vector<list<pair<int, int> > > &neighbours, int from, int to){
	priority_queue<node> pq;
	pq.push(node(from, 0, -1));
	vector<bool> visited(neighbours.size(), false);
	vector<int> prev(neighbours.size(), -1);
	while(!pq.empty()){
		node n = pq.top();
		pq.pop();
		if(visited[n.index])
			continue;
		visited[n.index] = true;
		prev[n.index] = n.from;
		if(to == n.index){
			stack<int> p;
			int curr = n.index;
			while(curr != -1){
				p.push(curr);
				curr = prev[curr];
			}
			vector<int> path;
			while(!p.empty()){
				path.push_back(p.top());
				p.pop();
			}
			return make_pair(n.distance, path);
		}
		for(list<pair<int, int> >::iterator it = neighbours[n.index].begin(); it != neighbours[n.index].end(); ++it){
			if(visited[it->first])
				continue;
			pq.push(node(it->first, it->second + n.distance, n.index));
		}
	}
	return make_pair(-1, vector<int>());
}

int main(){
	int N;
	scanf("%d", &N);
	vector<list<pair<int, int> > > neighbours(N);
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		neighbours[a].push_back(make_pair(b, d));
	}
	int start, end;
	scanf("%d%d", &start, &end);
	pair<int, vector<int> > result = dijkstra(neighbours, start, end);
	printf("%d\n", result.first);
	for(vector<int>::iterator it = result.second.begin(); it != result.second.end(); ++it){
		printf("%d ", *it);
	}
	printf("\n");
	return 0;
}

#include <cstdio>
#include <queue>
#include <list>
#include <vector>


using namespace std;

struct node{
	int index;
	int distance;
	bool operator<(const node &n) const{
		return this->distance > n.distance;
	}
	node(int index, int distance){
		this->index = index;
		this->distance = distance;
	}
};

int dijkstra(vector<list<pair<int, int> > > &neighbours, int from, int to){
	priority_queue<node> pq;
	pq.push(node(from, 0));
	vector<bool> visited(neighbours.size(), false);
	while(!pq.empty()){
		node n = pq.top();
		pq.pop();
		if(to == n.index)
			return n.distance;
		if(visited[n.index])
			continue;
		visited[n.index] = true;
		for(list<pair<int, int> >::iterator it = neighbours[n.index].begin(); it != neighbours[n.index].end(); ++it){
			if(visited[it->first])
				continue;
			pq.push(node(it->first, it->second + n.distance));
		}
	}
	return -1;
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
	printf("%d\n", dijkstra(neighbours, start, end));
	return 0;
}

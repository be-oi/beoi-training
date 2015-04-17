#include <cstdio>
#include <list>
#include <vector>
#include <queue>

using namespace std;

bool dfs(vector<list<int> > &neighbours, int target){
	queue<int> st;
	st.push(0);
	vector<bool> open(neighbours.size(), false);
	open[0] = true;
	while(!st.empty()){
		int curr = st.front();
		if(curr == target)
			return true;
		st.pop();
		for(list<int>::iterator it = neighbours[curr].begin(); it != neighbours[curr].end(); ++it){
			if(open[*it])
				continue;
			st.push(*it);
			open[*it] = true;
		}
	}
	return false;
}

int main(){
	int N;
	scanf("%d", &N);
	vector<list<int> > neighbours(N);
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		neighbours[a].push_back(b);
	}
	int to_find;
	scanf("%d", &to_find);
	printf("%d\n", dfs(neighbours, to_find)?1:0);
	return 0;
}

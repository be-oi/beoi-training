#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct container{
	int index;
	int l, h, d;
	container(int index, int l, int h, int d){
		this->index = index;
		this->l = l;
		this->h = h;
		this->d = d;
	}
	int volume() const{
		return this->l * this->h * this->d;
	}
	bool operator<(const container &c) const{
		return this->volume() < c.volume();
	}
};

int main(){
	int N;
	scanf("%d", &N);
	vector<container> containers;
	containers.reserve(N);
	for(int i = 0; i < N; ++i){
		int l, h, d;
		scanf("%d%d%d", &l, &h, &d);
		containers.push_back(container(i, l, h, d));
	}
	sort(containers.begin(), containers.end());
	for(vector<container>::iterator it = containers.begin(); it < containers.end(); ++it){
		printf("%d: %d\n", it->index, it->volume());
	}
	return 0;
}

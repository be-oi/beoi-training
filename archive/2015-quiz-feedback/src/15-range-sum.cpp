#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> v;
	v.reserve(N);
	vector<int> sum;
	sum.reserve(N+1);
	sum.push_back(0);
	for(int i = 0; i < N; ++i){
		int t;
		scanf("%d", &t);
		v.push_back(t);
		sum.push_back(sum.back() + t);
	}
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", sum[b+1]- sum[a]);
	}
	return 0;
}

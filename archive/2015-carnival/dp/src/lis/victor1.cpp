#include <cstdio>
#include <vector>
using namespace std;


int lis(vector<int> a)
{
	int n = a.size();
	vector<int> ending_with;
	for(int i=0; i<n; i++)
		ending_with.push_back(0);
	int best = 0;
	for(int i=0; i<n; i++)
		for(int j=0; j < a[i]; j++){
			ending_with[a[i]] = max(ending_with[a[i]], ending_with[j]+1);
			best = max(best, ending_with[a[i]]);
		}
	return best;
}

int main(){
	int N;
	scanf("%d", &N);
	vector<int> v;
	for(int i = 0; i < N; ++i){
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}
	printf("%d\n", lis(v));
	return 0;
}

#include <cstdio>
#include <vector>
using namespace std;
int lis(vector<int> &a, int min_value, int start_index)
{
	int best = 0;
	int smallest_found = 999999999;
	for(int i = start_index; i < a.size(); ++i)
	{
		if(a[i] > min_value && a[i] < smallest_found)
		{
			best = max(best, 1+lis(a, a[i], i+1));
			smallest_found = a[i];
		}
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
	printf("%d\n", lis(v, -1, 0));
	return 0;
}

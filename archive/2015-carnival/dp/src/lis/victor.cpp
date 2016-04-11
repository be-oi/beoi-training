#include <cstdio>
#include <vector>
using namespace std;


int lis(vector<int> &a)
{
	int L=1; // Longest so far
	vector<int> smallest_end_for;
	smallest_end_for.push_back(-1);
	smallest_end_for.push_back(0);
	for(int i=1; i<a.size(); i++)
	{
		// Binary search for the best length before a[i]
		int lower=0, upper=L+1;
		while(lower+1 < upper)
		{
			int middle = (lower+upper)/2;
			if(a[smallest_end_for[middle]] < a[i])
				lower = middle;
			else
				upper = middle;
		}
		int prev_len = lower;
		// If the length is the best so far
		if(prev_len + 1 > L)
		{
			smallest_end_for.push_back(i);
			L++;
		}
		// If this value is the new smallest for this length
		else if(a[i] < a[smallest_end_for[prev_len+1]])
		{
			smallest_end_for[prev_len+1] = i;
		}
	}
	return L;
}

int main(){
	int N;
	vector<int> v;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}
	printf("%d\n", lis(v));
}

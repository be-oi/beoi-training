#include <cstdio>

int get_ways(int N){
	switch(N){
		case 0:
			return 1;
		case 1:
			return 1;
		case 2:
			return 2;
		default:
			int curr = 4;
			int prev = 2;
			int prev2 = 1;
			for(int i = 3; i < N; ++i){
				int tmp = prev2;
				prev2 = prev;
				prev = curr;
				curr = tmp + prev + prev2;
			}
			return curr;
	}
}

int main(){
	int N;
	scanf("%d", &N);
	printf("%d\n", get_ways(N));
	return 0;
}

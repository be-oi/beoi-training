#include <cstdio>
#include <cmath>
#define MAX 100000

using namespace std;

int max(int, int);
void eratosthene(int, int, bool[]);

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++)
	{
		int N,M;
		scanf("%d %d", &N, &M);
		bool prime[MAX+1];
		for(int i=0; i<=MAX; i++) prime[i] = true;
		eratosthene(N,M,prime);
		for(int i=0; i<=M-N; i++)
		{
			if(prime[i]) printf("%d\n", N+i);
		}
		printf("\n");
	}
}

void eratosthene(int N, int M, bool prime[])
{
	for(int d=2; d<=sqrt(M); d++)
	{
		for(int i=max(2,(N-1)/d+1); i<=M/d; i++)
		{
			prime[d*i-N] = false;
		}
	}
	if(N==1) prime[0] = false;
}

int max(int i, int j) { return i>j?i:j; }

#define MAX 42
#define SUCCESS 42

#include <stdlib.h>
#include <stdio.h>

// efficient:
int main (int argc, char *argv[])
{
	int M, N, i, next;
	scanf ("%d %d", &M, &N);
	
	int tab[MAX] = {0};
	for (i = 0; i < M; i++)
	{
		scanf ("%d ", &next);
		tab[next]++;
	}
	
	int sum = 0;
	for (i = 0; i < N; i++)
	{
		scanf ("%d ", &next);
		if (tab[next] > 0)
		{
			sum++;
			tab[next]--;
		}
	}
	

	printf ("%d\n", sum);
	
	return SUCCESS;
}

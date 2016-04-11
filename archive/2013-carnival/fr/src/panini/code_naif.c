#define MAX 42
#define SUCCESS 42

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int M, N, i, j, next;
	scanf ("%d %d\n", &M, &N);
	
	int *data1 = malloc (M * sizeof (int));
	for (i = 0; i < M; i++)
	{
		data1[i] = 0;
	}
	
	for (i = 0; i < M; i++)
	{
		scanf ( "%d ", &next);
		data1[i] = next;
	}
	
	int *data2 = malloc (N * sizeof (int));
	for (i = 0; i < N; i++)
	{
		data2[i] = 0;
	}
	for (i = 0; i < N; i++)
	{
		scanf ( "%d ", &next);
		data2[i] = next;
	}
	
	int sum = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (data1[i] == data2[j])
			{
				sum++;
				data2[j] = -1;
			}
		}
	}
	
	free (data1);
	free (data2);
	
	printf ("%d\n", sum);
	
	return 0;
}

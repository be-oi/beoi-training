#define MAX 42
#define SUCCESS 42

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[])
{
//	paniniNaive (argc, argv);
	paniniEfficient (argc, argv);
}

int paniniNaive (int argc, char *argv[])
{
	FILE *file = fopen (argv[1], "r");
	int M, N, i, j, next;
	fscanf (file, "%d %d\n", &M, &N);
	
	int *data1 = malloc (M * sizeof (int));
	for (i = 0; i < M; i++)
	{
		data1[i] = 0;
	}
	
	for (i = 0; i < M; i++)
	{
		fscanf (file, "%d ", &next);
		data1[i] = next;
	}
	
	int *data2 = malloc (N * sizeof (int));
	for (i = 0; i < N; i++)
	{
		data2[i] = 0;
	}
	for (i = 0; i < N; i++)
	{
		fscanf (file, "%d ", &next);
		data2[i] = next;
	}
	
	fclose (file);
	
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
	
	file = fopen (argv[2], "w");
	fprintf (file, "%d\n", sum);
	fclose (file);
	
	return SUCCESS;
}

int paniniEfficient (int argc, char *argv[])
{
	FILE *file = fopen (argv[1], "r");
	int M, N, i, next;
	fscanf (file, "%d %d\n", &M, &N);
	
	int tab[MAX] = {0};
	for (i = 0; i < M; i++)
	{
		fscanf (file, "%d ", &next);
		tab[next]++;
	}
	
	int sum = 0;
	for (i = 0; i < N; i++)
	{
		fscanf (file, "%d ", &next);
		if (tab[next] > 0)
		{
			sum++;
			tab[next]--;
		}
	}
	
	fclose (file);
	
	file = fopen (argv[2], "w");
	fprintf (file, "%d\n", sum);
	fclose (file);
	
	return SUCCESS;
}
#include <unistd.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int 
main (int argc, char **argv)
{
	int read_ret, read_int, F, N, i, j, sum, max;
	int *latest, *full;
	
	read_ret = scanf("%d %d\n", &N, &F);
	
	i=0, max=0;
	latest = malloc(sizeof(int)*F);
	full = malloc(sizeof(int)*N);
	
	while ( (read_ret = scanf("%d ", &read_int)) != EOF ) {
		full[i] = read_int;
		i++;
	} 

	for ( i=0; i <= N-F; i++) {
		sum = 0;
		for ( j=0; j < F; j++ ) {
			sum += full[i+j];
		}
		if (sum > max) {
			max = sum;
		}
	}


	printf("%d\n",max/F);
	return 0;
}

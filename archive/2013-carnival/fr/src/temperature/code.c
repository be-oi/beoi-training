#include <unistd.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int 
main (int argc, char **argv)
{
	int read_ret, read_int, F, N, i, j, tot, max;
	int *latest;

	read_ret = scanf("%d %d", &N, &F);
	
	i=0, tot=0, max=0;
	latest = malloc(sizeof(int)*F);
	
	while ( (read_ret = scanf("%d ", &read_int)) != EOF ) {
		if (i < F-1) {
			tot += read_int;
			latest[i%F] = read_int;	
		}
		else {
			tot = tot - latest[i%F] + read_int;
			latest[i%F] = read_int;	
			if (tot > max) {
				max = tot;
			}
		}
		
		i++;
	} 

	printf("%d\n",max/F);
	return 0;
}

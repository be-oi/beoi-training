#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
	int i, j, count, subi, subj, len, x;
	int bestlen = 0;
	char* txt; 
	char* best; 
	
	scanf("%d\n", &len);
	txt = malloc(len+1);
	txt[len]='\0';
	best = malloc(len);
	x = fread(txt, sizeof(char), len, stdin);
	for (i = 0; i < len; i++ ) {
		for (j = i+1; j < len; j ++) {
			count = 0;
			subi = i;
			subj = j;
			while (subj < len && txt[subi] == txt[subj]) {
				count ++;
				subi++;
				subj++;
			}
			if (count > bestlen) {
				bestlen = count;
				strncpy(best, txt+i, count);
				best[count]='\0';
			}
		}
	}
	printf("%s\n", best);
	free(best);
	free(txt);
	return 0;
}

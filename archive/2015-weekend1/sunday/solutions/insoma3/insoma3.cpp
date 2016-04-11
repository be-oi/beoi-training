#include<cstdio>

int mergeSort(int*, int*, int*, int*);

int main(void)
{
	int N;
	scanf("%d", &N);
	int h[100000], j[100000];
	for(int i=0; i<N; i++) scanf("%d", &h[i]);
	int res = mergeSort(h, h+N, j, j+N);
	printf("%d\n", res);
}

int mergeSort(int* oBegin, int* oEnd, int* aBegin, int* aEnd)
{
	if(oEnd == oBegin+1) return 0;
	else
	{
		int res = 0;
		
		int len = oEnd-oBegin;
		int half = len/2;
		res += mergeSort(oBegin, oBegin+half, aBegin, aBegin+half);
		res += mergeSort(oBegin+half, oEnd, aBegin+half, aEnd);
		
		int i=0,j=0;
		while(i+j<len)
		{
			if(i==half)
			{
				for(;j<len-half;j++) *(aBegin+i+j) = *(oBegin+half+j);
				break;
			}
			if(j==len-half)
			{
				for(;i<half;i++) *(aBegin+i+j) = *(oBegin+i);
				break;
			}
			if(*(oBegin+i) <= *(oBegin+half+j))
			{
				*(aBegin+i+j) = *(oBegin+i);
				i++;
			}
			else
			{
				*(aBegin+i+j) = *(oBegin+half+j);
				res += half-i;
				j++;
			}
		}
		for(i=0; i<len; i++)
		{
			*(oBegin+i) = *(aBegin+i);
		}
		return res;
	}
}

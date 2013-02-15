// Source: http://www.algorithmist.com/index.php/Longest_Increasing_Subsequence.cpp
// Adapted by G. Geeraerts

#include <iostream>
using namespace std;

const int MAX = 10000 ;

/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
/* a is the sequence of inputs, of length n */
/* the function should write in b the sequences of indices (terminated by -1) s.t. a[b[0]], a[b[1]], ... is the longest
 increasing sequence in a */
void find_lis(int a[MAX], int b[MAX], int n) // n = size of vector a
{
	/**** 8< *** 8< *** CUT FROM HERE *** 8< *** 8< ****/
	
	int p[MAX] ;
	int u, v;
	int j = -1 ; // last occupied position in vector b
	
	if (n==0) return;
	
	j++ ;
	b[j] = 0 ;
		
	for (int i = 1; i < n; i++) 
	{
		
		// If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b[j]] < a[i]) 
		{
			p[i] = b[j];
			j++ ;
			b[j] = i ;
			
			continue;
		}
		
		// Binary search to find the smallest element referenced by b which is just bigger than a[i]
		// Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.    
		for (u = 0, v = j; u < v;) 
		{
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
		
		// Update b if new value is smaller then previously referenced value 
		if (a[i] < a[b[u]]) 
		{
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
	
	
	for (u = j+1, v = b[j]; u--; v = p[v]) b[u] = v;
	b[j+1] = -1 ;
	
	/**** 8< *** 8< *** TO HERE *** 8< *** 8< ****/

}



/* Example of usage: */
#include <cstdio>
int main()
{
	int i = 0 ;
	int a[MAX] ;
	int b[MAX] ;
	int nb_ghostbusters ;
	int nb_instances ;
	
	// All values are assumed in the interval [-90, 90]
	
	cin >> nb_instances >> nb_ghostbusters ;
	
	for (int i=0; i<nb_instances; ++i) {
		for (int j=0; j<nb_ghostbusters; ++j)
			cin >> a[j] ;
		find_lis(a,b,nb_ghostbusters) ;
		
		// Print result
		for (int j=0; b[j] != -1 ;++j)
			cout <<b[j]+1 <<" " ;
		cout << endl ;
		
	}
	
	
	return 0;
}

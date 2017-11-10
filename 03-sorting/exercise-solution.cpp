#include<bits/stdc++.h>
using namespace std;

vector<int> insertion_sort(vector<int> a) {
	for(int i = 1; i < (int)a.size(); ++i) {
		int x = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > x) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = x;
	}
	return a;
}

vector<int> merge(vector<int> a, vector<int> b) {
	vector<int> result;
	int n = (int)a.size(), m = (int)b.size();
	int i = 0, j = 0;
	while(i != n || j != m) {
		if(i == n) result.push_back(b[j++]);
		else if(j == m) result.push_back(a[i++]);
		else if(a[i] <= b[j]) result.push_back(a[i++]);
		else result.push_back(b[j++]);
	}
	return result;
}
vector<int> merge_sort(vector<int> a) {
	int n = a.size();
	if(n == 1) return a;
	vector<int> left,right;
	for(int i = 0; i < n/2; ++i) left.push_back(a[i]);
	for(int i = n/2; i < n; ++i) right.push_back(a[i]);
	left = merge_sort(left);
	right = merge_sort(right);
	return merge(left,right);
}

vector<int> quick_sort(vector<int> a) {
	int n = a.size();
	if(n <= 1) return a;
	vector<int> less,equal,greater;
	int pivot = a[0];
	for(int x : a) {
		if(x < pivot) less.push_back(x);
		if(x == pivot) equal.push_back(x);
		if(x > pivot) greater.push_back(x);
	}
	less = quick_sort(less);
	greater = quick_sort(greater);
	vector<int> result;
	for(int x : less) result.push_back(x);
	for(int x : equal) result.push_back(x);
	for(int x : greater) result.push_back(x);
	return result;
}

int main() {
	// sample input: 10 2 9 1 0 5 4 3 0 4 7

	// the code below will test your implementations; don't touch it!
	vector<int> a;
	int n; cin >> n;
	while(n--) { int x; cin >> x; a.push_back(x); }
	cout << "array to be sorted:" << endl;
	for(int i = 0; i < (int)a.size(); ++i) cout << ' ' << a[i]; cout << endl;
	vector<int> b = insertion_sort(a);
	cout << "insertion sort:" << endl;
	for(int i = 0; i < (int)b.size(); ++i) cout << ' ' << b[i]; cout << endl;
	vector<int> c = merge_sort(a);
	cout << "merge sort:" << endl;
	for(int i = 0; i < (int)c.size(); ++i) cout << ' ' << c[i]; cout << endl;
	vector<int> d = quick_sort(a);
	cout << "quick sort:" << endl;
	for(int i = 0; i < (int)d.size(); ++i) cout << ' ' << d[i]; cout << endl;
}


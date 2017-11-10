#include<bits/stdc++.h>
using namespace std;

vector<int> insertion_sort(vector<int> a) {
	// implement insertion sort here
	return a;
}
vector<int> merge_sort(vector<int> a) {
	// implement merge sort here
	return a;
}
vector<int> quick_sort(vector<int> a) {
	// implement quick sort here
	return a;
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


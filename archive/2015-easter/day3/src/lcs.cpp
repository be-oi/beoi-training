#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string a, string b){
	int best = 0;
	vector<int> cache(a.size()+1, 0);
	for(int i = 0; i < b.size(); ++i){
		for(int j = a.size()-1; j >= 0; --j){
			if(a[i] == b[j]){
				cache[j+1] = cache[j] + 1;
				best = max(cache[j+1], best);
			}else{
				cache[j+1] = 0;
			}
		}
	}
	return best;
}
		

int main(){
	string a, b;
	cin >> a >> b;
	cout << lcs(a, b) << endl;
	return 0;
}

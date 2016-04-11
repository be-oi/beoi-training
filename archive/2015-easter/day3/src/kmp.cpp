#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> preprocess(string pattern){
	vector<int> back_table(pattern.size()+1, 0);
	int j = -1;
	back_table[0] = -1;
	for(int i = 0; i < pattern.size(); ++i){
		while(j >= 0 && pattern[i] != pattern[j]){
			j = back_table[j];
		}
		++j;
		back_table[i+1] = j;
	}
	return back_table;
}

int matching(string text, string pattern){
	vector<int> back_table = preprocess(pattern);
	int j = 0;
	for(int i = 0; i < text.size(); ++i){
		while(j >= 0 && text[i] != pattern[j]){
			j = back_table[j];
		}
		j++;
		if(j == pattern.size()){
			return i+1-j;
		}
	}
	return -1;
}

int main(){
	string a, b;
	cin >> a >> b;
	cout << matching(a, b) << endl;
	return 0;
}

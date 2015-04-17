#include <string>
#include <iostream>

using namespace std;

int matching(string text, string pattern){
	for(int i = 0; i <= text.size() - pattern.size(); ++i){
		bool found = true;
		for(int j = 0; j < pattern.size(); ++j){
			if(text[i+j]!=pattern[j]){
				found = false;
				break;
			}
		}
		if(found){
			return i;
		}
	}
	return -1;
}

int main(){
	string text, pattern;
	cin >> text >> pattern;
	cout << matching(text, pattern) << endl;
	return 0;
}

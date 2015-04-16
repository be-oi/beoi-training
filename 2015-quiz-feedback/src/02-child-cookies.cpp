#include <string>
#include <iostream>
#include <map>

using namespace std;

struct cookies{
	map<string, int> pocket;
	void receive_cookies(string child, int amount){
		if(amount <= 0)
			cout << "Why are you so cruel as to give a non-positive number of cookies to this child?" << endl;
		this->pocket[child] += amount;
	}
	void eat_cookies(string child, int amount){
		if(amount <= 0)
			cout << "This is just disgusting..." << endl;
		if(amount > get_cookies(child))
			cout << "The child can only eat " << get_cookies(child)<< " cookies" << endl;
		this->pocket[child] -= amount;
	}
	int get_cookies(string child){
		return this->pocket[child];
	}
};

int main(){
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	cookies cc;
	for(int i = 0; i < N; ++i){
		string name, action;
		int amount;
		cin >> name >> action >> amount;
		if(action == "receive"){
			cc.receive_cookies(name, amount);
		}else if(action == "eat"){
			cc.eat_cookies(name, amount);
		}else{
			cout << "Invalid action, choose either receive/eat" << endl;
		}
		cout << name << " has now " << cc.get_cookies(name) << endl;
	}
	return 0;
}
	

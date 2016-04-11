#include <iostream>
#include <set>
#include <string>

using namespace std;

struct classroom{
	set<string> students;
	void enter(string student){
		if(in_classroom(student))
			cout << "Student is already in classroom" << endl;
		students.insert(student);
	}
	void leave(string student){
		if(!in_classroom(student))
			cout << "Student is not in classroom" << endl;
		students.erase(student);
	}
	bool in_classroom(string student){
		return students.count(student) > 0;
	}
};

int main(){
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	classroom room;
	for(int i = 0; i < N; ++i){
		string name;
		string action;
		cin >> name >> action;
		if(action == "enter"){
			room.enter(name);
		}else if(action == "leave"){
			room.leave(name);
		}else{
			cout << "Invalid action, choose enter/leave" << endl;
		}
	}
	return 0;
}



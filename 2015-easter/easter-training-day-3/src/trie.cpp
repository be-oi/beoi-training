#include <map>
#include <iostream>
#include <string>

using namespace std;

struct node{
	map<char, node*> children;
};

void add_to_prefix_tree(node *n, string s){
	node* current_node = n;
	int current_index = 0;
	while(current_index < s.size() && current_node->children.find(s[current_index]) != current_node->children.end()){
		current_node = current_node->children[s[current_index]];
		current_index ++;
	}
	while(current_index < s.size()){
		current_node->children[s[current_index]] = new node();
		current_node = current_node->children[s[current_index]];
		current_index ++;
	}
}
int find_longest_prefix(node *n, string s){
	node* current_node = n;
	int current_index = 0;
	while(current_index < s.size() && current_node->children.find(s[current_index]) != current_node->children.end()){
		current_node = current_node->children[s[current_index]];
		current_index++;
	}
	return current_index;
}

int main(){
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	node *root = new node();
	for(int i = 0; i < N; ++i){
		string s;
		cin >> s;
		cout << find_longest_prefix(root, s) << endl;
		add_to_prefix_tree(root, s);
	}
	return 0;
}

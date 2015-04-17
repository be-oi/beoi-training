#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct node;
struct node{
	node(string id){
		this->id = id;
	}
	string id;
	vector<node*> children;
	void print_hierarchy(string prec){
		cout << prec << this->id << endl;
		for(vector<node*>::iterator it = this->children.begin(); it != this->children.end(); ++it){
			(*it)->print_hierarchy(prec+" ");
		}

	}
	void addChild(node* n){
		this->children.push_back(n);
	}
};
vector<node*> nodes;
int main(){
	nodes.push_back(new node("1"));
	nodes.push_back(new node("2"));
	nodes.push_back(new node("3"));
	nodes.push_back(new node("4"));
	nodes.push_back(new node("5"));
	nodes.push_back(new node("6"));
	nodes[0]->addChild(nodes[1]);
	nodes[0]->addChild(nodes[2]);
	nodes[1]->addChild(nodes[3]);
	nodes[1]->addChild(nodes[4]);
	nodes[5]->addChild(nodes[5]);
	nodes[0]->print_hierarchy("");
}

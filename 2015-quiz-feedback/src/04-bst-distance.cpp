#include <cstdio>

#define LEFT 0
#define ME 1
#define RIGHT 2

struct node{
	int value;
	node* left;
	node* right;
	node(){
		this->value = -1;
		this->left = NULL;
		this->right = NULL;
	}
	void add_value(int value){
		if(this->value == -1){
			this->value = value;
			this->left = new node();
			this->right = new node();
		}else if(this->value < value){
			this->right->add_value(value);
		}else if(this->value > value){
			this->left->add_value(value);
		}
	}
	int side(int v){
		if(this->value == v)
			return ME;
		if(this->value < v)
			return RIGHT;
		return LEFT;
	}
	node* node_at_side(int side){
		switch(side){
			case LEFT:
				return left;
			case RIGHT:
				return right;
			default:
				return this;
		}
	}
	int distance_to(int v){
		if(v == this->value)
			return 0;
		if(v < this->value)
			return 1+this->left->distance_to(v);
		else	
			return 1+this->right->distance_to(v);
	}
};

int distance_between(node *root, int a, int b){
	node *current = root;
	while(current->side(a) == current->side(b)){
		current = current->node_at_side(current->side(a));
	}
	return current->distance_to(a) + current->distance_to(b);
}

int main(){
	int N;
	scanf("%d", &N);
	node* root =  new node();
	for(int i = 0; i < N; ++i){
		int t;
		scanf("%d", &t);
		root->add_value(t);
	}
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("Distance from a to b is: %d\n", distance_between(root, a, b));
	}
	return 0;
}

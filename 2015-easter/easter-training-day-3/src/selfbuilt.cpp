#include <cstdio>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;

#define MAX 999999

struct node{
	node* right;
	node* left;
	int value;
	int index;
	int right_bound;
	int left_bound;
	int minimum_index;
	int minimum_value;
	node(int index, int left_bound, int right_bound){
		this->minimum_index = index;
		this->minimum_value = MAX;
		this->left_bound = left_bound;
		this->right_bound = right_bound;
		this->index = index;
		this->left = NULL;
		this->right = NULL;
		if(left_bound < this->index){
			this->left = new node((left_bound+this->index)/2, left_bound, this->index-1);
		}
		if(right_bound > this->index){
			this->right = new node((right_bound+this->index+1)/2, this->index+1, right_bound);
		}
	}
	bool overlaps(int start, int end){
		if(start > this->right_bound)
			return false;
		if(end < this->left_bound)
			return false;
		return true;
	}
	pair<int, int> find_minimum_range(int start, int end){
		if(!overlaps(start, end))
			return make_pair(MAX, this->index);
		if(start<=this->left_bound && end >= this->right_bound){
			return make_pair(this->minimum_value, this->minimum_index);
		}
		pair<int, int> best = make_pair(MAX, this->index);
		if(start <= this->index && end >= this->index){
			best = make_pair(this->value, this->index);
		}
		if(this->left != NULL)
			best = min(best, this->left->find_minimum_range(start, end));
		if(this->right != NULL)
			best = min(best, this->right->find_minimum_range(start, end));
		return best;
	}
	void update_minimum_index(){
		this->minimum_index = this->index;
		this->minimum_value = this->value;
		if(this->left && this->left->minimum_value < this->value){
			this->minimum_value = this->left->minimum_value;
			this->minimum_index = this->left->minimum_index;
		}
		if(this->right && this->right->minimum_value < this->value){
			this->minimum_value = this->right->minimum_value;
			this->minimum_index = this->right->minimum_index;
		}
	}
	void set_value_at(int index, int v){
		if(this->index == index){
			this->value = v;
			update_minimum_index();
		}else if(index < this->index){
			this->left->set_value_at(index, v);
		}else{
			this->right->set_value_at(index, v);
		}
	}
};

int main(){
	int N;
	scanf("%d", &N);
	node *root = new node(N/2, 0, N);
	for(int i = 0; i < N; ++i){
		int v;
		scanf("%d", &v);
		root->set_value_at(i, v);
	}
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; ++i){
		int left, right;
		scanf("%d%d", &left, &right);
		pair<int, int> result = root->find_minimum_range(left, right);
		printf("index: %d, value: %d\n", result.second, result.first);
	}
}

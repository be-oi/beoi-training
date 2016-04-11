#include <vector>
#include <iostream>

using namespace std;
//Competitive Programming 3, p. 57
class SegmentTree{
	private:
		vector<int> st, A;
		int n;
		int left(int p){ return p << 1; }
		int right(int p){ return (p << 1) + 1; }

		void build(int p, int L, int R){
			if(L == R)
				st[p] = L;
			else{
				build(left(p), L, (L+R)/2);
				build(right(p), (L+R)/2 + 1, R);
				int p1 = st[left(p)], p2 = st[right(p)];
				st[p] = (A[p1] <= A[p2])?p1:p2;
			}
		}

		int rmq(int p, int L, int R, int i, int j){
			if(i > R || j < L) return -1;
			if(L >= i && R <= j) return st[p];

			int p1 = rmq(left(p), L, (L+R)/2, i, j);
			int p2 = rmq(right(p), (L+R)/2 + 1, R, i, j);

			if(p1 == -1) return p2;
			if(p2 == -1) return p1;

			return (A[p1] <= A[p2])? p1 : p2;
		}
	public:
		SegmentTree(const vector<int> &A){
			this->A = A;
			n = (int)A.size();
			st.assign(4*n, 0);
			build(1, 0, n-1);
		}
		int rmq(int i, int j){ return rmq(1, 0, n-1, i, j); }
};

int main(){
	int N;
	cin >> N;
	int t;
	vector<int> v;
	for(int i = 0; i < N; ++i){
		cin >> t;
		v.push_back(t);
	}
	SegmentTree st(v);
	int M;
	cin >> M;
	for(int i = 0; i < M; ++i){
		int a, b;
		cin >> a >> b;
		cout << st.rmq(a, b) << endl;
	}
	return 0;
}

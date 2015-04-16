#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define MAX 999999
void floyd_warshall(vector<vector<int> > &distances){
	for(int k = 0; k < distances.size(); ++k){
		for(int i = 0; i < distances.size(); ++i){
			for(int j = 0; j < distances.size(); ++j){
				distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][i]);
			}
		}
	}
}
int main(){
	int N;
	cin >> N;
	vector<vector<int> > distances;
	for(int i = 0; i < N; i++){
		distances.push_back(vector<int>(N, MAX));
	}
	int M;
	cin >> M;
	for(int i = 0; i < M; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		distances[a][b] = c;
	}
	floyd_warshall(distances);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cout << setw(8) << distances[i][j];
		}
		cout << endl;
	}
	return 0;
}

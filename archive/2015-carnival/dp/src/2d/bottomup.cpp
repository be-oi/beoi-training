#include <cstdio>
#include <vector>

using namespace std;
#define MAXN 1000
int grid[MAXN][MAXN];
int calculated[MAXN][MAXN];
int cheapest(int row, int col){
	calculated[0][0] = grid[0][0];
	for(int c = 1; c <= col; ++c)
		calculated[0][c] = calculated[0][c-1]+grid[0][c];
	for(int r = 1; r <= row; ++r)
		calculated[r][0] = calculated[r-1][0] + grid[r][0];
	for(int r = 1; r <= row; ++r)
		for(int c = 1; c <= col; ++c)
			calculated[r][c] = grid[r][c] + min(calculated[r-1][c], calculated[r][c-1]);
	return calculated[row][col];
}
int main(){
	int R, C;
	scanf("%d%d", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%d", &grid[i][j]);
			calculated[i][j] = -1;
		}
	}
	printf("%d\n", cheapest(R-1, C-1));
	return 0;
}

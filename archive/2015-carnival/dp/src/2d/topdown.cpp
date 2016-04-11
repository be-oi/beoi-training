#include <cstdio>
#include <vector>

using namespace std;
#define MAXN 1000
int grid[MAXN][MAXN];
int calculated[MAXN][MAXN];
int cheapest(int row, int col){
	if(row == 0 && col == 0)
		return grid[0][0];
	if(calculated[row][col]==-1){
		if(row == 0)
			calculated[row][col] = grid[row][col] + cheapest(row, col-1);
		else if(col == 0)
			calculated[row][col] = grid[row][col] + cheapest(row-1, col);
		else
			calculated[row][col] = grid[row][col] + min(cheapest(row-1, col), cheapest(row, col-1));
	}
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

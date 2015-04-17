#include <cstdio>

#define MAXR 1000
#define MAXC 1000

int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int R, C;
char grid[MAXR][MAXC];
bool visited[MAXR][MAXC];

bool valid_coordinate(int r, int c){
	if(!(r >= 0 && r < R && c >= 0 && c < C))
		return false;

	return grid[r][c] == '.';
}

void explore_room(int r, int c){
	if(!valid_coordinate(r, c))
		return;
	if(visited[r][c])
		return;
	visited[r][c] = true;
	printf(" %d %d\n", r, c);
	for(int i = 0; i < 4; ++i){
		int nr = r + directions[i][0];
		int nc = c + directions[i][1];
		explore_room(nr, nc);
	}
}

int main(){
	scanf("%d%d", &R, &C);
	for(int i = 0; i < R; ++i){
		while(fgetc(stdin) != '\n'){}
		for(int j = 0; j < C; ++j){
			grid[i][j] = fgetc(stdin);
		}
	}
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(!valid_coordinate(i, j))
				continue;
			if(!visited[i][j]){
				printf("Found a new room: \n");
				explore_room(i, j);
			}
		}
	}
	return 0;
}

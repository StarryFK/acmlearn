#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define RI(x) scanf("%d", &x)

struct Pos{
	int x,y;
};
int n,m;
int ma[1005][1005];
queue<Pos> q;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

inline bool inrange(int x, int y){
	return x>=0 && x<n && y>=0 && y<m;
}

inline void bfs(){
	int curx, cury, nxx, nxy;
	while(q.size()){
		curx = q.front().x;
		cury = q.front().y;
		q.pop();

		//cout << curx << ' ' << cury << endl;

		for(int i=0; i<4; i++){
			nxx = curx + dx[i];
			nxy = cury + dy[i];
			if(inrange(nxx, nxy) && ma[nxx][nxy]<0){
				ma[nxx][nxy] = ma[curx][cury] + 1;
				q.push({nxx, nxy});
			}
		}
	}
}

int main(){
	RI(n);
	RI(m);
	while(getchar()!='\n');
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ma[i][j] = getchar()=='1' ? 0 : -1;
			if(ma[i][j]==0){
				q.push({i,j});
			}
		}
		while(getchar()!='\n');
	}
	bfs();
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ", ma[i][j]);
		}
		puts("");
	}
}

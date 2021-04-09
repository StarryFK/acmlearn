#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define RI(x) scanf("%d", &x)

struct St{
	int x,y,lie;
};
int r,c;
char ma[505][505];
int dis[505][505][3];
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
const int rox[3][4] = {{-2,1,0,0},{-1,2,0,0},{-1,1,0,0}};
const int roy[3][4] = {{0,0,-2,1},{0,0,-1,1},{0,0,-1,2}};
const int rol[3][4] = {{1,1,2,2},{0,0,1,1},{2,2,0,0}};
St stt, endd;
queue<St> q;

inline bool inrange(int x, int y){
	return x>=0 && x<r && y>=0 && y<c;
}

inline bool valid(int x, int y, int lie){
	if(ma[x][y]=='#' || !inrange(x,y)){
		return false;
	}
	if(lie==0 && ma[x][y]=='E'){
		return false;
	}
	if(lie==1 && (ma[x+1][y]=='#' || !inrange(x+1,y))){
		return false;
	}
	if(lie==2 && (ma[x][y+1]=='#' || !inrange(x,y+1))){
		return false;
	}
	return true;
}

inline void init(){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(ma[i][j]=='O'){
				endd.x=i;
				endd.y=j;
				endd.lie=0;
				ma[i][j]='.';
			}
			if(ma[i][j]=='X'){
				for(int k=0; k<4; k++){
					if(inrange(i+dx[k], j+dy[k]) && ma[i+dx[k]][j+dy[k]]=='X'){
						stt.x = min(i, i+dx[k]);
						stt.y = min(j, j+dy[k]);
						stt.lie = k<2 ? 1 : 2;
						ma[i][j] = ma[i+dx[k]][j+dy[k]] = '.';
					}
				}
				if(ma[i][j]=='X'){
					stt.x = i;
					stt.y = j;
					stt.lie = 0;
					ma[i][j] = '.';
				}
			}
		}
	}
}

inline bool bfs(){
	while(q.size()){
		q.pop();
	}
	memset(dis, 0xff, sizeof(dis));
	dis[stt.x][stt.y][stt.lie]=0;
	q.push(stt);
	int curx, cury, curl, nxx, nxy, nxl;
	while(q.size()){
		curx = q.front().x;
		cury = q.front().y;
		curl = q.front().lie;

		//cout << curx << ' ' << cury << ' ' << curl << endl;

		q.pop();
		for(int i=0; i<4; i++){
			nxx = curx + rox[curl][i];
			nxy = cury + roy[curl][i];
			nxl = rol[curl][i];
			if(dis[nxx][nxy][nxl]==-1 && valid(nxx, nxy, nxl)){
				dis[nxx][nxy][nxl] = dis[curx][cury][curl] + 1;
				if(nxx==endd.x && nxy==endd.y && nxl==endd.lie){
					return true;
				}
				q.push({nxx, nxy, nxl});
			}
		}
	}
	return false;
}

int main(){
	while(1){
		RI(r);
		RI(c);
		if(r==0 && c==0){
			break;
		}
		getchar();
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				ma[i][j] = getchar();
			}
			getchar();
		}
		init();
		if(bfs()){
			printf("%d\n", dis[endd.x][endd.y][endd.lie]);
		}else{
			puts("Impossible");
		}
	}
}

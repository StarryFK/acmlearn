#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define RI(x) scanf("%d", &x)

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
struct Pos{
	int x;
	int y;
};
int n,m;
queue<Pos> qb;
queue<Pos> qg;
int ma[805][805];
int dboy[805][805];
int dgirl[805][805];
inline void clr(){
	while(qb.size()){
		qb.pop();
	}
	while(qg.size()){
		qg.pop();
	}
	memset(dboy, 0x3f, sizeof(dboy));
	memset(dgirl, 0x3f, sizeof(dgirl));
}
int g1x, g1y, g2x, g2y;
inline bool legal(int x, int y, int round){
	return  x>=0 && x<n && y>=0 && y<m 
		&& abs(x-g1x)+abs(y-g1y)>round*2 
		&& abs(x-g2x)+abs(y-g2y)>round*2 
		&& ma[x][y] != 'X';
}
inline int bfs(){
	for(int round=1; qb.size() && qg.size(); round++){

		//cout << "round " << round << endl;

		for(int i=0; i<3; i++){
			for(int j=qb.size(); j; j--){
				int x=qb.front().x;
				int y=qb.front().y;
				qb.pop();
				if(!legal(x,y,round)){
					continue;
				}

				//cout << "boy " << x << ' ' << y << endl;

				for(int k=0; k<4; k++){
					int nx=x+dx[k];
					int ny=y+dy[k];
					if(legal(nx, ny, round) && dboy[nx][ny]==INF){
						dboy[nx][ny]=round;
						qb.push({nx, ny});

						//cout << "push " << nx << ' ' << ny << endl;

					}
				}
			}
		}
		for(int j=qg.size(); j; j--){
			int x = qg.front().x;
			int y = qg.front().y;
			qg.pop();
			if(!legal(x,y,round)){
				continue;
			}

			//cout << "girl " << x << ' ' << y << endl;

			for(int k=0; k<4; k++){
				int nx=x+dx[k];
				int ny=y+dy[k];
				if(legal(nx, ny, round) && dgirl[nx][ny]==INF){
					dgirl[nx][ny] = round;
					if(dboy[nx][ny]!=INF){
						return round;
					}
					qg.push({nx, ny});

					//cout << "push " << nx << ' ' << ny << endl;

				}
			}
		}
	}
	return -1;
}
int main(){
	int t;
	RI(t);
	while(t--){
		clr();
		RI(n);
		RI(m);
		getchar();
		int gcnt=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				ma[i][j] = getchar();
				if(ma[i][j]=='Z'){
					if(gcnt==0){
						g1x = i;
						g1y = j;
						gcnt++;
					}else{
						g2x = i;
						g2y = j;
					}
				}
				if(ma[i][j]=='M'){
					qb.push({i,j});
					dboy[i][j]=0;
				}
				if(ma[i][j]=='G'){
					qg.push({i,j});
					dgirl[i][j]=0;
				}
			}
			getchar();
		}
		int ans = bfs();
		printf("%d\n", ans);
	}
}

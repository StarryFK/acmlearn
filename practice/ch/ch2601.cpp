#include <iostream>
#include <cstring>
#include <cstdio>
#include <deque>
using namespace std;
struct Pos{
	int x,y;
};
deque<Pos> dq;
char ma[505][505];
int dis[505][505];
bool vis[505][505];
int r,c;
const int dx[]={1,-1,1,-1};
const int dy[]={1,-1,-1,1};
const int cx[]={0,-1,0,-1};
const int cy[]={0,-1,-1,0};
const char best[]=R"(\\//)";
bool inr(int x, int y){
	return x>=0 && x<=r && y>=0 && y<=c;
}
inline int getcost(int x, int y, int dr){
	if(ma[x+cx[dr]][y+cy[dr]] == best[dr]){
		return 0;
	}else{
		return 1;
	}
}
bool bfs(){
	while(dq.size()){
		dq.pop_back();
	}
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[0][0]=0;
	dq.push_back({0,0});
	while(dq.size()){
		int x=dq.front().x;
		int y=dq.front().y;
		dq.pop_front();
		if(vis[x][y]){
			continue;
		}
		vis[x][y]=1;
		for(int i=0; i<4; i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(inr(nx, ny) && !vis[nx][ny]){
				if(getcost(x,y,i)==0){
					dis[nx][ny]=min(dis[x][y], dis[nx][ny]);
					dq.push_front({nx, ny});
				}else{
					dis[nx][ny]=min(dis[x][y]+1, dis[nx][ny]);
					dq.push_back({nx, ny});
				}
				if(nx==r && ny==c){
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> r >> c;
		for(int i=0; i<r; i++){
			scanf("%s", ma[i]);
		}	
		if(bfs()){
			cout << dis[r][c] << endl;
		}else{
			cout << "NO SOLUTION" << endl;
		}
	}
}

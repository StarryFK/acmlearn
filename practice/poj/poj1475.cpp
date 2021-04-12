#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
struct St{
	int x;
	int y;
	int dir;
};
struct Pos{
	int x;
	int y;
};

int r,c;
char ma[25][25];
int dbox[25][25][4];
int dman[25][25][4];
queue<St> q;

inline bool valid(int x, int y){
	return x>=0 && x<r && y>=0 && y<c && ma[x][y]=='.';
}
inline void clr(){
	memset(dbox, 0xff, sizeof(dbox));
	memset(dman, 0xff, sizeof(dman));
	while(q.size()){
		q.pop();
	}
}
queue<Pos> qm;
struct Com{
	int box;
	int man;
	int index;
};
bool operator<(const Com &a, const Com &b){
	if(a.box!=b.box){
		return a.box<b.box;
	}else{
		return a.man<b.man;
	}
}
vector<Com> v;
int dis[25][25];
inline int bfsman(int curx, int cury, int opx, int opy){
	if(!valid(opx, opy)){
		return -1;
	}
	if(curx==opx && cury==opy){
		return 0;
	}
	while(qm.size()){
		qm.pop();
	}
	memset(dis, 0xff, sizeof(dis));
	dis[curx][cury]=0;
	qm.push({curx, cury});
	while(qm.size()){
		curx = qm.front().x;
		cury = qm.front().y;
		qm.pop();
		for(int i=0; i<4; i++){
			if(valid(curx+dx[i], cury+dy[i]) && dis[curx+dx[i]][cury+dy[i]]<0){
				dis[curx+dx[i]][cury+dy[i]] = dis[curx][cury] + 1;
				if(curx+dx[i]==opx && cury+dy[i]==opy){
					return dis[curx+dx[i]][cury+dy[i]];
				}
				qm.push({curx+dx[i], cury+dy[i]});
			}
		}
	}
	return -1;
}
inline bool bfs(){
	int tgx=0, tgy=0;
	int bx=0, by=0;
	int mx=0, my=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(ma[i][j]=='T'){
				tgx = i;
				tgy = j;
				ma[i][j] = '.';
			}
			if(ma[i][j]=='B'){
				bx = i;
				by = j;
				ma[i][j] = '.';
			}
			if(ma[i][j]=='S'){
				mx = i;
				my = j;
				ma[i][j] = '.';
			}
		}
	}
	ma[bx][by] = '#';
	for(int i=0; i<4; i++){
		int man = bfsman(mx, my, bx+dx[i], by+dy[i]);
		if(man>=0){
			dman[bx][by][i]=man;
			dbox[bx][by][i]=0;
			q.push({bx, by, i});
		}
	}
	ma[bx][by] = '.';
	int stop=0x3f3f3f3f;
	while(q.size()){
		int x=q.front().x;
		int y=q.front().y;
		int dir=q.front().dir;
		q.pop();

		cout << x << ' ' << y << ' ' << dir << endl;
		cout << dbox[x][y][dir] <<  ' ' << dman[x][y][dir] << endl;

		if(dbox[x][y][dir]==stop){
			break;
		}
		for(int i=0; i<4; i++){
			if(!valid(x-dx[i], y-dy[i])){
				continue;
			}
			ma[x][y] = '#';
			int man = bfsman(x+dx[dir], y+dy[dir], x+dx[i], y+dy[i]);

			cout << "bfsman " << x+dx[dir] << ' ' << y+dy[dir] << ' ' <<  x+dx[i] << ' ' <<  y+dy[i]<< endl << man << endl;
			ma[x][y] = '.';
			if(man>=0){
				dman[x-dx[i]][y-dy[i]][i] = dman[x][y][dir] + man + 1;
				dbox[x-dx[i]][y-dy[i]][i] = dbox[x][y][dir] + 1;
				if(x-dx[i]==tgx && y-dy[i]==tgy){
					stop = dbox[x-dx[i]][y-dy[i]][i];
				}
				q.push({x-dx[i], y-dy[i], i});
			}
		}
	}
	v.clear();
	for(int i=0; i<4; i++){
		if(dbox[tgx][tgy][i]<0){
			continue;
		}
		v.push_back({dbox[tgx][tgy][i], dman[tgx][tgy][i], i});
	}
	sort(v.begin(), v.end());

	cout << "size" << v.size() << endl;

	if(v.size()==0){
		cout << -1 << endl;
		return false;
	}
	printf("%d\n", v[0].man);
	return true;
}


int main(){
	while(1){
		RI(r);
		RI(c);

		cout << "-----------------------" << endl;

		if(r==0){
			break;
		}
		clr();
		for(int i=0; i<r; i++){
			scanf("%s", ma[i]);
		}	
		if(bfs()){
			
		}
	}
}

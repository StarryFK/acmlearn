#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
#define LL long long

LL ma[3][3];
inline LL labs(LL num){
	if(num<0){
		return -num;
	}else{
		return num;
	}
}
struct St{
	LL phase;
	LL dis;
	LL f;
};
bool operator<(const St &a, const St &b){
	return a.dis+a.f > b.dis+b.f;
}
priority_queue<St> pq;
inline LL calcphase(){
	LL ans=0;
	for(LL i=0; i<9; i++){
		ans = ans*9 + ma[i/3][i%3];
	}
	return ans;
}
inline LL getf(){
	LL ans = 0;
	for(LL i=0; i<9; i++){
		LL x=i/3;
		LL y=i%3;
		LL num = ma[x][y]-1;
		LL tx = num/3;
		LL ty = num%3;
		ans += labs(x-tx) + labs(y-ty);
	}
	return ans;
}
map<LL, LL> dis;
map<LL, bool> vis;
const LL dx[]={-1,1,0,0};
const LL dy[]={0,0,-1,1};
const char dir[]="udlr";
inline bool inrange(LL x, LL y){
	return x>=0 && x<3 && y>=0 && y<3;
}
void phase2ma(LL phase){
	for(LL i=8; i>=0; i--){
		ma[i/3][i%3] = phase%9;
		phase /= 9;
	}
}
map<LL, LL> fromphase;
map<LL, LL> fromd;
LL endphase = 0;
bool astar(){
	while(pq.size()){
		LL phase = pq.top().phase;
		pq.pop();
		if(vis.count(phase)){
			continue;
		}
		vis[phase] = 1;
		phase2ma(phase);

		//for(int i=0; i<3; i++){
		//	for(int j=0; j<3; j++){
		//		cout << ma[i][j];
		//	}
		//	cout << endl;
		//}
		//cout << dis[phase] << endl;

		LL x=0, y=0;
		for(LL i=0; i<9; i++){
			if(ma[i/3][i%3]==0){
				x = i/3;
				y = i%3;
				break;
			}
		}
		for(LL i=0; i<4; i++){
			LL nx = x+dx[i];
			LL ny = y+dy[i];
			if(inrange(nx,ny)){
				swap(ma[x][y], ma[nx][ny]);
				LL nxp = calcphase();
				if(!vis.count(nxp)){
					if(dis.count(nxp) && dis[nxp]<dis[phase]+1){
					}else{
						dis[nxp] = dis[phase]+1;
						pq.push({nxp, dis[nxp], getf()});
						fromphase[nxp] = phase;
						fromd[nxp] = i;
						if(nxp==endphase){
							return true;
						}
					}
				}
				swap(ma[x][y], ma[nx][ny]);
			}
		}
	}
	return false;
}
void print(LL phase){
	if(!fromphase.count(phase)){
		return;
	}
	print(fromphase[phase]);
	printf("%c", dir[fromd[phase]]);

	//cout << endl;
	//phase2ma(phase);
	//for(int i=0; i<3; i++){
	//	for(int j=0; j<3; j++){
	//		cout << ma[i][j];
	//	}
	//	cout << endl;
	//}
	//cout << endl;
}

int main(){
	for(int i=0; i<8; i++){
		ma[i/3][i%3] = i+1;
	}
	ma[2][2]=0;
	endphase = calcphase();
	for(LL i=0; i<9; i++){
		char ch = getchar();
		if(ch>='0' && ch<='9'){
			ma[i/3][i%3] = ch-'0';
		}else{
			ma[i/3][i%3] = 0;
		}
		getchar();
	}
	pq.push({calcphase(), 0, getf()});
	dis[calcphase()] = 0;
	if(astar()){
		print(endphase);
		puts("");
	}else{
		puts("unsolvable");
	}
}

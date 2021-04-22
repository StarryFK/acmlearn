#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define RI(x) scanf("%d", &x)

struct St{
	int city;
	int fuel;
};
priority_queue<St> pq;
int cost[1005][105];
bool vis[1005][105];
int n,m;
int head[1005], nx[10005], len[10005], to[10005], tot=0;
int p[1005];
bool operator<(const St &a, const St &b){
	return cost[a.city][a.fuel] < cost[b.city][b.fuel];
}
void clr(){
	memset(cost, 0x3f, sizeof(cost));
	memset(vis, 0, sizeof(vis));
	while(pq.size()){
		pq.pop();
	}
}
void init(){
	clr();
	memset(head, -1, sizeof(head));
	memset(nx, -1, sizeof(nx));
	memset(len, -1, sizeof(len));
	tot=0;
}
void addedge(int x, int y, int d){

	//cout << x << y << d << endl;

	nx[tot] = head[x];
	head[x] = tot;
	to[tot] = y;
	len[tot] = d;
	tot++;
}
int bfs(int s, int e, int c){
	clr();
	cost[s][0]=0;
	pq.push({s,0});
	while(pq.size()){
		int city=pq.top().city;
		int fuel=pq.top().fuel;
		pq.pop();
		if(vis[city][fuel]){
			continue;
		}
		vis[city][fuel] = 1;

		cout << city << ' ' << fuel << endl;

		if(fuel+1<=c){
			cost[city][fuel+1] = min(cost[city][fuel+1], cost[city][fuel] + p[city]);
			pq.push({city, fuel+1});
		}
		for(int ed=head[city]; ed!=-1; ed=nx[ed]){

			cout << city << ' ' << to[ed] <<' ' <<  len[ed] << endl;

			if(len[ed] <= fuel){
				cost[to[ed]][fuel-len[ed]] = min(cost[to[ed]][fuel-len[ed]], cost[city][fuel]);
				pq.push({to[e], fuel-len[ed]});

				cout << "push" << endl;

			}
			if(to[ed]==e){
				return cost[to[ed]][fuel-len[ed]];
			}
		}
	}
	return -1;
}

int main(){
	RI(n);
	RI(m);
	init();
	for(int i=0; i<n; i++){
		RI(p[i]);
	}
	for(int i=0; i<m; i++){
		int u,v,d;
		RI(u);
		RI(v);
		RI(d);
		addedge(u,v,d);
		addedge(v,u,d);
	}
	int q;
	RI(q);
	while(q--){
		int s,e,c;
		RI(c);
		RI(s);
		RI(e);
		int res = bfs(s,e,c);
		if(res!=-1){
			printf("%d\n", res);
		}else{
			puts("impossible");
		}
	}
}


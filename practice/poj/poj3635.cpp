#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define RI(x) scanf("%d", &x)
#define INF 0x3f3f3f3f

struct St{
	int city;
	int fuel;
	int cost;
};
priority_queue<St> pq;
int cost[1005][105];
bool vis[1005][105];
int n,m;
int head[1005], nx[20005], len[20005], to[20005], tot=0;
int p[1005];

bool operator<(const St &a, const St &b){
	return a.cost > b.cost;
}
inline void clr(){
	memset(cost, 0x3f, sizeof(cost));
	memset(vis, 0, sizeof(vis));
	while(pq.size()){
		pq.pop();
	}
}
inline void init(){
	clr();
	memset(head, -1, sizeof(head));
	tot=0;
}
inline void addedge(int x, int y, int d){
	to[tot] = y;
	len[tot] = d;
	nx[tot] = head[x];
	head[x] = tot++;
}
inline int bfs(int s, int e, int c){
	clr();
	cost[s][0]=0;
	pq.push({s,0,0});
	while(pq.size()){
		int city=pq.top().city;
		int fuel=pq.top().fuel;
		pq.pop();
		if(city==e){
			return cost[city][fuel];
		}
		if(vis[city][fuel]){
			continue;
		}
		vis[city][fuel] = 1;
		//cout << city << ' ' << fuel << ' ' << cost[city][fuel] << endl;
		if(fuel+1<=c && !vis[city][fuel+1] && cost[city][fuel] + p[city] < cost[city][fuel+1]){
			cost[city][fuel+1] = cost[city][fuel] + p[city];
			pq.push({city, fuel+1, cost[city][fuel+1]});
			//cout << "push " << city << ' ' << fuel+1 << ' ' << cost[city][fuel+1] << endl;
		}
		for(int ed=head[city]; ed!=-1; ed=nx[ed]){
			//cout << city << ' ' << to[ed] <<' ' <<  len[ed] << endl;
			int w=len[ed];
			int t=to[ed];
			if(w <= fuel && !vis[t][fuel-w] && cost[city][fuel] < cost[t][fuel-w]){
				cost[t][fuel-w] = cost[city][fuel];
				pq.push({t, fuel-w, cost[t][fuel-w]});
				//cout << "push " << to[ed] << ' ' << fuel-len[ed] << ' ' << cost[to[ed]][fuel-len[ed]] << endl;
			}
		}
		//cout << "size " << pq.size() << endl;
	}
	return INF;
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
		if(res<INF){
			printf("%d\n", res);
		}else{
			puts("impossible");
		}
	}
}


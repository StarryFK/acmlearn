#include <iostream>
#include <cstring>
#include <cstdio>
#define RI(x) scanf("%d", &x)
#define RLL(x) scanf("%lld", &x)
#define ll long long
#include <vector>
using namespace std;

vector<int> to[200005];
ll gt[200005];
ll gd[200005];
ll valt[200005];
ll vald[200005];
int gid=0;
int visit[200005];

void dfs(int root){
	if(visit[root]){
		return;
	}
	visit[root] = 1;

	//cout << root << ' ' << valt[root] << ' ' << vald[root] << endl;

	gt[gid] += valt[root];
	gd[gid] += vald[root];
	for(auto i : to[root]){
		dfs(i);
	}
}


int main(){
	int n,m;
	while(~RI(n)){
		RI(m);
		memset(visit, 0, sizeof(visit));
		memset(gt, 0, sizeof(gt));
		memset(gd, 0, sizeof(gd));
		memset(valt, 0, sizeof(valt));
		memset(vald, 0, sizeof(vald));
		for(int i=1; i<=n; i++){
			to[i].clear();
		}
		gid=0;
		for(int i=1; i<=n; i++){
			RLL(valt[i]);
		}
		for(int i=1; i<=n; i++){
			RLL(vald[i]);
		}
		int f,t;
		for(int i=0; i<m; i++){
			RI(f);
			RI(t);
			to[f].push_back(t);
			to[t].push_back(f);
		}
		for(int i=1; i<=n; i++){
			if(visit[i]==0){
				gid++;
				dfs(i);
			}
		}
		bool ok = true;
		for(int i=1; i<=gid; i++){
			
			//cout << gt[i] << ' ' << gd[i] << endl;

			if(gt[i]!=gd[i]){
				ok = false;
			}
		}
		if(ok){
			puts("yingyingying");
		}else{
			puts("azhe");
		}
	}
}

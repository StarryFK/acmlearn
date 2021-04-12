#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

int coic[1000], ctot=0;
bool vis[1000];
int n,l,r,s;
int sum[1000];

void pt(int c){
	for(int i=0; i<c; i++){
		printf("%d ", coic[i]);
	}
	puts("");
}

bool dfs(int cur, int tot){

	//pt(ctot);

	if(tot==s && ctot == r-l+1){
		return true;
	}
	if(cur==0){
		return false;
	}
	if(tot + sum[cur] < s){
		return false;
	}
	if(tot+cur <= s && ctot<r-l+1){
		coic[ctot++]=cur;
		vis[cur]=1;
		if(dfs(cur-1, tot+cur)){
			return true;
		}
		vis[cur]=0;
		ctot--;
	}
	if(dfs(cur-1, tot)){
		return true;
	}
	return false;
}

int main(){
	int t;
	RI(t);
	sum[1]=1;
	for(int i=2; i<1000; i++){
		sum[i] = sum[i-1] + i;
	}
	while(t--){
		RI(n);
		RI(l);
		RI(r);
		RI(s);
		memset(vis, 0, sizeof(vis));
		ctot=0;
		if(dfs(n,0)){
			int p=1;
			for(int i=1; i<l; i++){
				for(;vis[p]; p++);
				printf("%d ", p++);
			}
			for(int i=0; i<ctot; i++){
				printf("%d ", coic[i]);
			}
			for(int i=r+1; i<=n; i++){
				for(;vis[p]; p++);
				printf("%d ", p++);
			}
			puts("");
		}else{
			puts("-1");
		}
	}
}

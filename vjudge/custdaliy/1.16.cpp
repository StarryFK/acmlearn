#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool visit[25];
int buf[25];
bool prime[50];
int n;

void getPrime(){
	memset(prime, 1, sizeof(prime));
	prime[0]=0;
	prime[1]=0;
	for(int i=2; i<50; i++){
		if(prime[i]){
			for(int j=2; i*j<50; j++){
				prime[i*j]=0;
			}
		}
	}
}

void dfs(int cur){
	if(cur>n){
		if(prime[buf[n]+buf[1]]){
			for(int i=1; i<=n; i++){
				printf("%s", i==1 ? "" : " ");
				printf("%d", buf[i]);
			}
			puts("");
		}
		return;
	}
	for(int i=1; i<=n; i++){
		if(!visit[i] && prime[buf[cur-1]+i]){
			buf[cur] = i;
			visit[i] = 1;
			dfs(cur+1);
			visit[i] = 0;
		}
	}
}

int main(){
	int kase=0;
	getPrime();
	buf[1] = 1;
	visit[1] = 1;
	while(~scanf("%d", &n)){
		printf("Case %d:\n", ++kase);
		dfs(2);
		puts("");
	}
}

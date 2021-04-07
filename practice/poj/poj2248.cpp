#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define RI(x) scanf("%d", &x)

bool vis[200];
int out[200];
int n;

inline void printo(int m){
	for(int i=1; i<=m; i++){
		printf("%d ", out[i]);
	}
	puts("");
}

bool dfs(int cur, int dst){

	//cout << cur << ' ' << dst << endl;
	//printo(cur);

	if(cur>dst){
		return false;
	}
	if(cur==1){
		out[1]=1;
		if(out[1]==n){
			printo(1);
			return true;
		}
		return dfs(cur+1, dst);
	}
	for(int i=cur-1; i>=1; i--){
		for(int j=i; j>=1; j--){
			if(!vis[out[i]+out[j]] && out[i]+out[j]>out[cur-1]){
				vis[out[i]+out[j]]=1;
				out[cur]=out[i]+out[j];
				if(out[cur]==n){
					printo(cur);
					return true;
				}
				if(out[cur]>n){
					return false;
				}
				if(dfs(cur+1, dst)){
					return true;
				}
				vis[out[i]+out[j]]=0;
			}
		}
	}
	return false;
}

int main(){
	while(1){
		RI(n);
		if(n==0){
			break;
		}
		memset(vis, 0, sizeof(vis));
		int i;
		for(i=1; !dfs(1,i); i++);
	}
}

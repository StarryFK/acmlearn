#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define RI(x) scanf("%d", &x)
const int E5 = 2*1e5+5;
bool vis[E5];

int q[E5];

int main(){
	int t;
	RI(t);
	while(t--){
		int n;
		RI(n);
		for(int i=0; i<n ;i++){
			RI(q[i]);
		}
		memset(vis, 0, (n+5)*sizeof(bool));
		for(int i=0; i<n; i++){
			if(!vis[q[i]]){
				printf("%d ", q[i]);
				vis[q[i]]=1;
				continue;
			}
			for(int j=1; j<=n; j++){
				if(!vis[j]){
					vis[j]=1;
					printf("%d ", j);
					break;
				}
			}
		}
		puts("");
		memset(vis, 0, (n+5)*sizeof(bool));
		for(int i=0; i<n; i++){
			for(int j=q[i]; j>=1; j--){
				if(!vis[j]){
					vis[j]=1;
					printf("%d ", j);
					break
				}
			}
		}
		puts("");
	}
}

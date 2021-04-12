#include <iostream>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

char ma[405][405];

int main(){
	int t;
	RI(t);
	while(t--){
		int x[2],y[2],tot=0;
		int n;
		RI(n);
		getchar();
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				ma[i][j] = getchar();
				if(ma[i][j]=='*'){
					x[tot]=i;
					y[tot]=j;
					tot++;
				}
			}
			getchar();
		}
		if(x[0]!=x[1] && y[0]!=y[1]){
			ma[x[0]][y[1]] = '*';
			ma[x[1]][y[0]] = '*';
		}else if(x[0]==x[1]){
			if(x[0]>0){
				ma[x[0]-1][y[0]] = '*';
				ma[x[1]-1][y[1]] = '*';
			}else{
				ma[x[0]+1][y[0]] = '*';
				ma[x[1]+1][y[1]] = '*';
			}
		}else if(y[0]==y[1]){
			if(y[0]>0){
				ma[x[0]][y[0]-1] = '*';
				ma[x[1]][y[1]-1] = '*';
			}else{
				ma[x[0]][y[0]+1] = '*';
				ma[x[1]][y[1]+1] = '*';
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%c", ma[i][j]);
			}
			puts("");
		}
	}
}

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

bool a[30][30], b[30];

int main(){
	int K;
	RI(K);
	while(K--){
		int n;
		RI(n);
		memset(a, 0, sizeof(a));
		for(int i=1; i<=n; i++){
			a[i][i]=1;
		}
		for(int i=1; i<=n; i++){
			int tmp;
			RI(tmp);
			b[i]=tmp;
		}
		for(int i=1; i<=n; i++){
			int tmp;
			RI(tmp);
			b[i] ^= tmp;
		}
		while(1){
			int x,y;
			RI(y);
			RI(x);
			if(x==0 && y==0){
				break;
			}
			a[x][y]=1;
		}

		//for(int i=1; i<=n; i++){
		//	for(int j=1; j<=n; j++){
		//		cout << a[i][j];
		//	}
		//	cout << endl;
		//}

		int fcnt=0;
		for(int i=1; i<=n; i++){
			bool found=0;
			for(int j=i; j<=n; j++){
				if(a[j][i]==1){
					for(int k=1; k<=n; k++){
						swap(a[i][k], a[j][k]);
					}
					swap(b[i], b[j]);
					found=1;
					break;
				}
			}
			if(found){
				for(int j=1; j<=n; j++){
					if(i==j){
						continue;
					}
					if(a[j][i]==1){
						for(int k=1; k<=n; k++){
							a[j][k] ^= a[i][k];
						}
						b[j] ^=  b[i];
					}
				}
			}else{
				fcnt++;
			}
		}

		//for(int i=1; i<=n; i++){
		//	for(int j=1; j<=n; j++){
		//		cout << a[i][j];
		//	}
		//	cout << endl;
		//}

		bool imp=0;
		for(int i=1; i<=n; i++){
			bool has=0;
			for(int j=1; j<=n; j++){
				if(a[i][j]==1){
					has=1;
					break;
				}
			}
			if(!has && b[i]){
				imp=1;
				break;
			}
		}
		if(imp){
			puts("Oh,it's impossible~!!");
		}else{
			printf("%d\n", 1<<fcnt);
		}
	}
}

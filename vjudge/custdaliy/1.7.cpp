#include <iostream>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

int main(){
	int n;
	RI(n);
	int sum=0, tmp;
	for(int i=0; i<n; i++){
		RI(tmp);
		sum ^= tmp;
	}
	if(n%2){
		puts("YES");
		printf("%d\n", n-2);
		for(int i=1; i<=n/2; i++){
			printf("%d %d %d\n", i*2-1, i*2, n);
		}
		for(int i=1; i<n/2; i++){
			printf("%d %d %d\n", i*2-1, i*2, n);
		}
	}else{
		if(sum==0){
			puts("YES");
			n--;
			printf("%d\n", n-2);
			for(int i=1; i<=n/2; i++){
				printf("%d %d %d\n", i*2-1, i*2, n);
			}
			for(int i=1; i<n/2; i++){
				printf("%d %d %d\n", i*2-1, i*2, n);
			}
		}else{
			puts("NO");
		}
	}
}

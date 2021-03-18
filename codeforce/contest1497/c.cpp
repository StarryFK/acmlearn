#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)
int main(){
	int t;
	RI(t);
	while(t--){
		int n,k;
		RI(n);
		RI(k);
		if(n%3==0){
			printf("%d %d %d\n", n/3, n/3, n/3);
		}else{
			if(n%2){
				printf("%d %d %d\n", 1, (n-1)/2, (n-1)/2);
			}else{
				if(n%4==0){
					printf("%d %d %d\n", n/2, n/4, n/4);
				}else{
					printf("%d %d %d\n", 2, 2*(n/2-1)/2, 2*(n/2-1)/2);
				}
			}
		}
	}
}

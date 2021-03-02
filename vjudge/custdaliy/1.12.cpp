#include <iostream>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

int main(){
	int n,k;
	while(~RI(n)){
		k = n/2;
		if(n%2){
			printf("%d\n", k*(k-1)/2 + k*(k+1)/2);
		}else if(n==2){
			puts("1");
		}else{
			printf("%d\n", k*(k-1));
		}
	}
}

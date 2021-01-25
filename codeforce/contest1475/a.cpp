#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)
#define RI(x) scanf("%d", &x)

int main(){
	int t;
	RI(t);
	LL num;
	bool st;
	while(t--){
		st=0;
		RLL(num);
		if(num%2){
			st=1;
		}else{
			for(LL i=2; i<=sqrt(num); i++){
				if(num%i==0 && (i%2==1 || (num/i % 2==1))){
					st=1;
					break;
				}
				while(num%i==0){
					num/=i;
				}
			}
		}
		if(st){
			puts("YES");
		}else{
			puts("NO");
		}
	}
}



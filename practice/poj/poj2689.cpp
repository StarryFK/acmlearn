#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)

bool cmps2[1000005];
bool cmps1[(1<<16)+5];
LL p[6000], pcnt=0;
inline void init(){
	LL n=1<<16;
	for(LL i=2; i<=n; i++){
		if(cmps1[i]){
			continue;
		}
		p[pcnt++] = i;
		for(LL j=i; j*i<=n; j++){
			cmps1[j*i]=1;
		}
	}
}

int main(){
	init();
	LL l,u;
	while(~RLL(l)){
		RLL(u);
		memset(cmps2, 0, sizeof(cmps2));
		if(l<2){
			cmps2[1-l]=1;
		}
		for(LL i=0; i<pcnt; i++){
			LL pr = p[i];
			for(LL j=(l+pr-1)/pr; j*pr<=u; j++){
				if(j==1){
					continue;
				}
				cmps2[j*pr-l]=1;
			}	
		}
		LL c1=-1, c2=-1, cv=0x3f3f3f3f3f3f3f3f, d1=-1, d2=-1, dv=0;
		LL last=u-l;
		for(LL i=0; i<=u-l; i++){
			if(cmps2[i]==0){
				last = i;
				break;
			}
		}
		for(LL i=last+1; i<=u-l; i++){
			if(cmps2[i]==0){
				if(i-last > dv){
					d1 = last;
					d2 = i;
					dv = i-last;
				}
				if(i-last < cv){
					c1 = last;
					c2 = i;
					cv = i-last;
				}
				last = i;
			}
		}
		if(c1==-1){
			puts("There are no adjacent primes.");
		}else{
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", c1+l, c2+l, d1+l, d2+l);
		}
	}
}	

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)

inline void mamul(LL a[2][2], LL b[2][2]){
	LL ans[2][2]={0,0,0,0};
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % 10000;
			}
		}
	}
	memcpy(a, ans, sizeof(ans));
}
inline void mapow(LL a[2][2], LL n){
	LL ans[2][2]={1,0,1,0};
	if(n==0){
		memcpy(a, ans, sizeof(ans));
		return;
	}
	for(; n; n>>=1){
		if(n&1){
			mamul(ans, a);
		}
		mamul(a, a);
	}
	memcpy(a, ans, sizeof(ans));
}

int main(){
	LL n;
	while(~RLL(n)){
		if(n==-1){
			break;
		}
		LL ma[2][2]={1,1,1,0};
		mapow(ma, n);
		printf("%lld\n", ma[0][1]);
	}
}

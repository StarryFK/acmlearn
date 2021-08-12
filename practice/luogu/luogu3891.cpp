#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
#define RLL(x) scanf("%lld", &x)

LL f[1005][1005];
LL a[1005], b[1005];

int main(){
	LL n,m,t;
	RLL(n);
	RLL(m);
	RLL(t);
	if(m>=t){
		puts("0");
		return 0;
	}
	memset(f, 0x3f, sizeof(f));
	for(LL i=0; i<n; i++){
		RLL(a[i]);
		RLL(b[i]);
	}
	f[m][0] = 0;
	for(LL w=0; w<=t; w++){
		for(LL r=0; r<=t; r++){
			LL nr = min(r+w, t);
			f[nr][w] = min(f[r][w]+1, f[nr][w]);
			for(LL i=0; i<n; i++){
				if(r>=a[i]){
					nr = r-a[i];
					LL nw = min(w+b[i], t);
					f[nr][nw] = min(f[r][w], f[nr][nw]);
				}
			}
		}
	}
	LL ans = INF;
	for(LL i=0; i<=t; i++){
		ans = min(f[t][i], ans);
	}
	printf("%lld\n", ans);
	//for(LL i=0; i<=t; i++){
	//	for(LL j=0; j<=t; j++){
	//		printf("%4lld", f[i][j]>=INF ? 66 : f[i][j]);
	//	}
	//	cout <<endl;
	//}
}

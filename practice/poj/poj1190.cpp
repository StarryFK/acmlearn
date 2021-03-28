#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)
#define LLINF 0x3f3f3f3f3f3f3f3f

LL h[25];
LL r[25];
LL n,m;
LL ans=LLINF;

LL limv[25];
LL lims[25];

inline void init(){
	for(int i=1; i<25; i++){
		limv[i] = limv[i-1] + i*i*i;
		lims[i] = lims[i-1] + i*i*2;
	}
}

void dfs(LL dep, LL s, LL v){

	//cout << dep << endl;

	if(dep==0){
		if(v==n){
			ans = min(ans, s+r[m]*r[m]);

			//cout << s+r[m]*r[m] << endl;
		}
		return;
	}
	for(LL curr=min(r[dep+1]-1, (LL)sqrt(n-v)); curr>=dep; curr--){
		for(LL curh=min(h[dep+1]-1, (LL)((n-v)/curr/curr)); curh>=dep; curh--){

			//cout << curr << ' ' << curh << ' ' << r[m] << ' ' << ans << endl;

			r[dep]=curr;
			h[dep]=curh;
			if(v+curr*curr*curh+limv[dep-1] > n){
				continue;
			}
			if(v+dep*curr*curr*curh < n){
				continue;
			}
			if(s+curr*curh*2+lims[dep-1]+r[m]*r[m] > ans){
				continue;
			}
			if(2*(n-v)/r[dep]+s+r[m]*r[m] > ans){
				continue;
			}
			dfs(dep-1, s+2*curr*curh, v+curr*curr*curh);
		}
	}
}

int main(){
	RLL(n);
	RLL(m);
	memset(r, 0x3f, sizeof(r));
	memset(h, 0x3f, sizeof(h));
	init();
	dfs(m, 0, 0);
	if(ans==LLINF){
		puts("0");
	}else{
		printf("%lld\n", ans);
	}
}

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define RI(x) scanf("%d", &x)
#define LL long long
#define RLL(x) scanf("%lld", &x)
const int EE7 = 1e7+5;

int fa[EE7];
LL res[EE7];

void initfa(){
	for(int i=0; i<EE7; i++){
		fa[i] = i;
	}
}

int getfa(int i){
	if(fa[i]==i){
		return i;
	}else{
		return fa[i] = getfa(fa[i]);
	}
}

void uni(int a, int b){
	if(getfa(a)!=getfa(b)){
		res[getfa(b)] += res[getfa(a)] - 2;
		fa[getfa(a)] = getfa(b);
	}else{
		res[getfa(a)] -= 2;
	}
}

int main(){
	int n,m;
	RI(n);
	RI(m);
	initfa();
	for(int i=1; i<=n; i++){
		RLL(res[i]);
	}
	int u,v;
	for(int i=1; i<=m; i++){
		RI(u);
		RI(v);
		uni(u,v);

		//cout << u << ' ' << getfa(u) << ' ' << res[getfa(u)] << endl;
		//cout << v << ' ' << getfa(v) << ' ' << res[getfa(v)] << endl;

	}
	LL tot0=0, tot1=0, totx=0;
	for(int i=1; i<=n; i++){

		//cout << getfa(i) << ' ' << res[getfa(i)] << endl;

		if(getfa(i)==i){
			if(res[i]==0){
				tot0++;
			}else if(res[i]==1){
				tot1++;
			}else{
				totx++;
			}
		}
	}
	LL ttot = tot1 + tot0 + totx;

	//cout << tot0 << tot1 << totx << endl;

	bool st=0;
	if(ttot==1){
		st=1;
	}
	if(ttot==2 && tot0==0){
		st=1;
	}
	if(ttot>=3 && tot0==0 && tot1<=2){
		st=1;
	}
	if(st){
		printf("%lld\n", ttot-1);
	}else{
		puts("-1");
	}
}

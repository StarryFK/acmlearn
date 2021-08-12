#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)
#define RD(x) scanf("%lf", &x)

int fa[1005];
double ra[1005];

inline bool eq(double a, double b){
	return abs(a-b) < 1e-9;
}
void init(int n){
	for(int i=0; i<=n; i++){
		fa[i] = i;
		ra[i] = 1;
	}
}
int getfa(int p){
	if(fa[p]==p){
		return p;
	}else{
		int f = getfa(fa[p]);
		ra[p] *= ra[fa[p]];
		fa[p] = f;
		return f;
	}
}
bool uni(int a, int b, double u, double v){
	//cout << a << b << endl;
	if(getfa(a) == getfa(b)){
		//cout << ra[a] << ' ' << ra[b] << ' ' << u << ' '<< v << endl;
		if(eq(ra[a]/ra[b], u/v)){
			return 1;
		}else{
			return 0;
		}
	}else{
		fa[a] = b;
		ra[a] = u/v;
		return 1;
	}
}

int main(){
	int t;
	RI(t);
	for(int kase=1; kase<=t; kase++){
		int N,M;
		RI(N);
		RI(M);
		init(N);
		bool ok = 1;
		for(int i=0; i<M; i++){
			int a,b;
			double x,y;
			RI(a);
			RI(b);
			RD(x);
			RD(y);
			if(!uni(a,b,x,y)){
				ok = 0;
			}
		}
		printf("Case #%d: %s\n", kase, ok ? "Yes" : "No");
	}
}


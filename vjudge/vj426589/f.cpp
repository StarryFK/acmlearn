#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)
#define RI(x) scanf("%d", &x)

const int E5 = 1e5+5;

LL sum[E5];

//inline LL log2l(LL num){
//	if(num==0){
//		return 0;
//	}else{
//		return log2(num);
//	}
//}

LL p2[36];

inline void initeq(){
	LL mul=1;
	p2[0] = 1;
	for(int i=1; i<=35; i++){
		mul *= 2;
		p2[i] = mul;
	}
}

inline bool eqlog(LL x, LL y){
	if(x==0){
		if(y==0){
			return true;
		}else{
			return false;
		}
	}else{
		if(x>=p2[y] && p2[y+1]>x){
			return true;
		}else{
			return false;
		}
	}
}

inline bool ltlog(LL x, LL y){
	if(x==0){
		if(y>0){
			return true;
		}else{
			return false;
		}
	}
	if(p2[y]>x){
		return true;
	}else{
		return false;
	}
}

//inline bool gtlog(LL x, LL y){
//	if(p2[y]<x){
//		return true;
//	}else{
//		return false;
//	}
//}

inline LL getSum(int i, int j){
	return sum[j] - sum[i-1];
}

int main(){
	initeq();
	int t;
	RI(t);
	int n;
	while(t--){
		RI(n);
		for(int k=1; k<=n; k++){
			RLL(sum[k]);
			sum[k] += sum[k-1];
		}
		LL ans=0;
		for(int lo=0; lo<=33; lo++){

			cout << lo << endl;

			LL ijsum = 0;
			int i=1, jl=1, jr=1;
			for(; i<=n; i++){
				jl = max(i, jl);
				while(ltlog(getSum(i, jl) ,lo) && jl<=n){
					jl++;
				}
				jr = max(jl, jr);
				while((ltlog(getSum(i, jr), lo) || eqlog(getSum(i, jr), lo)) && jr<=n){
					jr++;
				}

				cout << i << ' ' << jl << ' ' << jr << endl;

				if(jl <= n && eqlog(getSum(i, jl), lo)){
					ijsum += i*(jr-jl) + (jl+jr-1)*(jr-jl)/2;
				}else{
					break;
				}
			}

			cout << "ij:" << ijsum << endl;
			ans += (lo+1) * (ijsum);
		}
		printf("%lld\n", ans);
	}
}

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

LL p2[40];

inline void initp2(){
	LL mul=1;
	p2[0] = 0;
	for(int i=1; i<=39; i++){
		mul *= 2;
		p2[i] = mul;
	}
}

//inline bool eqlog(LL x, int y){
//	if(x==0){
//		if(y==0){
//			return true;
//		}else{
//			return false;
//		}
//	}else{
//		if(x>=p2[y] && p2[y+1]>x){
//			return true;
//		}else{
//			return false;
//		}
//	}
//}
//
//inline bool ltlog(LL x, int y){
//	if(x==0){
//		if(y>0){
//			return true;
//		}else{
//			return false;
//		}
//	}
//	if(p2[y]>x){
//		return true;
//	}else{
//		return false;
//	}
//}

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
	initp2();

	//for(LL i=0; i<40; i++){
	//	cout << p2[i] << endl ;
	//}

	LL t;
	RLL(t);
	while(t--){
		LL n;
		RLL(n);
		sum[0]=0;
		for(LL k=1; k<=n; k++){
			RLL(sum[k]);
			sum[k] += sum[k-1];
		}
		LL ans=0;
		for(LL lo=0; lo<=36; lo++){

			//cout << lo << endl;

			LL ijsum = 0;
			int i=1, jl=1, jr=1;
			for(; i<=n; i++){
				jl = max(i, jl);
				while(getSum(i, jl)<p2[lo] && jl<=n){
					jl++;
				}
				jr = max(jl, jr);
				while(getSum(i, jr)<p2[lo+1] && jr<=n){
					jr++;
				}

				//cout << i << ' ' << jl << ' ' << jr << endl;

				if(jl <= n && getSum(i, jl) >= p2[lo] && getSum(i, jl) < p2[lo+1]){
					ijsum += (LL)i*(jr-jl) + (LL)(jl+jr-1)*(jr-jl)/2;
				}
			}

			//if(ijsum!=0){
			//	printf("%d\n%lld\n", lo, ijsum);
			//}
			
			ans += (lo+1) * (ijsum);
		}
		printf("%lld\n", ans);
	}
}

#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)

int main(){
	LL t;
	RLL(t);
	LL m,n,k,q,ans;
	while(t--){
		RLL(m);
		RLL(n);
		RLL(k);
		RLL(q);
		m = m%(k+1);
		n = n%(k+1);
		ans = m^n ? 1 : 0;
		ans = q ? ans : (!ans);

		//cout << m << n << ans << endl;

		if(ans){
			puts("YES");
		}else{
			puts("NO");
		}
	}
}

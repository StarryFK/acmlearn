#include <iostream>
using namespace std;
#define LL long long

int main(){
	LL n,k;
	cin >> n >> k;
	LL ans = n*k;
	for(LL st=1, ed=1; st<=n; st = ed+1){
		LL l=st, r=n, mid=(l+r+1)>>1;
		while(l<r){
			mid = (l+r+1)>>1;
			if(k/mid == k/st){
				l = mid;
			}else{
				r = mid-1;
			}

			//cout << l << ' ' << r << endl;

		}
		ed=l;

		//cout << (k/st) << ' ' << st <<  ' ' << ed << endl;

		ans -= (st+ed)*(ed-st+1)/2*(k/st);
	}
	cout << ans << endl;
}

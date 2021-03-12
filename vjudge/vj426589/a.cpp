include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)
#define INF 0x3f3f3f3f3f3f3f3f
#define RI(x) scanf("%d", &x)

const int E5 = 1e5+5;

LL arr[E5];
pair<LL, int> sum[E5];

LL sbabs(LL num){
	if(num<0){
		return -num;
	}else{
		return num;
	}
}

int main(){
	int n,k;
	while(1){
		RI(n);
		RI(k);
		if(n==0){
			break;
		}
		for(int i=1; i<=n; i++){
			RLL(arr[i]);
		}
		for(int i=2; i<=n; i++){
			arr[i] += arr[i-1];
		}
		for(int i=0; i<=n; i++){
			sum[i] = make_pair(arr[i], i);
		}
		sort(sum, sum+n+1);
		for(int i=0; i<k; i++){
			LL t;
			RLL(t);
			int l=0, r=1;
			int ansl=0, ansr=0;
			LL ans=INF;
			while(r<n+1){
				LL diff = sum[r].first - sum[l].first;
				if(sbabs(diff-t) < sbabs(ans-t)){
					ansl = min(sum[r].second, sum[l].second) + 1;
					ansr = max(sum[r].second, sum[l].second);
					ans = diff;
				}
				if(diff==t){
					break;
				}else if(diff>t){
					if(r-l==1){
						l++;
						r++;
					}else{
						l++;
					}
				}else{
					r++;
				}
			}
			printf("%lld %d %d\n", ans, ansl, ansr);
		}
	}
}

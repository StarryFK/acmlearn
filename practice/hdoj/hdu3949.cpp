#include <iostream>
#include <cstdio>
using namespace std;
#define ULL unsigned long long
#define RULL(x) scanf("%llu", &x)

ULL a[10005];

inline bool getbit(ULL num, ULL pos){
	return (num>>pos)&1;
}

int main(){
	ULL t;
	RULL(t);
	for(ULL kase=1; kase<=t; kase++){
		ULL n;
		RULL(n);
		for(ULL i=0; i<n; i++){
			RULL(a[i]);
		}
		ULL dim=0;
		bool zero=0;
		for(ULL i=0; i<n; i++){
			dim = i+1;
			for(ULL j=i+1; j<n; j++){
				if(a[j] > a[i]){
					swap(a[j], a[i]);
				}
			}
			if(a[i]==0){
				zero=1;
				//dim--;
				break;
			}
			for(int k=64; k>=0; k--){
				if(getbit(a[i],k)){
					for(ULL j=0; j<n; j++){
						if(i==j){
							continue;
						}
						if(getbit(a[j], k)){
							a[j] ^= a[i];
						}
					}
					break;
				}
			}
		}

		cout << "dim" << dim << endl;
		for(int i=0; i<n; i++){
			cout << a[i] << endl;
		}

		ULL q;
		RULL(q);
		printf("Case #%llu:\n", kase);
		while(q--){
			ULL k;
			RULL(k);
			if(zero){
				k--;
			}
			if(k>=(1llu<<dim)){
				puts("-1");
				continue;
			}
			ULL ans=0;
			for(ULL pos=1; k; k>>=1,pos++){
				if(k&1){
					ans ^= a[dim-pos];
				}
			}
			printf("%llu\n", ans);
		}
	}
}

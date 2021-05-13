nclude <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
const LL E9 = 1e9;

LL plist[5000], plcnt=0;
bool cmps[50000];

void init(){
	for(int i=2; i<=sqrt(2*E9); i++){
		if(cmps[i]){
			continue;
		}
		plist[plcnt++]=i;
		for(int j=i; i*j<=sqrt(2*E9); j++){
			cmps[i*j]=1;
		}
	}
}

int main(){
	LL n;
	init();
	cin >> n;
	while(n--){
		LL a,b,c,d;
		cin >> a >> b >> c >> d;
		LL ans = 1;
		bool once = false;
		for(int i=0; plist[i]<=sqrt(d) || !once; i++){
			LL p = plist[i];
			if(!once && plist[i]>sqrt(d)){
				if(d<=1){
					break;
				}
				p = d;
				once = true;
			}

			//cout << "p " << p << endl;

			if(d%p){
				continue;
			}
			LL pa=0, pb=0, pc=0, pd=0;
			for(; a%p==0; a/=p){
				pa++;
			}
			for(; b%p==0; b/=p){
				pb++;
			}
			for(; c%p==0; c/=p){
				pc++;
			}
			for(; d%p==0; d/=p){
				pd++;
			}

			//cout << "pa "<< pa << pb << pc << pd << endl;

			if(pa==pb && pc==pd && pb<=pd){
				ans *= pd-pb+1;

				//cout << pd-pb+1 << endl;

			}else if(pa==pb && pc<pd && pb<=pd){
				
			}else if(pa>pb && pc==pd && pb<=pd){

			}else if(pa>pb && pc<pd && pb==pd){

			}else{
				ans *= 0;

				//cout << 0 << endl;

				break;
			}
		}
		cout << ans << '\n';
	}
}

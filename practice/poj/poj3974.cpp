#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
#define P 131
#define ull unsigned long long
const int CMAX = 1e6+9;

ull ha[CMAX];
ull rha[CMAX];
ull ppow[CMAX];

char str[CMAX];
int sl;
int ans = 0;

ull getha(int l, int r){
	return ha[r] - ha[l-1] * ppow[r-l+1];
}
ull getrha(int l, int r){
	return rha[l] - rha[r+1] * ppow[r-l+1];
}

void find1(int i){
	int l=0;
	int r = min(i-1, sl-i);
	while(l<r){
		int mid = (l+r+1)>>1;
		if(getha(i-mid, i) != getrha(i, i+mid)){
			r = mid-1;
		}else{
			l = mid;
		}
	}
	ans = max(ans, 1+l*2);
}

void find2(int i){
	int l=1;
	int r=min(i-1, sl-i+1);
	if(getha(i-1,i-1) == getrha(i,i)){
		while(l<r){
			int mid = (l+r+1)>>1;
			if(getha(i-mid, i-1) != getrha(i, i+mid-1)){
				r = mid-1;
			}else{
				l = mid;
			}
		}
		ans = max(ans, l*2);
	}
}

int main(){
	int kase=1;
	ppow[0] = 1;
	for(int i=1; i<=CMAX; i++){
		ppow[i] = ppow[i-1] * P;
	}
	while(~scanf("%s", str)){
		if(str[0]=='E'){
			break;
		}
		ans = 0;
		sl = strlen(str);
		ha[0] = 0;
		for(int i=1; i<=sl; i++){
			ha[i] = ha[i-1]*P + str[i-1] - 'a' + 1;
		}
		rha[sl+1] = 0;
		for(int i=sl; i>0; i--){
			rha[i] = rha[i+1]*P + str[i-1]-'a'+1;
		}
		for(int i=1; i<=sl; i++){
			find1(i);
		}
		for(int i=2; i<=sl; i++){
			find2(i);
		}
		printf("Case %d: %d\n", kase++, ans);
	}
}

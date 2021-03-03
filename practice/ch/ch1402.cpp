#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ull unsigned long long
#define P 131
const int E5 = 3e5+5;

char str[E5];
ull shash[E5];
ull ppow[E5];
int len=0;
int SA[E5];
int Height[E5];

void calHash(){
	ull sum=0;
	ull pow=1;
	for(int i=0; i<len; i++){
		sum = sum * P + str[i]-'a'+1;
		shash[i] = sum;
		ppow[i] = pow;
		pow *= P;
	}
}

ull getHash(int l, int r){
	if(l>r){
		return 0;
	}
	if(l>0){
		return shash[r] - shash[l-1]*ppow[r-l+1];
	}else{
		return shash[r];
	}
}

int getCom(int k1, int k2){
	int r = min(len-k1, len-k2) + 1;
	int l=0;
	int mid;
	while(l<r){
		mid = (l+r+1)>>1;

		//cout << l << ' ' << r << ' ' << mid << endl;

		if(getHash(k1, k1+mid-1) != getHash(k2, k2+mid-1)){
			r = mid-1;
		}else{
			l = mid;
		}
	}

	return l;
}

bool cmp(int a, int b){
	int r = min(len-a, len-b) + 1;
	int l=0;
	int mid;
	while(l<r){
		mid = (l+r+1)>>1;

		//cout << l << ' ' << r << ' ' << mid << endl;

		if(getHash(a, a+mid-1) != getHash(b, b+mid-1)){
			r = mid-1;
		}else{
			l = mid;
		}
	}

	//cout << a << ' ' << b << ' ' << l << endl;

	return str[a+l] < str[b+l];
}

int main(){
	char ch;
	while((ch=getchar())>='A' && ch<='z'){
		str[len++] = ch;
	}
	calHash();
	for(int i=0; i<len; i++){
		SA[i] = i;
	}
	sort(SA, SA+len, cmp);
	for(int i=0; i<len; i++){
		printf("%d ", SA[i]);
	}
	puts("");

	//cout << len << endl;

	for(int i=2; i<=len; i++){
		Height[i] = getCom(SA[i-1], SA[i-2]);
	}

	for(int i=1; i<=len; i++){
		printf("%d ", Height[i]);
	}
	puts("");

	//cout << getCom(9,4) << endl;

}

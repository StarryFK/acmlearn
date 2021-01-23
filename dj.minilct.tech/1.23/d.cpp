#include <iostream>
#include <cstdio>
using namespace std;
#define RS(x) scanf("%s", x)
#define RI(x) scanf("%d", &x)
#define ULL unsigned long long
#define P 131

char s[100005];
ULL ss[100005];
char si[100005];
ULL sis[100005];

int main(){
	int m;
	RI(m);
	RS(s);
	ULL sum=0;
	for(int i=0; i<m; i++){
		sum = sum*P + s[i]-'a'+1;
		ss[i] = sum;
	}
	int n;
	RI(n);
	for(int i=0; i<n; i++){
		RS(si);
		int len = strlen(si);
		sum=0;
		for(int j=0; j<len; j++){
			sum = sum*P + s[i]-'a'+1;
			sis[i] = sum;
		}
	}
}

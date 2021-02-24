#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define RI(x) scanf("%d", &x)
#define LL long long
#define RLL(x) scanf("%lld", &x)
const int EE5 = 1e5+5;

LL arr[EE5];

int main(){
	int n;
	RI(n);
	for(int i=1; i<=n; i++){
		RLL(arr[i]);
	}
	LL tmp;
	for(int i=1; i<=n; i++){
		RLL(tmp);
		arr[i] = (arr[i]-tmp)*(arr[i]-tmp);
	}
	for(int i=1; i<=n; i++){
		arr[i] = arr[i-1] + arr[i];
	}
	int m;
	RI(m);
	int x,y;
	for(int i=0; i<m; i++){
		RI(x);
		RI(y);
		printf("%f\n", sqrt(arr[y]-arr[x-1]));
	}
}

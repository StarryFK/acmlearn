#include <iostream>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)
#define RLL(x) scanf("%lld", &x)

int main(){
	int t;
	RI(t);
	while(t--){
		long long n,m,x;
		RLL(n);
		RLL(m);
		RLL(x);
		long long i = (x-1)%n;
		long long j = (x-1)/n;
		cout << i*m + j + 1 << endl;
	}
}

#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)
#define RI(x) scanf("%d", &x)

int main(){
	int t;
	RI(t);
	while(t--){
		LL num;
		RLL(num);
		while(num%2==0){
			num /= 2;
		}

		//cout << num << endl;

		if(num>1){
			puts("YES");
		}else{
			puts("NO");
		}
	}
}

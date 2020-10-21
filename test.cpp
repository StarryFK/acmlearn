#include <cstdio>
#include <iostream>
#define ull unsigned long long 
using namespace std;

inline int read(){
	int x=0, f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
			ch=getchar();
		}
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int main(){
	int n;
	
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	//while(cin >> n){
	//	cout << n << '\n';
	//}

	while(~scanf("%d", &n)){
		printf("%d\n", n);
	}
}


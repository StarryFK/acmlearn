#include <iostream>
using namespace std;
#define LL long long 

LL exgcd(LL a, LL b, LL &x, LL &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	LL d = exgcd(b, a%b, x, y);
	LL tmp = x;
	x = y;
	y = tmp - (a/b)*y;
	return d;
}

int main(){
	LL a,b,x,y;
	cin >> a >> b;
	exgcd(a,b,x,y);
	x = (x%b+b)%b;
	cout << x << endl;
}

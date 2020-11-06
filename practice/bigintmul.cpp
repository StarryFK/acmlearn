#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;
const int BGMOD	= 10000;

struct BigInt{
	vector<int> v;
	BigInt(){
		v.push_back(1);
	}
};

BigInt operator * (BigInt &a, ll b){
	ll x=0;
	for(int i=0; i<a.v.size(); i++){
		x += a.v[i] * b;
		a.v[i] = x % BGMOD;
		x /= BGMOD;
	}
	if(x){
		a.v.push_back(x);
	}
	return a;
}

ostream& operator <<(ostream& obj, const BigInt& bg){
	char buf[20];
	for(int i=bg.v.size()-1; i>=0; i--){
		if(i!=bg.v.size()-1){
			sprintf(buf, "%04d", bg.v[i]);
		}else{
			sprintf(buf, "%d", bg.v[i]);
		}
		obj<<buf;
	}
	return obj;
}

vector<int> v;

int main(){
	ll n;
	while(cin>>n){
		v.push_back(n);
	}
	BigInt bg;
	for(int i : v){
		bg  = bg * i;
	}
	cout << bg << endl;
	
}

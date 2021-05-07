#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define LL long long

vector<LL> p;
bool cmps[1000005];

int main(){
	LL n;
	cin >> n;
	for(LL i=2; i<=n; i++){
		if(cmps[i]){
			continue;
		}
		p.push_back(i);
		for(LL j=i; j*i<=n; j++){
			cmps[i*j]=1;
		}
	}
	for(LL i : p){
		cout << i << ' ';
		int cnt=0;
		for(LL mul=i; mul<=n; mul*=i){
			cnt += n/mul;
		}
		cout << cnt << '\n';
	}
}

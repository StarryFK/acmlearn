#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
#include <algorithm>
#define scanf("%d", &x)
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

struct Cow{
	int in;
	int out;
	Cow(int a, int b){
		in = a;
		out = b;
	}
};

bool operator<(const Cow &a, const Cow &b){
	return a.in < b.in;
}

vector<Cow> v;

int main(){
	int n;
	while(~RI(n)){
		int l,r;
		for(int i=0; i<n; i++){
			RI(l);
			RI(r);
			v.push_back(l,r);
		}
		sort(v.begin(), v.end());
		for(auto i : v){

		}
		printf("%d\n", maxn);
	}
}

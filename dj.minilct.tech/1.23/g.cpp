#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define RI(x) scanf("%d", &x)

struct P{
	int index;
	int time;

	P(int i, int t){
		index = i;
		time = t;
	}
};

bool operator<(const P &a, const P &b){
	return a.time < b.time;
}

vector<P> v;

int main(){
	int t;
	RI(t);
	while(t--){
		v.clear();
		int n;
		RI(n);
		for(int i=1; i<=n; i++){
			int a;
			RI(a);
			v.push_back(P(i,a));
		}
		sort(v.begin(), v.end());
		for(auto i : v){
			printf("%d ", i.index);
		}
		puts("");
	}
}

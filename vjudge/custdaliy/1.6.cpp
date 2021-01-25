#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
#define RI(x) scanf("%d", &x)

map<int, int> diff;

int main(){
	int t;
	RI(t);
	for(int kase=1; kase<=t; kase++){
		int n,m;
		RI(n);
		RI(m);
		diff.clear();
		int l,r;
		for(int i=0; i<m; i++){
			RI(l);
			RI(r);
			if(diff.count(l)){
				diff[l]++;
			}else{
				diff[l]=1;
			}
			if(diff.count(r+1)){
				diff[r+1]++;
			}else{
				diff[r+1]=1;
			}
		}
		int last=0, cnt=0, st=0;
		for(auto i : diff){
			if(st%2){
				cnt += i.first-last;
			}

			//cout << i.first << ' ' << i.second << ' ' << st << ' ' << cnt << endl;

			last = i.first;
			st += i.second;
		}
		if(st%2){
			cnt += n-last;
		}
		printf("Case #%d: %d\n", kase, cnt);
	}
}

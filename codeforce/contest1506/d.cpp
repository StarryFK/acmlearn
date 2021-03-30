#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;
#define RI(x) scanf("%d", &x)

map<int, int> cnt;

int main(){
	int t;
	RI(t);
	while(t--){
		int n;
		RI(n);
		int tmp;
		cnt.clear();
		for(int i=0; i<n; i++){
			RI(tmp);
			if(cnt.count(tmp)){
				cnt[tmp]++;
			}else{
				cnt[tmp]=1;
			}
		}
		int sum=0;
		for(auto i : cnt){
			sum += i.second;

			//cout << i.second  << ' ';

		}
		for(auto i : cnt){
			if(i.second*2>sum){
				printf("%d\n", 2*i.second-sum);
				goto nx;
			}
		}
		if(sum%2){
			puts("1");
		}else{

			puts("0");
		}
nx:;
	}
}



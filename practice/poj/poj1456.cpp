#include <iostream>
#include <utility>
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
#define RI(x) scanf("%d", &x)

priority_queue<int, vector<int>, greater<int> > sell;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > prod;

int main(){
	int n;
	int p,d;
	while(~RI(n)){
		for(int i=0; i<n; i++){
			RI(p);
			RI(d);
			prod.push({d,p});
		}
		while(!prod.empty()){
			p=prod.top().second;
			d=prod.top().first;

			//cout << p << ' ' << d << endl;

			if(d>sell.size()){
				sell.push(p);
			}else{
				if(p>sell.top()){
					sell.pop();
					sell.push(p);
				}
			}
			prod.pop();
		}
		int ans = 0;
		for(; !sell.empty(); sell.pop()){
			ans += sell.top();
		}
		printf("%d\n", ans);
	}
}

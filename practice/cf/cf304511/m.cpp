#include <iostream>
#include <cstring>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n,x;
	int cur=0;
	int last=0;
	int pri=0;
	while(cin >> n >> x){
		last = x; 
		cur = x;
		pri=0;
		for(int i=1; i<n; i++){
			//cout << cur << endl;
			cur = last + 2*pri;
			cur %= 100000;
			pri = last;
			last = cur;
		}
		cout << cur << '\n';
	}
}

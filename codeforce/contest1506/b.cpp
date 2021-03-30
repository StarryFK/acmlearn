#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	int t;
	cin >> t;
	string str;
	while(t--){
		int k,n;
		cin >> n >> k;
		cin >> str;
		int i=-1,j=0;
		for(int p=0; p<n; p++){
			if(str[p]=='*'){
				if(i==-1){
					i = p;
				}
				j = p;
			}
		}
		if(i==j){
			cout << 1 << endl;
		}else{
			int p=i;
			int cnt=0;
			p += k;
			while(p<j){
				while(str[p]=='.'){
					p--;
				}

				//cout << ' ' << p << endl;

				cnt++;
				p += k;
			}
			cout << 2+cnt << endl;
		}
	}
}

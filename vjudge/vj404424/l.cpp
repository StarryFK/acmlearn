#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int acnt[26], bcnt[26];

int main(){
	ios::sync_with_stdio(false);
	string a,b;
	while(cin >> a >> b){
		if(a==b){
			cout << "Equal\n";
		}else{
			if(a.size()!=b.size() || a[0]!=b[0] || a[a.size()-1]!=b[b.size()-1]){
				cout << "No\n";
			}else{
				memset(acnt,0,sizeof(acnt));
				memset(bcnt,0,sizeof(bcnt));
				for(int i=0; i<a.size(); i++){
					acnt[a[i]-'a']++;
					bcnt[b[i]-'a']++;
				}
				bool flag=true;
				for(int i=0; i<26; i++){
					if(acnt[i]!=bcnt[i]){
						flag=false;
						break;
					}
				}
				if(flag){
					cout << "Yes\n";
				}else{
					cout << "No\n";
				}
			}
		}
	}
}

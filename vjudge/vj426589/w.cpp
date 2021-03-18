#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

const int E6 = 1e6+5;

char str[E6];
bool vis[30];

int main(){
	int t;
	RI(t);
	getchar();
	while(t--){
		char ch=getchar();
		memset(str, 0, sizeof(str));
		for(int i=0; ch!='\n'; ch=getchar(), i++){
			str[i] = ch;
		}
		int k;
		int len = strlen(str);
		RI(k);
		for(int i=0, j=0; i<len; i++){
			if(vis[str[j]-'a']){
				vis[str[i]-'a']=0;
				continue;
			}
			vis[str[j]-'a']=1;

		}
	}
}

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)

char str[200010];

int main(){
	int t;
	RI(t);
	while(t--){
		int a,b;
		RI(a);
		RI(b);
		scanf("%s", str);

		//cout << "    " << str << endl;

		int n=strlen(str);
		int cntdw=0, cntow=0;
		for(int i=0; i<n/2; i++){
			if(str[i]=='0'){
				if(str[n-i-1]=='1'){
					goto err;
				}else{
					a-=2;
					str[n-i-1]='0';
				}
			}else if(str[i]=='1'){
				if(str[n-i-1]=='0'){
					goto err;
				}else{
					b-=2;
					str[n-i-1]='1';
				}
			}else{
				if(str[n-i-1]=='?'){
					cntdw++;
				}else if(str[n-i-1]=='1'){
					b-=2;
					str[i]='1';
				}else if(str[n-i-1]=='0'){
					a-=2;
					str[i]='0';
				}
			}
		}
		if(n%2){
			if(str[n/2]=='1'){
				b--;
			}else if(str[n/2]=='0'){
				a--;
			}else{
				cntow++;
			}
		}
		if(a<0 || b<0){
			goto err;
		}
		if(a%2 && b%2){
			goto err;
		}
		if(a%2 || b%2){
			if(cntow==0){
				goto err;
			}else{
				if(a%2){
					a--;
					str[n/2]='0';
				}else{
					b--;
					str[n/2]='1';
				}
			}
		}
		for(int i=0; i<n/2; i++){
			if(str[i]=='?'){
				if(a>0){
					str[i] = str[n-i-1] = '0';
					a-=2;
				}else{
					str[i] = str[n-i-1] = '1';
					b-=2;
				}
			}
		}
		if(a==0 && b==0){
			printf("%s\n", str);
		}else{
			goto err;
		}
		if(0){
err:
			puts("-1");
		}
	}
}

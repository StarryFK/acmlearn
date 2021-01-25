#include <iostream>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)
const int EE6 = 1e6+5;

bool check[EE6];

int main(){
	check[0]=1;
	for(int i=0; i<EE6; i++){
		if(check[i]){
			if(i+2020<EE6){
				check[i+2020]=1;
			}
			if(i+2021<EE6){
				check[i+2021]=1;
			}
		}
	}
	int t;
	RI(t);
	int num;
	while(t--){
		RI(num);
		if(check[num]){
			puts("YES");
		}else{
			puts("NO");
		}
	}
}

#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
#define RI(x) scanf("%d", &x)

int main(){
	int t;
	RI(t);
	while(t--){
		int num;
		RI(num);
		int tmp,last;
		int pos[2] = {0,0};
		int cnt[2]={1,0};
		RI(last);
		int st=0;
		for(int i=1; i<num; i++){
			RI(tmp);
			if(tmp!=last){
				st = !st;
			}
			cnt[st]++;
			pos[st]=i;
			last=tmp;
		}
		if(cnt[0]>cnt[1]){
			printf("%d\n", pos[1]+1);
		}else{
			printf("%d\n", pos[0]+1);
		}
	}
}

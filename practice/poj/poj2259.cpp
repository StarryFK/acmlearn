#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
#include <map>
#define RI(x) scanf("%d", &x)
#define RS(x) scanf("%s", x)
using namespace std;

queue<int> totq;
queue<int> qing[1005];
map<int, int> group;
char str[100];

int main(){
	int t;
	int kase=0;
	while(RI(t)){
		if(t==0){
			break;
		}
		printf("Scenario #%d\n", ++kase);
		for(int i=0; i<t; i++){
			int n;
			RI(n);
			while(n--){
				int k;
				RI(k);
				group[k] = i;
			}
		}
		while(RS(str)){
			if(str[0]=='E'){
				int tmp;
				RI(tmp);
				int g = group[tmp];
				if(qing[g].empty()){
					totq.push(g);
				}
				qing[g].push(tmp);
			}else if(str[0]=='D'){
				printf("%d\n", qing[totq.front()].front());
				qing[totq.front()].pop();
				if(qing[totq.front()].empty()){
					totq.pop();
				}
			}else{
				puts("");
				while(!totq.empty()){
					totq.pop();
				}
				for(int i=0; i<1005; i++){
					while(!qing[i].empty()){
						qing[i].pop();
					}
				}
				group.clear();
				break;
			}
		}
	}
}

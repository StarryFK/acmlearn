#include <iostream>
#include <algorithm>
#include <stack>
#include <cstdio>
#include <cstring>
#define RI(x) scanf("%d", &x)
#define RC(x) scanf("%c", &x)
using namespace std;


stack<int> front;
stack<int> back;
int sum[1000005];
int maxsum[1000005];

int main(){
	int q;
	while(~RI(q)){
		char ch;
		int x;
		int sizef=0;
		sum[0] = 0;
		maxsum[0] = -0x3f3f3f3f;
		while(!front.empty()){
			front.pop();
		}
		while(!back.empty()){
			back.pop();
		}
		for(int i=0; i<q; i++){
			getchar();
			RC(ch);
			if(ch=='I'){
				RI(x);
				front.push(x);
				sizef = front.size();
				sum[sizef] = sum[sizef-1] + front.top();
				maxsum[sizef] = max(maxsum[sizef-1], sum[sizef]);
			}else if(ch=='D'){
				if(front.empty()){
					continue;
				}
				front.pop();
			}else if(ch=='L'){
				if(front.empty()){
					continue;
				}
				back.push(front.top());
				front.pop();
			}else if(ch=='R'){
				if(back.empty()){
					continue;
				}
				front.push(back.top());
				back.pop();
				sizef = front.size();
				sum[sizef] = sum[sizef-1] + front.top();
				maxsum[sizef] = max(maxsum[sizef-1], sum[sizef]);
			}else{
				RI(x);
				printf("%d\n", maxsum[x]);
			}
		}
	}
}

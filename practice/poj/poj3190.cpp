#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
#include <algorithm>
#define RI(x) scanf("%d", &x)
using namespace std;


struct Cow{
	int in;
	int out;
	Cow(int a, int b){
		in = a;
		out = b;
	}
};

bool operator<(const Cow &a, const Cow &b){
	return a.in < b.in;
}

vector<Cow> v;

struct Stall{
	int out;
	int index;
	Stall(int a, int b){
		out = a;
		index = b;
	}
};

priority_queue<Stall> q;

bool operator<(const Stall &a, const Stall &b){
	return a.out > b.out;
}

void clearq(priority_queue<Stall> &obj){
	priority_queue<Stall> empty;
	swap(empty, obj);
}

int cis[50005];

int main(){
	int n;
	while(~RI(n)){
		memset(cis,0,sizeof(cis));
		int l,r;
		clearq(q);
		for(int i=0; i<n; i++){
			RI(l);
			RI(r);
			v.push_back(Cow(l,r));
		}
		sort(v.begin(), v.end());
		int scnt=0;
		int ccnt=0;
		for(int i=0; i<(int)v.size(); i++){

			if(q.empty()){
				q.push(Stall(v[i].out, ++scnt));
				cis[ccnt++] = scnt; 
			}else{
				if(q.top().out<=v[i].in){
					int index=q.top().index;
					q.pop();
					q.push(Stall(v[i].out, index));
					cis[ccnt++] = index;
				}else{
					q.push(Stall(v[i].out, ++scnt));
					cis[ccnt++] = scnt;
				}
			}
		}
		printf("%d\n", scnt);
		for(int i=0; i<ccnt; i++){
			printf("%d\n", cis[i]);
		}
	}
}

#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
#define RI(x) scanf("%d", &x)
using namespace std;

priority_queue<int, vector<int>, greater<int> > ql;
priority_queue<int> qb;

void insert(int i){
	if(qb.empty()){
		qb.push(i);

		//cout << "qbpush" << i << endl;

	}else{
		if(i<=qb.top()){
			qb.push(i);

			//cout << "qbpush" << i << endl;

		}else{
			ql.push(i);

			//cout << "qlpush" << i << endl;

		}
	}
	if(qb.size() >  ql.size()+1){

		//cout << "qb->ql" <<endl;

		ql.push(qb.top());
		qb.pop();
	}else if(ql.size() > qb.size()){

		//cout << "ql->qb" << endl;

		qb.push(ql.top());
		ql.pop();
	}
}

vector<int> out;

int main(){
	int p;
	RI(p);
	for(int j=0; j<p; j++){
		if(j!=0){
			puts("");
		}
		int n,m;
		RI(n);
		RI(m);
		int tmp;
		ql = priority_queue<int, vector<int>, greater<int> >();
		qb = priority_queue<int>();
		out.clear();
		for(int i=1; i<=m; i++){
			RI(tmp);
			insert(tmp);
			if(i%2==1){
				out.push_back(qb.top());
			}
		}
		printf("%d %d\n", n, out.size());
		for(int i=0; i<out.size(); i++){
			if(i%10==0 && i!=0){
				puts("");
			}
			printf("%d ", out[i]);
		}
	}
}

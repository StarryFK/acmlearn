#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define INF 0x7fffffff
#define RI(x) scanf("%d", &x)
using namespace std;

struct Num{
	int num;
	int index;
	Num(int n, int i){
		num = n;
		index = i;
	}
};

bool operator<(const Num &a, const Num &b){
	return a.num < b.num;
}

set<Num> se;

int main(){
	int n;
	while(~RI(n)){
		se.clear();
		int tmp;
		RI(tmp);
		se.insert(Num(tmp, 1));
		int aj,j;
		for(int i=2; i<=n; i++){
			aj = INF;
			j = 0;
			RI(tmp);
			auto it = se.insert(Num(tmp, i)).first;
			it++;
			if(it!=se.end()){
				aj = it->num;
				j = it->index;
			}
			it--;
			if(it!=se.begin()){
				it--;
				if(abs((it->num)-tmp) < abs(aj-tmp)){
					aj = it->num;
					j = it->index;
				}else if(abs((it->num)-tmp) == abs(aj-tmp)){
					if(it->num < aj){
						aj = it->num;
						j = it->index;
					}
				}
			}
			printf("%d %d\n", abs(aj-tmp), j);
		}
	}
}

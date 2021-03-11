#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define LL long long
#define RLL(x) scanf("%lld", &x)
#define RI(x) scanf("%d", &x)
#define INF 0x3f3f3f3f3f3f3f3f

const int E5 = 1e5+5;

struct Node{
	int addr;
	LL val;
};

bool operator < (const Node &a, const Node &b){
	return a.val > b.val;
}

priority_queue<Node> q;

int totlist;

struct LNode{
	int pri;
	LL val;
	int next;
} list[2*E5];

bool del[2*E5];

void initList(){
	list[0].pri=-1;
	list[0].val=INF;
	list[0].next=1;
	list[1].pri=0;
	list[1].val=INF;
	list[1].next=-1;
	totlist = 2;
}

int insertList(int addr, LL val){
	int cur = totlist++;
	list[cur].next = list[addr].next;
	list[cur].pri = addr;
	list[cur].val = val;

	list[addr].next = cur;
	list[list[cur].next].pri = cur;

	return cur;
}

int addlist(LL val){
	return insertList(list[1].pri, val);
}

void dellist(int addr){
	list[list[addr].pri].next = list[addr].next;
	list[list[addr].next].pri = list[addr].pri;
}

int main(){
	int n,k;
	RI(n);
	RI(k);
	initList();
	LL pos, last;
	RLL(last);
	for(int i=1; i<n; i++){
		RLL(pos);

		//cout << pos-last << ' ';

		int addr = addlist(pos-last);
		q.push({addr, pos-last});
		last = pos;
	}

	//cout << endl;

	LL ans = 0;
	for(int i=0; i<k; i++){

		//int p=0;
		//while(p!=-1){
		//	cout << (list[p].val==INF ? 0 : list[p].val) << ' ';
		//	p = list[p].next;
		//}
		//cout << endl;

		while(del[q.top().addr]){
			q.pop();
		}

		int addr = q.top().addr;
		ans += q.top().val;

		//cout << q.top().val << endl;

		q.pop();
		LL newval = list[list[addr].pri].val + list[list[addr].next].val - list[addr].val;

		//cout <<list[list[addr].pri].val << list[list[addr].next].val << list[addr].val<< newval << endl;

		del[list[addr].pri]=1;
		del[list[addr].next]=1;
		dellist(list[addr].pri);
		dellist(list[addr].next);
		list[addr].val = newval;
		q.push({addr, newval});
	}
	printf("%lld\n", ans);
}

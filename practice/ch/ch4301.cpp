#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define int LL
#define RLL(x) scanf("%lld",&x)
const LL MAX = 5E5+5;
const LL INF = 0X3F3F3F3F3F3F3F3F;

struct SegTree{
	LL l,r;
	LL max;
	LL lmax, rmax;
	LL sum;
};
SegTree st[4*MAX];
LL arr[MAX];

void update(LL x){
	LL lc = 2*x;
	LL rc = 2*x+1;
	st[x].sum = st[lc].sum + st[rc].sum;
	st[x].lmax = max(st[lc].lmax, st[lc].sum + st[rc].lmax);
	st[x].rmax = max(st[rc].rmax, st[rc].sum + st[lc].rmax);
	st[x].max = max(max(st[lc].max, st[rc].max), st[lc].rmax+st[rc].lmax);
}
void build(LL x, LL l, LL r){
	st[x].l = l;
	st[x].r = r;
	if(l==r){
		st[x].max = st[x].lmax = st[x].rmax = st[x].sum = arr[l];
	}else{
		LL mid = (l+r)>>1;
		build(x*2, l, mid);
		build(x*2+1, mid+1, r);
		update(x);
	}
}
void change(LL p, LL x, LL num){
	if(st[p].l == st[p].r){
		arr[st[p].l] = num;
		st[p].max = st[p].lmax = st[p].rmax = st[p].sum = arr[st[p].l];
	}else{
		LL mid = (st[p].l + st[p].r)>>1;
		if(x<=mid){
			change(p*2, x, num);
		}else{
			change(p*2+1, x, num);
		}
		update(p);
		
		//cout <<"update"<< st[p].l << ' ' << st[p].r << ' ' << st[p].max << endl;
		
	}
}
SegTree ask(LL p, LL l, LL r){
	if(l<=st[p].l && st[p].r<=r){
		return st[p];
	}else{
		SegTree lt, rt, ans;
		lt.max = lt.lmax = lt.rmax = -INF;
		rt.max = rt.lmax = lt.rmax = -INF;
		lt.sum = rt.sum = 0;
		LL mid = (st[p].r+st[p].l)>>1;
		if(l<=mid){
			lt = ask(p*2, l, r);
		}
		if(r>mid){
			rt = ask(p*2+1, l, r);
		}
		ans.sum = lt.sum + rt.sum;
		ans.lmax = max(lt.lmax, lt.sum+rt.lmax);
		ans.rmax = max(rt.rmax, rt.sum+lt.rmax);
		ans.max = max(max(lt.max, rt.max), lt.rmax+rt.lmax);
		return ans;
	}
}

signed main(){
	LL n,m;
	RLL(n);
	RLL(m);
	for(LL i=1; i<=n; i++){
		RLL(arr[i]);
	}
	build(1, 1, n);
	for(LL i=0; i<m; i++){
		LL op,x,y;
		RLL(op);
		RLL(x);
		RLL(y);
		if(op==1){
			if(x>y){
				swap(x,y);
			}
			SegTree ans = ask(1, x, y);
			printf("%lld\n", ans.max);
		}else{
			change(1, x, y);
			/*
			for(int i=1; i<=n; i++){
				cout << arr[i] << ' ';
			}
			cout << endl;
			*/
			
		}
	}
}
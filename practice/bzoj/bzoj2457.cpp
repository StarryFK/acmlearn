#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define IINF 0x3f3f3f3f
#define RLL(x) scanf("%lld", &x)
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

vector<Num> arr;
vector<int> gp;

int main(){
	ll n;
	RLL(n);
	ll tmp;
	for(int i=0; i<n; i++){
		RLL(tmp);
		arr.push_back(Num(tmp, i));
	}
	sort(arr.begin(), arr.end());
	ll lastn = arr[0].num;
	for(int i=0; i<(int)arr.size(); i++){
		if(arr[i].num!=lastn){
			gp.push_back(i-1);
			lastn = arr[i].num;
		}
	}
	gp.push_back((int)arr.size()-1);

	//for(int i : gp){
	//	cout << i << ' ';
	//}
	//cout << endl;

	int cur=0;
	int cnt=0;
	bool st=1;
	int lastnum = IINF;
	int maxn, minn;
	for(int i=0; i<(int)gp.size(); i++){
		maxn = -IINF;
		minn = IINF;
		for(; cur<=gp[i]; cur++){
			maxn = max(maxn, arr[cur].index);
			minn = min(minn, arr[cur].index);
		}

		//cout << maxn << ' '  << minn << endl;

		if(st){
			if(minn>lastnum){
				lastnum = maxn;
			}else{
				st = 0;
				cnt++;
				lastnum = minn;
			}
		}else{
			if(maxn < lastnum){
				lastnum = minn;
			}else{
				st = 1;
				lastnum = maxn;
			}
		}

		//cout << lastnum << endl;

	}
	printf("%d\n", cnt);
}

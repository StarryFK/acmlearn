#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Man{
	int l;
	int r;
	Man(int _l, int _r){
		l = _l;
		r = _r;
	}
};

bool operator<(const Man &a, const Man &b){
	return a.l*a.r < b.l*b.r;
}

vector<Man> v;

struct BigInt{
	vector<int> v;
	BigInt(){
		v.push_back(1);
	}
}

BigInt& operator * (BigInt &a, const int &b){
	BigInt ans = a;
	int x=0;
	for(int i=0; i<a.v.size(); i++){
		x += ans.v[i]*b;
		ans.v[i] = x%10000;
		x /= 10000;
	}
	if(x){
		ans.v.push_back(x);
	}
	return ans;
}

BigInt operator / (BigInt &a, const int &b){
	BigInt ans = a;
	int x=0;
	for(int i=a.v.size()-1; i>=0; i--){
		x = (x+a.v[i]) % b;
	}
	
}


int main(){
	int n;
	cin >> n;
	int l,r;
	for(int i=0; i<=n; i++){
		cin >> l >> r;
		v.push_back(Man(l,r));
	}
	sort(v.begin()+1, v.end());
	int tot=v[0].l;
	int maxn=0;
	for(int i=1; i<=n; i++){
		//cout << tot << ' ';
		//cout << v[i].r << endl;
		maxn = max(maxn, tot/v[i].r);
		tot *= v[i].l;
	}
	cout << maxn << endl;
}

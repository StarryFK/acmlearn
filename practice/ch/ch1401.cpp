#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define ull unsigned long long
#define P 131

string str;
vector<ull> sum;

ull powm(ull a, ull n){
	ull ans = 1;
	for(; n; n>>=1){
		if(n&1){
			ans *= a;
		}
		a *= a;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> str;
	ull cursum = 0;
	sum.push_back(0);
	for(int i=0; i<(int)str.size(); i++){
		cursum *= P;
		cursum += str[i]-'a'+1;
		sum.push_back(cursum);
	}
	int m;
	cin >> m;
	int l1,l2,r1,r2;
	for(int i=0; i<m; i++){
		cin >> l1 >> r1 >> l2 >> r2;
		ull ha1 = sum[r1] - sum[l1-1] * powm(P,r1-l1+1);
		ull ha2 = sum[r2] - sum[l2-1] * powm(P,r2-l2+1);
		if(ha1 == ha2){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	}
}

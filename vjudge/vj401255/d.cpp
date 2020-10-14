#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int out[100005];
bool vis[100005];
vector<pair<int, int> > v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int x,y;
		v.clear();
		for(int i=0; i<m; i++){
			cin >> x >> y;
			v.push_back(make_pair(x-1,y-1));
		}
		sort(v.begin(), v.end());
		for(int i=0; i<n; i++){
			vis[i]=0;
			out[i]=1;
		}
		int l,r,vp,last=0;
		for(int i=0; i<v.size(); i++){
			l = v[i].first;
			r = v[i].second;
			vp = 1;
			if(i>0){
				for(int j=v[i-1].first; j<l; j++){
					vis[out[j]] = false;
				}
				l = max(last+1, l);
			}

			//for(int i=0; i<100000; i++){
			//	cout << vis[i] << '\n';
			//}

			for(int j=l; j<=r; j++){
				while(vis[vp]==1){
					vp++;
				}

				//cout << i << ' ' << j << ' '<< vp << endl;

				out[j] = vp;
				last = j;
				vis[vp] = 1;
			}
		}
		for(int i=0; i<n; i++){
			if(i!=0){
				cout << ' ';
			}
			cout << out[i];
		}
		cout << '\n';
	}
}



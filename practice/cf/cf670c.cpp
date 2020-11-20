#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

map<int, int> id;
int curid=0;
vector<int> man, voi, text;
int cnt[600010];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m;
	cin >> n;
	int num;
	for(int i=0; i<n; i++){
		cin >> num;
		if(id.count(num)==0){
			id[num] = curid++;
		}
		man.push_back(id[num]);
	}
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> num;
		if(id.count(num)==0){
			id[num] = curid++;
		}
		voi.push_back(id[num]);
	}
	for(int i=0; i<m; i++){
		cin >> num;
		if(id.count(num)==0){
			id[num] = curid++;
		}
		text.push_back(id[num]);
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i:man){
		cnt[i]++;
	}
	int ans1=0, ans2=0;
	int result =0;
	for(int i=0; i<m; i++){
		int a1 = cnt[voi[i]];
		int a2 = cnt[text[i]];
		if((a1>ans1) || ((a1==ans1) && (a2>ans2))){
			result = i;
			ans1 = a1;
			ans2 = a2;
		}
	}
	cout << result+1 << endl;
}

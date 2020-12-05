#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define MOD 99991
#define RI(x) scanf("%d", &x)
#define uint unsigned int

vector<int> ha[MOD];
int pool[100005][6];

inline bool find(uint hv, int cnt){

	//cout << hv << endl;

	for(int i=0; i<(int)ha[hv].size(); i++){
		for(int j=0; j<6; j++){
			bool flag1 = true;
			bool flag2 = true;
			for(int k=0; k<6; k++){
				if(pool[cnt][(j+k)%6]!=pool[ha[hv][i]][k]){
					flag1 = false;
				}
				if(pool[cnt][(j-k+6)%6]!=pool[ha[hv][i]][k]){
					flag2 = false;
				}
			}
			if(flag1 || flag2){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n;
	int cnt=0;
	RI(n);
	for(int i=0; i<n; i++){
		uint sum=0, mul=1;
		for(int j=0; j<6; j++){
			RI(pool[cnt][j]);

			//cout << 1 << endl;

			sum += pool[cnt][j];
			mul *= pool[cnt][j];
		}
		if(find((sum+mul)%MOD, cnt)){
			puts("Twin snowflakes found.");
			return 0;
		}
		ha[(sum+mul)%MOD].push_back(cnt);
		cnt++;
	}
	puts("No two snowflakes are alike.");
}

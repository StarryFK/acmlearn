#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
#define RI(x) scanf("%d", &x)

vector<char> ans;
int ansn;
int st[9][9];

inline bool read(){
	RI(st[1][3]);
	if(st[1][3]==0){
		return false;
	}
	RI(st[1][5]);
	RI(st[2][3]);
	RI(st[2][5]);
	for(int i=1; i<=7; i++){
		RI(st[3][i]);
	}
	RI(st[4][3]);
	RI(st[4][5]);
	for(int i=1; i<=7; i++){
		RI(st[5][i]);
	}
	RI(st[6][3]);
	RI(st[6][5]);
	RI(st[7][3]);
	RI(st[7][5]);
	return true;
}
inline void rot(int arr, int dir){
	switch(arr){
		case 0:
			if(dir==0){
				for(int i=0; i<7; i++){
					st[i][3] = st[i+1][3];
				}
				st[7][3] = st[0][3];
			}else{
				for(int i=8; i>1; i--){
					st[i][3] = st[i-1][3];
				}
				st[1][3] = st[8][3];
			}
			break;
		case 1:
			if(dir==0){
				for(int i=0; i<7; i++){
					st[i][5] = st[i+1][5];
				}
				st[7][5] = st[0][5];
			}else{
				for(int i=8; i>1; i--){
					st[i][5] = st[i-1][5];
				}
				st[1][5] = st[8][5];
			}
			break;
		case 2:
			if(dir==0){
				for(int i=0; i<7; i++){
					st[3][i] = st[3][i+1];
				}
				st[3][7] = st[3][0];
			}else{
				for(int i=8; i>1; i--){
					st[3][i] = st[3][i-1];
				}
				st[3][1] = st[3][8];
			}
			break;
		case 3:
			if(dir==0){
				for(int i=0; i<7; i++){
					st[5][i] = st[5][i+1];
				}
				st[5][7] = st[5][0];
			}else{
				for(int i=8; i>1; i--){
					st[5][i] = st[5][i-1];
				}
				st[5][1] = st[5][8];
			}
			break;
	}
}
inline void act(int sel){
	switch(sel){
		case 0:
			rot(0, 0);
			break;
		case 1:
			rot(1, 0);
			break;
		case 2:
			rot(2, 1);
			break;
		case 3:
			rot(3, 1);
			break;
		case 4:
			rot(1, 1);
			break;
		case 5:
			rot(0, 1);
			break;
		case 6:
			rot(3, 0);
			break;
		case 7:
			rot(2, 0);
			break;
	}
}
int cnt[4];
const int checkx[]={3,3,3,4,5,5,5,4};
const int checky[]={3,4,5,5,5,4,3,3};
inline int getf(){
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<8; i++){
		cnt[st[checkx[i]][checky[i]]]++;
	}
	int maxn = max(max(cnt[1], cnt[2]), cnt[3]);
	if(maxn==cnt[1]){
		return cnt[2] + cnt[3];
	}else if(maxn==cnt[2]){
		return cnt[1] + cnt[3];
	}else{
		return cnt[2] + cnt[1];
	}
}
const int inv[]={5,4,7,6,1,0,3,2};
bool ida(int cur, int dep, int last){
	int f = getf();

	//cout << cur << ' ' << f << ' ' << dep << endl;

	if(f==0){
		ansn = st[3][3];
		return true;
	}
	if(cur+f>dep){
		return false;
	}
	int b[9][9];
	memcpy(b, st, sizeof(b));
	for(int i=0; i<8; i++){
		if(last==-1 || (last!=-1 && inv[last]!=i)){
			act(i);
			ans.push_back('A'+i);
			if(ida(cur+1, dep, i)){
				return true;
			}
			ans.pop_back();
			memcpy(st, b, sizeof(b));
		}
	}
	return false;
}

int main(){
	while(read()){
		ans.clear();
		for(int dep=0; ; dep++){
			if(ida(0, dep, -1)){
				if(dep==0){
					puts("No moves needed");
				}else{
					for(int i=0; i<ans.size(); i++){
						printf("%c", ans[i]);
					}
					puts("");
				}
				printf("%d\n", ansn);
				break;
			}
		}
	}
}

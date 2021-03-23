#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x);

int l[9], _[9], o[3][3];
int getbit[40];
int get1num[0x000003FF];
int ma[9][9];
int cnt=0;

inline void clrbit(int& num, int pos){
	num &= ~(1<<pos);
}

inline void setbit(int &num, int pos){
	num |= (1<<pos);
}

inline int lowbit(int num){
	return getbit[(num&(-num))%37];
}

inline void init(){
	for(int i=0; i<15; i++){
		getbit[(1<<i)%37] = i;
	}
	for(int i=0; i<=0x000003FE; i++){
		int ccnt=0, tmp=i;
		while(tmp){
			tmp -= 1<<getbit[tmp];
			ccnt++;
		}
		get1num[i] = ccnt;
	}
}

inline void clr(){
	for(int i=0; i<9; i++){
		l[i] = 0x000003FE;
		_[i] = 0x000003FE;
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			o[i][j] = 0x000003FE;
		}
	}
	cnt=0;
}

bool dfs(){
	if(cnt==81){
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				printf("%d", ma[i][j]);
			}
		}
		puts("");
		return true;
	}
	int choice=10, x=-1, y=-1;
	int curc, ccnt;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(ma[i][j]!=0){
				continue;
			}
			ccnt=get1num[l[j] & _[i] &o[i/3][j/3]];
			if(ccnt>0 && ccnt < choice){
				x=i, y=j;
				choice=ccnt;
			}
		}
	}
	if(x>=0 && y>=0){
		cnt++;
		choice = l[y] & _[x] & o[x/3][y/3];
		while(choice){
			curc = lowbit(choice);
			choice -= (1<<curc);
			clrbit(l[y], curc);
			clrbit(_[x], curc);
			clrbit(o[x/3][y/3], curc);
			ma[x][y] = curc;

			//cout << x << ' ' << y << ' ' << curc << endl;

			if(dfs()){
				return true;
			}
			ma[x][y] = 0;
			setbit(l[y], curc);
			setbit(_[x], curc);
			setbit(o[x/3][y/3], curc);
		}
		cnt--;
	}
	return false;
}

int main(){
	init();
	while(1){
		clr();
		char ch;
		for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				ch = getchar();
				if(ch=='e'){
					goto endd;
				}
				if(ch=='.'){
					ma[i][j] = 0;
				}else{
					ma[i][j] = ch-'0';
					cnt++;
					clrbit(l[j], ch-'0');
					clrbit(_[i], ch-'0');
					clrbit(o[i/3][j/3], ch-'0');
				}
			}
		}
		getchar();
		dfs();
	}
endd:;
}

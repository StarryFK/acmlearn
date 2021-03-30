#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f

int ma[20][20];
int l[20];
int _[20];
int o[5][5];
int gbarr[40];
int get1[1<<18];
int tot=0;
int bma[260][20][20];
int bl[260][20];
int b_[260][20];
int bo[260][5][5];

inline void printma(){
	for(int i=0; i<16; i++){
		for(int j=0; j<16; j++){
			if(ma[i][j]==0){
				printf("-");
			}else{
				printf("%c", ma[i][j]+'A'-1);
			}
		}
		puts("");
	}
}
inline int lowbit(int num){
	return num&(-num);
}
inline void init(){
	for(int i=0; i<20; i++){
		l[i] = (1<<17)-2;
		_[i] = (1<<17)-2;
	}
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			o[i][j] = (1<<17)-2;
		}
	}
	for(int i=0; i<20; i++){
		gbarr[(1<<i)%37] = i;
	}
	for(int i=0; i<=(1<<17); i++){
		int cnt=0;
		int tmp=i;
		while(tmp){
			cnt++;
			tmp -= lowbit(tmp);
		}
		get1[i] = cnt;
	}
}
inline int getbit(int num){
	return gbarr[num%37];
}
inline void setbit(int &num, int pos){
	num |= (1<<pos);
}
inline void clrbit(int &num, int pos){
	num &= ~(1<<pos);
}
inline int getcoic(int i, int j){
	return l[j] & _[i] & o[i/4][j/4];
}
inline void setnum(int i, int j, int num){
	ma[i][j] = num;
	clrbit(l[j], num);
	clrbit(_[i], num);
	clrbit(o[i/4][j/4], num);
	tot++;
}
inline void clrnum(int i, int j, int num){
	ma[i][j] = 0;
	setbit(l[j], num);
	setbit(_[i], num);
	setbit(o[i/4][j/4], num);
	tot--;
}
bool dfs(){

	cout << tot << endl;

	if(tot==256){
		for(int i=0; i<16; i++){
			for(int j=0; j<16; j++){
				printf("%c", ma[i][j]+'A'-1);
			}
			puts("");
		}
		return true;
	}
	memcpy(bma[tot], ma, sizeof(ma));
	memcpy(bl[tot], l, sizeof(l));
	memcpy(b_[tot], _, sizeof(_));
	memcpy(bo[tot], o, sizeof(o));
	int btot=tot;
	int coic;
	int ppos;
	int pcnt;
	int pposx, pposy;
	int minx=-1, miny=-1;
	int minccnt=INF;
	int num;
	//for(int i=0; i<16; i++){
	//	for(int j=0; j<16; j++){
	//		if(ma[i][j]!=0){
	//			continue;
	//		}
	//		coic = getcoic(i,j);
	//		if(get1[coic]==0){

	//			cout << 1 << endl;
	//			cout << i << ' ' << j << endl;
	//			printma();

	//			goto back;
	//		}
	//		if(get1[coic]==1){
	//			setnum(i, j, getbit(coic));
	//		}	
	//	}
	//}
	for(int i=0; i<16; i++){
		for(int c=_[i]; c; c-=lowbit(c)){
			num = getbit(lowbit(c));
			ppos=-1;
			pcnt=0;
			for(int j=0; j<16; j++){
				coic = getcoic(i,j);
				if((coic>>num)&1){
					ppos=j;
					pcnt++;
				}
			}

			cout << ppos << ' ' << pcnt << endl;

			if(pcnt==0){

				cout << 2 << endl;
				//cout << i << ' '  << num << endl;

				goto back;
			}
			if(pcnt==1){
				setnum(i, ppos, num);
			}
		}
	}
	for(int i=0; i<16; i++){
		for(int c=l[i]; c; c-=lowbit(c)){
			num = getbit(lowbit(c));
			ppos=-1;
			pcnt=0;
			for(int j=0; j<16; j++){
				coic = getcoic(j,i);
				if((coic>>num)&1){
					ppos=i;
					pcnt++;
				}
			}
			if(pcnt==0){

				cout << 3 << endl;

				goto back;
			}
			if(pcnt==1){
				setnum(ppos, i, num);
			}
		}
	}
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			for(int c=o[i][j]; c; c-=lowbit(c)){
				num = getbit(lowbit(c));
				pposx=-1;
				pposy=-1;
				pcnt=0;
				for(int ii=0; ii<4; ii++){
					for(int jj=0; jj<4; jj++){
						coic = getcoic(i*4+ii, j*4+jj);
						if((coic>>num)&1){
							pposx = ii;
							pposy = jj;
							pcnt++;
						}
					}
				}
				if(pcnt==0){

					cout << 4 << endl;

					goto back;
				}
				if(pcnt==1){
					setnum(i*4+pposx, j*4+pposy, num);
				}
			}
		}
	}
	for(int i=0; i<16; i++){
		for(int j=0; j<16; j++){
			if(ma[i][j]!=0){
				continue;
			}
			coic = getcoic(i,j);
			if(get1[coic]==0){

				cout << 6 << endl;
				//cout << i << ' ' << j << endl;
				//printma();

				goto back;
			}
			if(get1[coic]==1){
				setnum(i, j, getbit((coic)));
			}	
		}
	}
	for(int i=0; i<16; i++){
		for(int j=0; j<16; j++){
			if(ma[i][j]!=0){
				continue;
			}
			coic = getcoic(i,j);
			if(get1[coic] < minccnt){
				minccnt = get1[coic];
				minx = i;
				miny = j;
			}
		}
	}
	for(coic=getcoic(minx, miny); coic; coic-=lowbit(coic)){
		setnum(minx, miny, getbit(lowbit(coic)));
		if(dfs()){
			return true;
		}
		clrnum(minx, miny, getbit(lowbit(coic)));
	}

	cout << 5 << endl;
	//cout << minccnt << ' ' << minx << ' ' << miny << endl;

back:
	tot = btot;
	memcpy(ma, bma[tot], sizeof(ma));
	memcpy(l, bl[tot], sizeof(l));
	memcpy(_, b_[tot], sizeof(_));
	memcpy(o, bo[tot], sizeof(o));
	return false;
}

int main(){
	char ch;
	init();
	for(int i=0; i<16; i++){
		for(int j=0; j<16; j++){
			ch = getchar();
			if(ch!='-'){
				setnum(i, j, ch-'A'+1);
			}
		}
		getchar();
	}
	dfs();
}

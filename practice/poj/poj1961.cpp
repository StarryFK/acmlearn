#include <iostream>
#include <cstdio>
using namespace std;
#define RS(x) scanf("%s", x)
#define RI(x) scanf("%d", &x)

char str[1000005];
int nnext[1000005];
int kase=0;
int num;

void calcnnext(){
	nnext[1]=0;
	for(int i=2,j=0; i<=num; i++){
		while(j>0 && str[i]!=str[j+1]){
			j = nnext[j];
		}
		if(str[i]==str[j+1]){
			j++;
		}
		nnext[i]=j;
	}
}

int main(){
	while(RI(num)){
		if(num==0)	break;
		RS(str+1);
		calcnnext();
		printf("Test case #%d\n", ++kase);
		for(int i=2; i<=num; i++){
			if(i%(i-nnext[i])==0 && i/(i-nnext[i])>1){
				printf("%d %d\n", i, i/(i-nnext[i]));
			}
		}
		puts("");
	}
}

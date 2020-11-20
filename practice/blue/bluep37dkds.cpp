#include <cstdio>
#include <vector>
#define RI(x) scanf("%d", &x)
#define ull unsigned long long 
using namespace std;

vector<int> v;
int k;

int search(int l, int r){
	if(l>=r){
		return v[r];
	}
	int i=l, j=r, pi=v[l];
	while(i<j){
		while(i<j && v[j]>=pi){
			j--;
		}
		v[i] = v[j];
		while(i<j && v[i]<=pi){
			i++;
		}
		v[j] = v[i];
	}
	v[i] = pi;
	if(i>k){
		return search(l,i-1);
	}else if(i<k){
		return search(i+1,r);
	}else{
		return v[i];
	}
}
int main(){
	int tmp;
	RI(k);
	k--;
	while(~RI(tmp)){
		v.push_back(tmp);
		//printf("1\n");
	}
	printf("%d\n", search(0, v.size()-1));
}


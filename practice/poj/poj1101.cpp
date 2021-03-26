#include <iostream>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define RI(x) scanf("%d" ,&x)

int n, ans;
int arr[70], vis[70];

bool test(int rest, int cur, int last){
	if(rest<0){
		return true;
	}
	if(cur==ans){
		return test(rest-1, 0, -1);
	}
	int fail=-1;
	for(int i=last+1; i<n; i++){
		if(!vis[i] && cur+arr[i]<=ans && arr[i]!=fail){
			vis[i]=1;
			if(test(rest, cur+arr[i], i)){
				return true;
			}
			vis[i]=0;
			fail = arr[i];
			if(cur==0 || cur+arr[i]==ans){
				return false;
			}
		}
	}
	return false;
}

int main(){
	while(~RI(n)){
		if(n==0){
			break;
		}
		int sum=0;
		for(int i=0; i<n; i++){
			RI(arr[i]);
			sum += arr[i];
		}
		sort(arr, arr+n, greater<int>());
		for(ans=1; ans<=sum; ans++){
			if(sum%ans){
				continue;
			}
			memset(vis, 0, sizeof(vis));	
			if(test(sum/ans-1, 0, -1)){
				break;
			}
		}
		printf("%d\n", ans);
	}
}

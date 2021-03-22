#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define RI(x) scanf("%d", &x)
#define LL long long

const int E6 = 1e6+5;

char str[E6];
int cnt[30];

int main(){
	int t;
	RI(t);
	getchar();
	while(t--){
		char ch=getchar();
		memset(str, 0, sizeof(str));
		memset(cnt, 0, sizeof(cnt));
		for(int i=0; ch!='\n'; ch=getchar(), i++){
			str[i] = ch;
		}
		int k;
		int len = strlen(str);
		RI(k);
		getchar();
		LL ans=0;
		int diff=0;

		//cout << str << endl;

		for(int i=0, j=0; i<len; i++){
			j = max(i,j);
			for(; diff<k && j<len; j++){
				if(cnt[str[j]-'a']==0){
					diff++;
				}
				cnt[str[j]-'a']++;
			}

			//cout << i << ' ' << j << endl;

			if(diff==k){
				ans += max(0, len-j+1);

				//cout << max(0, len-j+1) << endl;

			}
			cnt[str[i]-'a']--;
			if(cnt[str[i]-'a']==0){
				diff--;
			}
		}
		printf("%lld\n", ans);
	}
}

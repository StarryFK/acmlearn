#include <iostream>
#include <stack>
#include <map>
#include <cstring>
using namespace std;

map<char, int> ma;

char a[1000005], b[1000005];

int result=0;

int cnt[4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cnt, 0, sizeof(cnt));
    ma['C']=0;
    ma['G']=1;
    ma['A']=2;
    ma['T']=3;
    cin >> a >> b;
    int len=0;
    for(int i=0; a[i]!=0; i++){
        len++;
        if(a[i] != b[i]){
            cnt[ma[b[i]]]++;
        }
    }
    for(int i=0; i<4; i++){
        result = max(cnt[i], result);
    }
    cout << len-result << endl;
}
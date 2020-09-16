#include <iostream>
#include <cstring>
#define ull unsigned long long
using namespace std;

int num[100005][105];
const int p = 998244353;

int main(){
    ios::sync_with_stdio(false);
    memset(num, 0, sizeof(num));
    int n,m;
    cin >> n >> m;
    int x,y,c;
    for(int i=0; i<m ;i++){
        cin >> x >> y >> c;
        for(int j=x; j<=y; j++){
            num[j][c]++;
        }
    }
    ull result=1;
    for(int i=2; i<105; i++){
        int cnt=0x3f3f3f3f;
        for(int j=1; j<=n; j++){
            cnt=min(cnt, num[j][i]);
        }
        if(cnt){
            result = (result * cnt * i)%p;
        }
    }
    cout << result << endl;
}
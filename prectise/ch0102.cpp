#include <iostream>
#define ull unsigned long long
using namespace std;
int main(){
    ull a,b,p;
    cin >> a >> b >> p;
    ull ans = 0;
    ull mul = a%p;
    for(; b; b>>=1){
        ans = (ans + mul * (b&1))%p;
        mul = (mul*2)%p;
    }
    cout << ans << endl;
}
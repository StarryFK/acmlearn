#include <iostream>
#define ull unsigned long long
using namespace std;
int main(){
    ull a,b,p;
    cin >> a >> b >> p;
    ull mul=a%p;
    ull result=1%p;
    for(;b>0; b>>=1){
        if(b&1){
            result = ((result%p) * (mul%p))%p;
        }
        mul = ((mul%p) * (mul%p))%p;
    }
    cout << result << endl;
}
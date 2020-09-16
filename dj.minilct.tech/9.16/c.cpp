#include <iostream>
#define ull unsigned long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    ull t,n;
    cin >> t;
    while(t--){
        cin >>n;
        n %= 4;
      // cout << n << endl;
        if(n==0){
            cout << "danshen" << endl;
            return 0;
        }
    }
    cout << "tuodan" << endl;
}
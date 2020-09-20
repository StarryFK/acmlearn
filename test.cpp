#include <iostream>
#include <ctime>
#define ull unsigned long long 
using namespace std;

int ha[36];

int main(){
    ios::sync_with_stdio(false);
    double t1 = (double)clock()/CLOCKS_PER_SEC;
    ull n=1;
    for(int i=0; i<36; i++){
        ha[n%37]=i;
        n<<=1;
    }
    while(cin>>n){
        cout << n << ':';
        while(n){
            cout << ha[(n&(-n)) % 37] << ' ';
            n -= n&(-n);
        }
        cout << endl;
    }
    double t2 = (double)clock()/CLOCKS_PER_SEC;
    cout << t2-t1 << 's' << endl;
}
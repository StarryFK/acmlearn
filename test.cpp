#include <cstdio>
#include <iostream>
#include <ctime>
#define ull unsigned long long 
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double t1 = (double)clock()/CLOCKS_PER_SEC;
    double num;
    while(cin>>num);
//    while(scanf("%lf", num)!=EOF);
    for(int i=1; i<10000000; i++){
        cout << i << '\n';
//        printf("%d\n", i);
    }
    double t2 = (double)clock()/CLOCKS_PER_SEC;
    cout << t2-t1 << '\n';
//    printf("%f\n", t2-t1);
}
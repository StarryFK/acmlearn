#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int four[15];
int three[15];

int main(){
    memset(four, 0x3f, sizeof(four));
    memset(three, 0x3f, sizeof(three));
    three[0]=0;
    three[1]=1;
    three[2]=3;
    for(int i=3; i<13; i++){
        three[i] = 2*three[i-1]+1;
    }
    four[0]=0;
    four[1]=1;
    four[2]=3;
    four[3]=5;
    for(int i=4; i<13; i++){
        for(int k=1; k<i; k++){
            four[i] = min(four[i], 2*four[k]+three[i-k]);
        }
    }
    for(int i=1; i<13; i++){
        cout << four[i] << '\n';
    }
}
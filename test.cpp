#include <iostream>
using namespace std;

int main(){
    unsigned long long a = 1;
    for(int i=0; i<40; i++){
        cout << i << ':' << a%37 << endl;
        a <<= 1;
    }

}
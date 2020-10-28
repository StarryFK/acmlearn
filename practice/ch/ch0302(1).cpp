#include <iostream>
#include <cstdio>
using namespace std;

int s[100000];
int top=0, curadd=0;

int out[1000];
int size=0;

void call(int x, int add){
    s[top++] = x;
    s[top++] = add;
}

int ret(){
    curadd = s[--top];
    return s[--top];
}

int main(){
    int n,m;
    cin >> n >> m;
    call(1, 0);
    int x;
    while(top){
        //cout <<"top"<< top << endl;
        x = ret();
        //cout << "x"<< x << endl;
        switch(curadd){
            case 0:
                if(size == m){
                    for(int i=0; i<size; i++){
                        cout << out[i] << ' ';
                    }
                    cout << '\n';
                    continue;
                }
                if(x>n || size + (n-x+1)<m){
                    //cout << 'r' << endl;
                    continue;
                }
                out[size++] = x;
                call(x, 1);
                call(x+1, 0);
                continue;
            case 1:
                size--;
                call(x+1, 0);
                continue;
        }
    }
}

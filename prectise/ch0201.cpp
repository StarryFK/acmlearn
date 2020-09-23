#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int status;
bool ma[5][5];
bool cp[5][5];

void change(int x, int y){
    cp[x][y] = !cp[x][y];
    if(x-1>=0){
        cp[x-1][y] = !cp[x-1][y];
    }
    if(y-1>=0){
        cp[x][y-1] = !cp[x][y-1];
    }
    if(x+1<5){
        cp[x+1][y] = !cp[x+1][y];
    }
    if(y+1<5){
        cp[x][y+1] = !cp[x][y+1];
    }
}

int check(){
    int time=0;
    memcpy(cp, ma, sizeof(ma));
    for(int i=0; i<5; i++){
        if((status>>i)&1){
            change(0,i);
            time++;
        }
    }
    for(int i=1; i<5; i++){
        for(int j=0; j<5; j++){
            if(!cp[i-1][j]){
                change(i,j);
                time++;
            }
        }
    }
    bool flag=true;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(!cp[i][j]){
                flag=false;
            }
        }
    }
    if(flag){
        return time;
    }else{
        return -1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while(n--){
        char ch;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                cin >> ch;
                ma[i][j] = (ch-'0');
            }
        }

        //for(int i=0; i<5; i++){
        //    for(int j=0; j<5; j++){
        //        cout << ma[i][j];
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';

        int mintime=0x3f3f3f3f;
        for(status=0; status<32; status++){
            int time = check();
            if(time>=0){
                mintime = min(mintime, time);
            }
        }
//        cout << mintime << '\n';
        if(mintime<=6){
            cout << mintime << '\n';
        }else{
            cout << -1 << '\n';
        }
    }
}
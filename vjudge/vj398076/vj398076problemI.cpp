#include <iostream>
#include <string>
#include <stack>
#define ull unsigned long long
using namespace std;

char base[63]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

struct BigInt{
    string dec;
    void add(ull obj){
        int pos=0;
        bool high=false;
        int curnum=0;
        while(obj!=0){
            curnum = obj%10;
            if(high){
                curnum++;
            }
            high=false;
            if(curnum+(dec[pos]-'0')<10){
                dec[pos] += curnum;
            }else{
                high=true;
                dec[pos] = ((dec[pos]-'0')+curnum)%10;
            }
            obj /= 10;
        }
    }

    int div(ull obj){
        int pos=dec.length()-1;
        ull curnum = dec[pos]-'0';
        stack<int> s;
        while(pos>=0){
            while(curnum/obj==0 && pos>=0){
                curnum *= 10;
                curnum += dec[--pos];
            }
            s.push(curnum/obj);
            curnum %= obj;
        }
        dec.clear();
        while(!s.empty()){
            dec += s.top() + '0';
            s.pop();
        }
    }
};

int main(){
    int x,y;
    string z;
    ull temp;
    cin >> x >> y >> z;
    for(int i=0; i<z.length(); i++){
        
    }
}
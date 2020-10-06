#include <iostream>
using namespace std;

int ma[1005][1005];

int main(){
    int n;
    cin >> n;
    int x,y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> ma[i][j];
            if(ma[i][j] == -1){
                x=i;
                y=j;
            }
        }
    }
    if(x==0 && y==0){
        cout << ma[x+1][y] + ma[x][y+1] - ma[x+1][y+1] << endl;
    }else if(x==0 && y==n-1){
        cout << ma[x+1][y] + ma[x][y-1] - ma[x+1][y-1] << endl;
    }else if(x==n-1 && y==0){
        cout << ma[x-1][y] + ma[x][y+1] - ma[x-1][y+1] << endl;
    }else{
        cout << ma[x-1][y] + ma[x][y-1] - ma[x-1][y-1] << endl;
    }
}
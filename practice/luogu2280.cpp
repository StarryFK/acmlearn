#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int sum[5005][5005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(sum, 0, sizeof(sum));
    int n,m;
    cin >> n >>m;
    int x,y,v;
    for(int i=0; i<n; i++){
        cin >> x >> y >> v;
        sum[x][y] = v;
    }
    for(int i=1; i<5005; i++){
        sum[i][0] += sum[i-1][0];
        sum[0][i] += sum[0][i-1];
    }
    for(int i=1; i<5005; i++){
        for(int j=1; j<5005; j++){
            sum[i][j] += sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }

    int maxv=0;
    for(int i=0; i+m-1<5005; i++){
       for(int j=0; j+m-1<5005; j++){
           if(i==0 && j==0){
               maxv = max(sum[i+m-1][j+m-1], maxv);
           }else if(i==0){
               maxv = max(sum[i+m-1][j+m-1] - sum[i+m-1][j-1], maxv);
           }else if(j==0){
               maxv = max(sum[i+m-1][j+m-1]-sum[i-1][j+m-1], maxv);
           }else{
               maxv = max(sum[i+m-1][j+m-1]-sum[i-1][j+m-1]-sum[i+m-1][j-1]+sum[i-1][j-1], maxv);
           }
       } 
    }
    cout << maxv << '\n';
}
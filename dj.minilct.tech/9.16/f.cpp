#include <iostream>
using namespace std;

const int LEN = 1e5+5;

int l[LEN];
int sum[LEN];

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    sum[0]=0;
    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> l[i];
            sum[i+1] = l[i] + sum[i];
        }

 //       for(int i=0; i<n+1; i++){
 //           cout << sum[i] <<' ';
 //       }
 //       cout << endl;

        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(i-j-1 == sum[j+1]-sum[i]){

        //            cout << i << ' ' << j << endl;

                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
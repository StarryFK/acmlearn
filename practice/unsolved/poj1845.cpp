#include <cmath>
#include <cstring>
#include <iostream>
#define ull unsigned long long
using namespace std;

const int mod = 9901;

ull pf[7080];

bool getpf(ull n) {
    memset(pf, 0, sizeof(pf));
    bool prime = true;
    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            prime = false;
            pf[i]++;
            n /= i;
        }
    }
    return prime;
}

ull powmod(ull a, ull b) {
    ull result = 1;
    for (int i = 0; i < b; i++) {
        result = ((result % mod) * (a % mod))%mod;
    }
    return result;
}

ull summod(ull p, ull c) {

//    cout << p << ' ' << c << '\n';

    if(c==1){
        return p+1;
    }
    if (c & 1) {
        return ((1 + powmod(p, (c + 1) / 2)) * summod(p, (c - 1) / 2))%mod;
    } else {
        return (((1 + powmod(p, c / 2)) * summod(p, c / 2 - 1))%mod + powmod(p, c))%mod;
    }
}

int main() {
    ull a, b;
    cin >> a >> b;
    bool prime = getpf(a);
    ull result = 1;
    if (prime) {
        result = (result * summod(a, b))%mod;
    } else {
        for (int i = 2; i <= sqrt(a); i++) {
            if (pf[i] == 0) {
                continue;
            }
            result = (result * summod(i, b * pf[i]))%mod;
        }
    }
    cout << result << '\n';
}
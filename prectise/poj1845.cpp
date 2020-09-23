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
        result = (result % mod) * (a % mod);
    }
}

ull summod(ull p, ull c) {
    if (p & 1) {
        return (1 + powmod(p, (c + 1) / 2)) * summod(p, (c - 1) / 2);
    } else {
        return (1 + powmod(p, c / 2)) * summod(p, c / 2 - 1) + powmod(p, c);
    }
}

int main() {
    ull a, b;
    cin >> a >> b;
    bool prime = getpf(a);
    ull result = 1;
    if (prime) {
        result = result * summod(a, b);
    } else {
        for (int i = 2; i <= sqrt(a); i++) {
            if (pf[i] == 0) {
                continue;
            }
            result = result * summod(i, b * pf[i]);
        }
    }
    cout << result << '\n';
}
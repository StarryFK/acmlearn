#include <algorithm>
#include <cstdio>
void chkmax1(int& x, int y) {
    if (x < y) x = y;
}
void chkmax2(int& x, int y) {
    if (x > y) x = y;
}
void chkmax3(int x, int y) { x = std::max(x, y); }
void chkmin1(int& x, int y) {
    if (x > y) x = y;
}
void chkmin2(int& x, int y) {
    if (x < y) x = y;
}
void chkmin3(int x, int y) { x = std::min(x, y); }
int a, b, c, d, e;
int main() {
    scanf("%d %d %d", &a, &b, &c);
    // 1:
    printf("%d", std::max({a, b, c}));
    // 2:
    printf("%d", std::min({a, b, c}));
    // 3:
    printf("%d", std::max(a, std::max(b, c)));
    // 4:
    chkmax1(a, b);
    chkmax1(a, c);
    printf("%d", a);
    // 5:
    chkmax2(a, b);
    chkmax2(a, c);
    printf("%d", a);
    // 6:
    chkmax3(a, b);
    chkmax3(a, c);
    printf("%d", a);
    // 7:
    chkmin1(a, b);
    chkmin1(a, c);
    printf("%d", a);
    // 8:
    chkmin2(a, b);
    chkmin2(a, c);
    printf("%d", a);    
    // 9:
    chkmin3(a, b);
    chkmin3(a, c);
    printf("%d", a);
    // 10:
    if (a > b)
        d = a;
    else
        d = b;
    if (c > d)
        e = c;
    else
        e = d;
    printf("%d", e);
}

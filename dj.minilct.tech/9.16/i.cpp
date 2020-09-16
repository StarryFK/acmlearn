#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int m = 0, g = 0;
    char qp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> qp[i][j];
            if (qp[i][j] == 'G') {
                g++;
            } else if (qp[i][j] == 'M') {
                m++;
            }
        }
    }
    if (m - g == 0 || m - g == 1) {
        bool mwin = false, gwin = false;
        for (int i = 0; i < 3; i++) {
            int tot1 = 0, tot2 = 0;
            for (int j = 0; j < 3; j++) {
                tot1 += qp[i][j];
                tot2 += qp[j][i];
            }
            if (tot1 / 3 == 'M' || tot2 / 3 == 'M') {
                mwin = true;
            }
            if (tot1 / 3 == 'G' || tot2 / 3 == 'G') {
                gwin = true;
            }
        }
        int tot1 = 0, tot2 = 0;
        for (int i = 0; i < 3; i++) {
            tot1 += qp[i][i];
            tot2 += qp[i][2 - i];
        }
        if (tot1 / 3 == 'M' || tot2 / 3 == 'M') {
            mwin = true;
        }
        if (tot1 / 3 == 'G' || tot2 / 3 == 'G') {
            gwin = true;
        }
        if (mwin && gwin) {
            cout << "Illegal" << endl;
        } else if (mwin) {
            if (m > g)
                cout << "Myf win" << endl;
            else
                cout << "Illegal" << endl;
        } else if (gwin) {
            if (m == g)
                cout << "AlphaGo win" << endl;
            else
                cout << "Illegal" << endl;
        } else {
            if (m == g) {
                cout << "It's myf's turn" << endl;
            } else {
                if (m + g < 9) {
                    cout << "It's AlphaGo's turn" << endl;
                } else {
                    cout << "Draw" << endl;
                }
            }
        }
    } else {
        //   cout << m <<g <<endl;
        cout << "Illegal" << endl;
    }
}
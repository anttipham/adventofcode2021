#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int a[N][N]={0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1,y1,x2,y2;
    char q;
    string w;
    // 0,9 -> 5,9
    // 8,0 -> 0,8
    // 9,4 -> 3,4
    // 2,2 -> 2,1
    // 7,0 -> 7,4
    // 6,4 -> 2,0
    // 0,9 -> 2,9
    // 3,4 -> 1,4
    // 0,0 -> 8,8
    // 5,5 -> 8,2
    while (cin >> x1 >> q >> y1 >> w >> x2 >> q >> y2) {
        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        if (x1 != x2 && y1 != y2) {
            if (x1-x2 == y1-y2) {
                // "\"
                for (int i=0; i<=x2-x1; i++) {
                    a[x1+i][y1+i]++;
                }

            } else {
                // "/"
                for (int i=0; i<=x2-x1; i++) {
                    a[x1+i][y1-i]++;
                }
            }
        } else {
            if (x1 > x2) swap(x1, x2);
            if (y1 > y2) swap(y1, y2);
            for (int i=x1; i<=x2; i++) {
                for (int j=y1; j<=y2; j++) {
                    a[i][j]++;
                }
            }
        }
    }
    int res=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (a[i][j] >= 2) res++;
            // if (a[j][i] == 0) cout << ".";
            // else cout << a[j][i];
        }
        // cout << "\n";
    }
    cout << res;
}

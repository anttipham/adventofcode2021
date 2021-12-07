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
    while (cin >> x1 >> q >> y1 >> w >> x2 >> q >> y2) {
        if (x1 != x2 && y1 != y2) continue;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        for (int i=x1; i<=x2; i++) {
            for (int j=y1; j<=y2; j++) {
                a[i][j]++;
            }
        }
    }
    int res=0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (a[i][j] >= 2) res++;
        }
    }
    cout << res;
}
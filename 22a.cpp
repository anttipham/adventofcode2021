#include <bits/stdc++.h>
using namespace std;

const int N = 101;
bool arr[N][N][N]={};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char cs[4];
    int x1,x2,y1,y2,z1,z2;
    while (scanf("%s x=%d..%d,y=%d..%d,z=%d..%d", &cs, &x1, &x2, &y1, &y2, &z1, &z2) == 7) {
        string s(cs);
        x1 += N/2;
        x1 = max(x1, 0);
        y1 += N/2;
        y1 = max(y1, 0);
        z1 += N/2;
        z1 = max(z1, 0);

        x2 += N/2;
        x2 = min(x2, N-1);
        y2 += N/2;
        y2 = min(y2, N-1);
        z2 += N/2;
        z2 = min(z2, N-1);

        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                for (int k = z1; k <= z2; k++) {
                    arr[i][j][k] = s == "on" ? 1 : 0;
                }
            }
        }
    }

    int c = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (arr[i][j][k]) c++;
            }
        }
    }
    cout << c;
}
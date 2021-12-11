#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const int N=10;
int octo[N][N] = {}, check[N][N] = {};

void inc(int i, int j) {
    if (i<0 || i>=N) return;
    if (j<0 || j>=N) return;
    if (check[i][j]) return;

    octo[i][j]++;

    if (octo[i][j] > 9) {
        octo[i][j] = 0;
        check[i][j] = 1;
        inc(i-1, j-1);
        inc(i-1, j);
        inc(i-1, j+1);
        inc(i, j-1);
        inc(i, j+1);
        inc(i+1, j-1);
        inc(i+1, j);
        inc(i+1, j+1);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char c;
            cin >> c;
            octo[i][j] = c - '0';
        }
    }

    int step = 0;
    while (true) {
        step++;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                inc(i,j);
            }
        }
        int flashes = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (check[i][j]) {
                    flashes++;
                    check[i][j]=false;
                }
            }
        }
        if (flashes == N*N) break;
    }
    cout << step;
}
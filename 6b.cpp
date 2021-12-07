#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long f[10] = {};

    long long fish;
    char _;
    while (cin >> fish >> _) {
        f[fish]++;
    }
    f[fish]++;
    for (int i=0; i<256; i++) {
        long long uusia = f[0];
        for (int j=0; j<9; j++) {
            f[j] = f[j+1];
        }
        f[6] += uusia;
        f[8] += uusia;
    }
    long long s=0;
    for (auto a : f) s+=a;
    cout <<s;
}
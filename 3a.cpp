#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int bits[12] = { 0 };
    string bit;
    while (cin >> bit) {
        for (int i=0; i<12; i++) {
            if (bit[i] == '1') {
                bits[i]++;
            }
        }
    }

    for (auto i : bits) {
        cout << i << "\n";
    }
    int gam=0, eps=0;
    for (int i=0; i<12; i++) {
        if (bits[i] > 500) {
            gam = gam + (1<<(12-i-1));
        }
    }
    eps = 0b111111111111 & (~gam);

    cout << gam << " " << eps << "\n";
    cout << gam*eps;
}
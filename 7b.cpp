#include <bits/stdc++.h>
using namespace std;

const int N=1882;

int fuel_con(int dx) {
    return ((1 + dx) * dx) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> pos;
    int p;
    char _;
    while (cin >> p >> _) {
        pos.push_back(p);
    }
    pos.push_back(p);

    long long f = INT64_MAX;
    for (int x1 = 0; x1 < N; x1++) {
        long long s=0;
        for (auto &&x2 : pos) {
            s += fuel_con(abs(x1-x2));
        }
        f = min(f, s);
    }

    cout << f;
}
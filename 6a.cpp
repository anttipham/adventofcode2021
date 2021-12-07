#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> f;

    int fish;
    char _;
    while (cin >> fish >> _) {
        f.push_back(fish);
    }
    f.push_back(fish);

    for (int i=0; i<80; i++) {
        int koko = f.size();
        for (int j=0; j<koko; j++) {
            if (f[j]) {
                f[j]--;
            } else {
                f[j] = 6;
                f.push_back(8);
            }
        }
        // for (auto a : f) cout << a << " ";
        // cout << "\n";
    }
    cout << f.size();
}
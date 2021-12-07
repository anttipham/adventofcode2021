#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x;
    vector<int> v;
    while (cin >> x) v.push_back(x);

    int prev=0, cur, c=-1;
    for (int i=0; i<v.size()-2; i++) {
        cur = v[i] + v[i+1] + v[i+2];
        if (cur > prev) c++;
        prev = cur;
    }

    cout << c;
}
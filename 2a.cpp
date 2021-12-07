#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int x, dep=0, hor=0;
    while (cin >> s >> x) {
        if (s == "forward") hor += x;
        if (s == "down") dep += x;
        if (s == "up") dep -= x;
    }
    cout << dep*hor;
}
#include <bits/stdc++.h>
using namespace std;


int f(string s) {
    vector<char> c;

    for (auto a : c) {
        switch (a) {
        case ')':
            if (c.back() != '(') return 3;
            c.pop_back();
        case ']':
            if (c.back() != '[') return 57;
            c.pop_back();
        case '}':
            if (c.back() != '{') return 1197;
            c.pop_back();
        case '>':
            if (c.back() != '<') return 25137;
            c.pop_back();
        default:
            c.push_back(a);
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    long long x=0;
    while (cin >> s) {
        x += f(s);
    }
    cout << x;
}
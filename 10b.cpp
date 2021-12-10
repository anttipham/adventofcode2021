#include <bits/stdc++.h>
using namespace std;

long long f(string s) {
    vector<char> c;

    for (auto a : s) {
        switch (a) {
        case ')':
            if (c.back() != '(') return 0;
            c.pop_back();
            break;
        case ']':
            if (c.back() != '[') return 0;
            c.pop_back();
            break;
        case '}':
            if (c.back() != '{') return 0;
            c.pop_back();
            break;
        case '>':
            if (c.back() != '<') return 0;
            c.pop_back();
            break;
        default:
            c.push_back(a);
            break;
        }
    }

    long long y=0;
    while (c.size()) {
        y*=5;
        switch (c.back()) {
        case '(':
            y+=1;
            break;
        case '[':
            y+=2;
            break;
        case '{':
            y+=3;
            break;
        case '<':
            y+=4;
            break;
        }
        c.pop_back();
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    vector<long long> x;
    while (cin >> s) {
        auto z = f(s);
        if (z) x.push_back(z);
    }
    sort(x.begin(), x.end());
    for (auto w : x) cout << w << " ";
    cout << "\n" << x[x.size() / 2];
}
#include <bits/stdc++.h>
using namespace std;

vector<string> v;

char get_point(int i, int j) {
    if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size()) {
        return CHAR_MAX;
    }
    return v[i][j];
}

bool get_area(int i, int j) {
    char cur = get_point(i, j);
    if (get_point(i-1, j) <= cur
        || get_point(i+1, j) <= cur
        || get_point(i, j-1) <= cur
        || get_point(i, j+1) <= cur)
    {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (cin >> s) {
        v.push_back(s);
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (get_area(i, j)) {
                sum += v[i][j] - '0' + 1;
            }
        }
    }
    cout << sum;
}
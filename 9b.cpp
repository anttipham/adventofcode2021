#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<vector<bool>> b;

int get_area(int i, int j) {
    if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size()) return 0;
    if (v[i][j] == '9' || b[i][j]) return 0;
    b[i][j] = 1;

    int area = 1
               + get_area(i-1, j)
               + get_area(i+1, j)
               + get_area(i, j-1)
               + get_area(i, j+1);
    return area;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (cin >> s) {
        v.push_back(s);
    }
    b.resize(v.size());
    for (auto&& bi : b) {
        bi.resize(v[0].size());
    }

    multiset<int> areas;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            int area = get_area(i, j);
            if (!area) continue;

            areas.insert(area);
            if (areas.size() > 3) {
                areas.erase(areas.begin());
            }
        }
    }
    int r=1;
    for (auto area : areas) r *= area;
    cout << r;
}
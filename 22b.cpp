#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Cube {
    ll x1, x2, y1, y2, z1, z2;

    bool operator<(const Cube &o) const {
        return std::tie(x1, x2, y1, y2, z1, z2) < std::tie(o.x1, o.x2, o.y1, o.y2, o.z1, o.z2);
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<Cube, ll> m, m_update;

    char cs[4];
    int x1,x2,y1,y2,z1,z2;
    while (scanf("%s x=%d..%d,y=%d..%d,z=%d..%d", &cs, &x1, &x2, &y1, &y2, &z1, &z2) == 7) {
        string s(cs);

        m_update.clear();
        if (s == "on") {
            m_update[{x1,x2,y1,y2,z1,z2}]++;
        }
        for (auto [c, v] : m) {
            // get intersection
            Cube i {
                max((ll)x1, c.x1),
                min((ll)x2, c.x2),
                max((ll)y1, c.y1),
                min((ll)y2, c.y2),
                max((ll)z1, c.z1),
                min((ll)z2, c.z2),
            };
            // if no intersection
            if (i.x1 > i.x2 || i.y1 > i.y2 || i.z1 > i.z2) {
                continue;
            }
            // if has intersection, cancel out the value
            m_update[i] -= v;
        }
        // add to the map
        for (auto [c, v] : m_update) {
            // cout << "Add: " << c.x1 << " " << c.x2 << " " << c.y1 << " " << c.y2 << " " << c.z1 << " " << c.z2 << " | " << v << "\n";
            m[c] += v;
        }
        // for (auto [c, v] : m) {
        //     cout << "Now: " << c.x1 << " " << c.x2 << " " << c.y1 << " " << c.y2 << " " << c.z1 << " " << c.z2 << " | " << v << "\n";
        // }
    }
    long long res = 0;
    for (auto [c, v] : m) {
        res += v * (c.x2 - c.x1 + 1) * (c.y2 - c.y1 + 1) * (c.z2 - c.z1 + 1);
    }
    cout << res << "\n";
}
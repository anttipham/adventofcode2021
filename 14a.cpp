#include <bits/stdc++.h>
using namespace std;

string s;
map<pair<char,char>, char> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    char a, b, c;
    while (cin>>a>>b>>c>>c>>c) {
        cout << a<< " "<<b<<" "<<c<<"\n";
        m.insert({{a,b},c});
    }

    for (int i=0;i<10;i++) {
        string ss;
        for (int j=0; j<s.size()-1;j++) {
            ss.push_back(s[j]);
            if (m.count({s[j], s[j+1]})) {
                ss.push_back(m[{s[j], s[j+1]}]);
            }
        }
        ss.push_back(s.back());
        s = ss;
    }
    map<char,int> w;
    for (auto q : s) w[q]++;
    int ma=0, mi=INT32_MAX;
    for (auto q : w) {
        ma=max(ma,q.second);
        mi=min(mi,q.second);
    }
    cout << ma-mi;
}
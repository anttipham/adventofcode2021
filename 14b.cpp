#include <bits/stdc++.h>
using namespace std;

string s;
map<pair<char,char>, char> m;
map<pair<char,char>, long long> t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    {char a, b, c;
    while (cin>>a>>b>>c>>c>>c) {
        cout << a<< " "<<b<<" "<<c<<"\n";
        m.insert({{a,b},c});
    }}
    for (int i=0;i<s.size()-1;i++) t[{s[i],s[i+1]}]++;

    for (int i=0;i<40;i++) {
        map<pair<char,char>, long long> tt;
        for (auto [f, s] : t) {
            tt[{f.first, m[f]}]+=s;
            tt[{m[f], f.second}]+=s;
        }
        t = tt;
    }
    map<char,long long> w;
    for (auto [f, s] : t) {
        w[f.second]+=s;
        w[f.first]+=s;
    }
    w[s.front()]++;
    w[s.back()]++;

    long long ma=0, mi=INT64_MAX, su=0;
    for (auto q : w) {
        su+=q.second;
        cout << q.first << " " << q.second << "\n";
        ma=max(ma,q.second);
        mi=min(mi,q.second);
    }
    cout << (ma-mi)/2 << "\n";
}
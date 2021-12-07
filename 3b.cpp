#include <bits/stdc++.h>
using namespace std;

const int N=12;

template<typename T, typename f>
bool filter(vector<T>& v, f pred) {
    vector<T> v2;
    copy_if(v.begin(), v.end(), back_inserter(v2), pred);
    if (v.size() == v2.size()) return false;
    swap(v, v2);
    return true;
}

vector<int> count_bits(vector<string>& a) {
    vector<int> bits;
    bits.resize(N);
    for (auto&& bit : a) {
        for (int i=0; i<N; i++) {
            if (bit[i] == '1') {
                bits[i]++;
            }
        }
    }
    return bits;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> o, co;
    string in_bit;
    while (cin >> in_bit) {
        o.push_back(in_bit);
    }
    co = o;

    for (int i=0; i<N; i++) {
        if (o.size() == 1) break;
        auto bits = count_bits(o);
        char bit = bits[i] > o.size() / 2.0 ? '1' : '0';
        if (bits[i] == o.size() / 2.0) {
            // nothing was filtered out
            filter(o, [&](string v){ return v[i] == '1'; });
            continue;
        } else {
            filter(o, [&](string v){ return v[i] == bit; });
        }
    }

    for (int i=0; i<N; i++) {
        if (co.size() == 1) break;
        auto bits = count_bits(co);
        char bit = bits[i] < co.size() / 2.0 ? '1' : '0';
        if (bits[i] == co.size() / 2.0) {
            // nothing was filtered out
            filter(co, [&](string v){ return v[i] == '0'; });
            continue;
        } else {
            filter(co, [&](string v){ return v[i] == bit; });
        }
    }

    cout << o[0] << " " << co[0] << "\n";
    cout << stoi(o[0], 0, 2) * stoi(co[0], 0, 2) << "\n";
}
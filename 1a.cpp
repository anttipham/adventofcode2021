#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, prev, x=0;
    cin >> prev;
    while (cin >> d) {
        if (d > prev) x++;
        prev = d;
    }
    cout << x;
}
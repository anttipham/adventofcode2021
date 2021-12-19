#include <bits/stdc++.h>
using namespace std;

int maxY(int dy) {
    int y=0;
    while (dy) {
        y+=dy;
        dy--;
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, x2, y1, y2;
    scanf("target area: x=%d..%d, y=%d..%d", &x1, &x2, &y1, &y2);

    int dy=abs(y1)-1;
    cout << maxY(dy);
}
#include <bits/stdc++.h>
using namespace std;

bool xyInArea(int dx, int dy, int xArea1, int xArea2, int yArea1, int yArea2) {
    int x=0;
    int y=0;
    while (y > yArea1 && x < xArea2) {
        x+=dx;
        y+=dy;
        if (dx > 0) dx--;
        dy--;
        if (xArea1 <= x && x <= xArea2 && yArea1 <= y && y <= yArea2) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, x2, y1, y2;
    scanf("target area: x=%d..%d, y=%d..%d", &x1, &x2, &y1, &y2);

    int xCount=0, yCount=0;
    int count=0;
    int dyMax=abs(y1)-1;
    for (int dy=y1; dy<=dyMax; dy++) {
        for (int dx=1; dx<=x2; dx++) {
            if (xyInArea(dx, dy, x1, x2, y1, y2)) {
                count++;
                // cout << dx << "," << dy << "\n";
            }
        }
    }
    cout << count;
}
#include <bits/stdc++.h>
using namespace std;

const int N=101, ERR=-1;
vector<string> arr;
bool visited[N][N] = {};
int n = 0;
multimap<int, pair<int,int>> cur;

int get_arr(int i, int j) {
    if (i < 0 || j < 0 || i > n || j > n) return ERR;
    return arr[i][j] - '0';
}

void visit(int prev_val, int i, int j) {
    int risk_val = get_arr(i, j);
    if (risk_val == ERR) return;
    if (visited[i][j]) return;

    int cur_val = prev_val + risk_val;
    cur.insert({cur_val, {i,j}});
}

int dijkstra() {
    cur.insert({0, {0,0}});

    while (cur.size()) {
        auto cur_it = cur.begin();
        auto p = cur_it->second;
        auto [i,j] = p;
        cur.erase(cur_it);

        if (visited[i][j]) continue;
        visited[i][j] = 1;

        if (i==n && j==n) {
            return cur_it->first;
        }
        auto val = cur_it->first;
        visit(val, i-1, j);
        visit(val, i+1, j);
        visit(val, i, j-1);
        visit(val, i, j+1);

    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string ss;
    while (cin >> ss) {
        arr.push_back(ss);
    }

    n = arr.size() - 1;
    cout << dijkstra() << "\n";
}
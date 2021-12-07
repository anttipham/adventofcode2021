#include <bits/stdc++.h>
using namespace std;

int n = 0;
vector<int> nums;
set<int> deta;
vector<array<array<int, 5>, 5>> boards;

int has_bingo() {
    int sum, res=0;
    bool found =0;
    for (auto& board : boards) {
        sum=0;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                // if (deta.count(24)) cout << sum << " ";
                if (!deta.count(board[i][j])) {
                    sum += board[i][j];
                }
            }
            // if (deta.count(24)) cout << "\n";
        }
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (!deta.count(board[i][j])) break;
                res++;
                if (res == 5) return sum;
            }
            res=0;
            for (int j=0; j<5; j++) {
                if (!deta.count(board[j][i])) break;
                res++;
                if (res == 5) return sum;
            }
            res=0;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string in = "";
    while (cin >> in) {
        if (in == ".") break;
        nums.push_back(stoi(in));
    }

    while (!cin.eof()) {
        array<array<int, 5>, 5> board;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                cin >> in;
                board[i][j] = stoi(in);
            }
        }
        boards.push_back(board);
    }

    for (auto& num : nums) {
        deta.insert(num);
        auto a = has_bingo();
        if (a) {
            cout << a << " " << num << " " << a*num;
            break;
        }
    }
}
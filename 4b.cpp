#include <bits/stdc++.h>
using namespace std;

int n = 0;
vector<int> nums;
set<int> deta;
vector<array<array<int, 5>, 5>> boards;

// int has_bingo() {
//     int sum, res=0;
//     bool found =0;
//     for (auto& board : boards) {
//         sum=0;
//         for (int i=0; i<5; i++) {
//             for (int j=0; j<5; j++) {
//                 // if (deta.count(24)) cout << sum << " ";
//                 if (!deta.count(board[i][j])) {
//                     sum += board[i][j];
//                 }
//             }
//             // if (deta.count(24)) cout << "\n";
//         }
//         for (int i=0; i<5; i++) {
//             res=0;
//             for (int j=0; j<5; j++) {
//                 if (deta.count(board[i][j])) res++;
//             }
//             if (res == 0) {
//                 return 0;
//             }
//             res=0;
//             for (int j=0; j<5; j++) {
//                 if (deta.count(board[j][i])) res++;
//             }
//             if (res == 0) {
//                 return 0;
//             }
//         }
//     }
//     return max(sum,1);
// }
int has_bingo(array<array<int, 5>, 5>& board) {
    int sum, res=0;
    bool found =0;
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
            if (res == 5) return max(sum, 1);
        }
        res=0;
        for (int j=0; j<5; j++) {
            if (!deta.count(board[j][i])) break;
            res++;
            if (res == 5) return max(sum, 1);
        }
        res=0;
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
    boards.pop_back();

    for (auto& num : nums) {
        deta.insert(num);
    }
    for (int i = nums.size()-1; i>=0; i--) {
        int num = nums[i];
        deta.erase(num);
        for (int j=0; j<boards.size(); j++) {
            auto a = has_bingo(boards[j]);
            if (!a) {
                cout << i << " " << j << "\n";
                deta.insert(num);
                auto c = has_bingo(boards[j]);
                cout << c << " " << num << " " << c*num;
                return 0;
            }
        }
    }
}
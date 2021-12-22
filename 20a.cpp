#include <bits/stdc++.h>
using namespace std;

const int R = 2;
const int N = 500;
// const int N = 30;
const int M = 512;
bool arr[N][N] = {}, arr0[N][N] = {}, convert[M];

int from_bits(int ii, int jj) {
    int b = 0;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            b <<= 1;
            b += arr[ii+i][jj+j];
        }
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // parse "image enhancement algorithm"
    char c;
    for (int i=0; i<M; i++) {
        cin >> c;
        convert[i] = c == '#' ? 1 : 0;
    }

    // parse input
    string s;
    int half = N/2;
    for (int i = 0; i < N; i++) {
        cin >> s;
        int halfS = s.size() / 2;
        for (int j = 0; j < s.size(); j++) {
            arr[half+i-halfS][half+j-halfS] = s[j] == '#' ? 1 : 0;
        }
        if (i+1 == s.size()) break;
    }

    // debug print
    // for (int i=1; i<N-1; i++) {
    //     for (int j=1; j<N-1; j++) {
    //         cout << (arr[i][j] ? "#" : ".");
    //     }
    //     cout << "\n";
    // }

    // apply "image enhancement"
    for (int n=1; n<R+1; n++) {
        fill((bool*)arr0, (bool*)arr0+N*N, 0);
        for (int i=n; i<N-n; i++) {
            for (int j=n; j<N-n; j++) {
                arr0[i][j] = convert[from_bits(i,j)];
            }
        }
        swap(arr, arr0);
    }

    int count = 0;
    for (int i=R+1; i<N-R+1; i++) {
        for (int j=1; j<N-1; j++) {
            if (arr[i][j]) count++;
        }
    }
    cout << count;
}
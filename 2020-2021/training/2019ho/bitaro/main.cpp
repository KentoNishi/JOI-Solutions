// Test case path: [path]
// https://atcoder.jp/contests/joi2019ho/tasks/joi2019ho_a

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    auto grid = vector<vector<char>>(H, vector<char>(W));
    auto oInRow = vector<vector<int>>(H, vector<int>(W));
    auto iInCol = vector<vector<int>>(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char &c = grid[i][j];
            cin >> c;
            if (c == 'O') {
                oInRow[i][j]++;
            } else if (c == 'I') {
                iInCol[i][j]++;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = W - 2; j >= 0; j--) {
            oInRow[i][j] += oInRow[i][j + 1];
        }
    }
    for (int i = H - 2; i >= 0; i--) {
        for (int j = 0; j < W; j++) {
            iInCol[i][j] += iInCol[i + 1][j];
        }
    }
    int64 ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'J') {
                ans += oInRow[i][j] * iInCol[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
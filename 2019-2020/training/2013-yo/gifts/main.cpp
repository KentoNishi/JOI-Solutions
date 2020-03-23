// Test case path: [path]
// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_f

#include <bits/stdc++.h>
using namespace std;

int H, W, K;

vector<vector<int>> grid;
int ans = 0;

void doFill(int x, int y, int k, int total, vector<vector<bool>> picked) {
    if (x < 0 || y < 0 || x >= H || y >= W || k == -1 || grid[x][y] == -1) {
        return;
    }
    if (!picked[x][y]) {
        total += grid[x][y];
    }
    picked[x][y] = true;
    if (x == H - 1 && y == W - 1) {
        ans = max(ans, total);
    }
    doFill(x + 1, y, k, total, picked);
    doFill(x, y + 1, k, total, picked);
    doFill(x - 1, y, k - 1, total, picked);
    doFill(x, y - 1, k - 1, total, picked);
}

int main() {
    cin >> H >> W >> K;
    grid = vector<vector<int>>(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[i][j] = 0;
            } else if (c == '#') {
                grid[i][j] = -1;
            } else {
                grid[i][j] = c - '0';
            }
        }
    }
    doFill(0, 0, K, 0, vector<vector<bool>>(H, vector<bool>(W)));
    cout << ans << endl;
    return 0;
}
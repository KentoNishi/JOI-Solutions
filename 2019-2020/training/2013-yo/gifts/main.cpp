// Test case path: [path]
// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_f

#include <bits/stdc++.h>
using namespace std;

int H, W, K;

vector<vector<int>> grid;

int doFill(int x, int y, int k, vector<vector<bool>> pickedUp) {
    if (x < 0 || y < 0 || x >= H || y >= W || k == -1 || grid[x][y] == -1) {
        return -1;
    }
    int thisStore = (pickedUp[x][y] ? 0 : grid[x][y]);
    pickedUp[x][y] = true;
    vector<int> results = {doFill(x + 1, y, k, pickedUp),
                           doFill(x, y + 1, k, pickedUp),
                           doFill(x - 1, y, k - 1, pickedUp),
                           doFill(x, y - 1, k - 1, pickedUp)};
    int local = -1;
    for (int &result : results) {
        if (result != -1) {
            local = max(local, result + thisStore);
        }
    }
    if (x == H - 1 && y == W - 1) {
        return max(local, grid[x][y]);
    }
    return local;
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
    vector<vector<bool>> pickedUp = vector<vector<bool>>(H, vector<bool>(W));
    cout << doFill(0, 0, K, pickedUp) << endl;
    return 0;
}
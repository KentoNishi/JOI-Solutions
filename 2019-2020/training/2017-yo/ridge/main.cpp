// Test case path: [path]

#include <bits/stdc++.h>
using namespace std;

int H, W;

struct Pixel {
    int h;
    set<int> to;
};

vector<vector<Pixel>> grid;

set<int> drop(int i, int j) {
    if (i < 0 || i >= H || j < 0 || j >= W) {
        return {};
    }
    if (grid[i][j].to.size() > 0) {
        return grid[i][j].to;
    }
    set<int> canGo;
    vector<int> d0 = {0, 0, 1, -1};
    vector<int> d1 = {1, -1, 0, 0};
    for (int k = 0; k < 4; k++) {
        if (i + d0[k] < 0 || i + d0[k] >= H || j + d1[k] < 0 || j + d1[k] >= W) {
            continue;
        }
        if (grid[i + d0[k]][j + d1[k]].h < grid[i][j].h) {
            set<int> res = drop(i + d0[k], j + d1[k]);
            canGo.insert(res.begin(), res.end());
        }
    }
    if (canGo.size() == 0) {
        canGo.insert(i * 1001 + j);
    }
    grid[i][j].to = canGo;
    return canGo;
}

int main() {
    cin >> H >> W;
    grid = vector<vector<Pixel>>(H, vector<Pixel>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j].h;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j].to.size() == 0) {
                drop(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j].to.size() > 1) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
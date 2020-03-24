// Test case path: [path]
// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_f

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int64 H, W, K;

vector<vector<int64>> grid;
vector<vector<vector<map<set<int64>, int64>>>> memo;
vector<vector<int64>> shopID;

bool inSet(set<int64> &s, int64 n) {
    return s.find(n) != s.end();
}

bool inMap(map<set<int64>, int64> &m, set<int64> &s) {
    return m.find(s) != m.end();
}

int64 doFill(int64 x, int64 y, int64 k, set<int64> pickedUp) {
    if (x < 0 || y < 0 || x >= H || y >= W || k == -1 || grid[x][y] == -1) {
        return -1;
    }
    if (inMap(memo[x][y][k], pickedUp)) {
        return memo[x][y][k][pickedUp];
    }
    int64 thisStore = (inSet(pickedUp, shopID[x][y]) ? 0 : grid[x][y]);
    set<int64> pickedBefore = pickedUp;
    pickedUp.insert(shopID[x][y]);
    vector<int64> results = {doFill(x + 1, y, k, pickedUp),
                             doFill(x, y + 1, k, pickedUp),
                             doFill(x - 1, y, k - 1, pickedUp),
                             doFill(x, y - 1, k - 1, pickedUp)};
    int64 local = -1;
    for (int64 &result : results) {
        if (result != -1) {
            local = max(local, result + thisStore);
        }
    }
    if (x == H - 1 && y == W - 1) {
        memo[x][y][k][pickedBefore] = max(local, grid[x][y]);
        return memo[x][y][k][pickedBefore];
    }
    memo[x][y][k][pickedBefore] = local;
    return local;
}

int main() {
    cin >> H >> W >> K;
    grid = vector<vector<int64>>(H, vector<int64>(W, -1));
    shopID = grid;
    int64 id = 0;
    for (int64 i = 0; i < H; i++) {
        for (int64 j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[i][j] = 0;
            } else if (c == '#') {
                grid[i][j] = -1;
            } else {
                grid[i][j] = c - '0';
                shopID[i][j] = id++;
            }
        }
    }
    memo = vector<vector<vector<map<set<int64>, int64>>>>(
        H,
        vector<vector<map<set<int64>, int64>>>(
            W,
            vector<map<set<int64>, int64>>(
                K + 1)));
    cout << doFill(0, 0, K, set<int64>()) << endl;
    return 0;
}
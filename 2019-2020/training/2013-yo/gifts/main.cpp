// Test case path: [path]
// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_f

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int64 H, W, K;

struct Point {
    int64 x;
    int64 y;
    Point(int64 x, int64 y) {
        this->x = x;
        this->y = y;
    }
};

struct State {
    Point p;
    int64 k;
    set<Point> pickedUp;
};

bool operator<(const Point &a, const Point &b) {
    return (a.x == b.x ? (a.y < b.y) : (a.x < b.x));
}
bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}
bool operator<(const State &a, const State &b) {
    return (a.p == b.p) ? (a.k == b.k ? (a.pickedUp < b.pickedUp) : (a.k < b.k)) : (a.p < b.p);
}

vector<vector<int64>> grid;
map<State, int64> memo;

bool alreadyPickedUp(set<Point> &pickedUp, int64 x, int64 y) {
    return pickedUp.find(Point(x, y)) != pickedUp.end();
}

bool alreadyVisited(State state) {
    return memo.find(state) != memo.end();
}

int64 doFill(int64 x, int64 y, int64 k, set<Point> pickedUp) {
    if (x < 0 || y < 0 || x >= H || y >= W || k == -1 || grid[x][y] == -1) {
        return -1;
    }
    State state = {{x, y}, k, pickedUp};
    if (alreadyVisited(state)) {
        return memo[state];
    }
    int64 thisStore = 0;
    if (!alreadyPickedUp(pickedUp, x, y)) {
        thisStore = grid[x][y];
    }
    if (grid[x][y] > 0) {
        pickedUp.insert({x, y});
    }
    for (auto iter = pickedUp.begin(); iter != pickedUp.end(); iter++) {
        if (max(x - iter->x, 0LL) + max(y - iter->y, 0LL) > K) {
            pickedUp.erase(iter);
            iter--;
        }
    }
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
        memo[state] = max(local, grid[x][y]);
    } else {
        memo[state] = local;
    }
    return memo[state];
}

int main() {
    cin >> H >> W >> K;
    grid = vector<vector<int64>>(H, vector<int64>(W, -1));
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
            }
        }
    }
    memo = map<State, int64>();
    cout << doFill(0, 0, K, set<Point>()) << endl;
    return 0;
}
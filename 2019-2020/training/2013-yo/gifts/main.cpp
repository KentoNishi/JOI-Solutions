// Test case path: [path]
// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_f

#include <bits/stdc++.h>
using namespace std;

int H, W, K;

struct State {
    int x;
    int y;
    int k;
    vector<pair<int, int>> pickedUp;
};

bool operator<(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.first == b.first ? (a.second < b.second) : (a.first < b.first));
}

bool operator==(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first == b.first && a.second == b.second;
}

bool operator<(const State &a, const State &b) {
    return make_pair(make_pair(a.x, a.y), make_pair(a.k, a.pickedUp)) <
           make_pair(make_pair(b.x, b.y), make_pair(b.k, b.pickedUp));
}

int grid[51][51];
map<State, int> memo = map<State, int>();

bool alreadyVisited(State &state) {
    return memo.find(state) != memo.end();
}

bool alreadyPickedUp(vector<pair<int, int>> &pickedUp, int x, int y) {
    return find(pickedUp.begin(), pickedUp.end(), make_pair(x, y)) != pickedUp.end();
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int doFill(int x, int y, int k, vector<pair<int, int>> pickedUp) {
    if (x < 0 || y < 0 || x >= H || y >= W || k == -1 || grid[x][y] == -1) {
        return -1;
    }
    State state = {x, y, k, pickedUp};
    if (alreadyVisited(state)) {
        return memo[state];
    }
    int ans = -INT_MAX;
    if (x == H - 1 && y == W - 1) {
        ans = 0;
    }
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        int nk = k - (d >= 2 ? 1 : 0);
        if (nx < 0 || ny < 0 || nx >= H || ny >= W || nk == -1 || grid[nx][ny] == -1) {
            continue;
        }
        vector<pair<int, int>> visited;
        for (int i = 0; i < pickedUp.size(); i++) {
            if (max(nx - pickedUp[i].first, 0) + max(ny - pickedUp[i].second, 0) <= nk) {
                visited.push_back(pickedUp[i]);
            }
        }
        int val = max(grid[nx][ny], 0);
        if (alreadyPickedUp(visited, nx, ny)) {
            val = 0;
        }
        if (grid[nx][ny] != -1) {
            visited.push_back(make_pair(nx, ny));
            sort(visited.begin(), visited.end());
            visited.erase(unique(visited.begin(), visited.end()), visited.end());
        }
        ans = max(ans, doFill(nx, ny, nk, visited) + val);
    }
    memo[state] = ans;
    return ans;
}

int main() {
    cin >> H >> W >> K;
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
    cout << doFill(0, 0, K, vector<pair<int, int>>()) << endl;
    return 0;
}

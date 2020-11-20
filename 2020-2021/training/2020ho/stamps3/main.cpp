// Test case path: [path]
// https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_c

#include <bits/stdc++.h>
#define int64 long long
#define INT64_INF LLONG_MAX / 3
using namespace std;

int N, L;

struct Station {
    int64 position;
    int64 closing;
};

vector<Station> stations;

int64 dp[202][202][2][202];
// # visited positive,
// # visited negative,
// current side,
// # of stamps acquired

template <class T>
T &assign_min(T &a, const T &b) { return a = min(a, b); }
template <class T>
T &assign_max(T &a, const T &b) { return a = max(a, b); }

int main() {
    cin >> N >> L;
    stations.resize(N + 2);
    for (int i = 0; i < N; i++) cin >> stations[i + 1].position;
    for (int i = 0; i < N; i++) cin >> stations[i + 1].closing;
    stations[N + 1].position = L;
    stations[N + 1].closing = -1;
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            for (int k = 0; k < 2; k++) {
                for (int m = 0; m <= N; m++) {
                    dp[i][j][k][m] = INT64_INF;
                }
            }
        }
    }
    dp[0][N + 1][0][0] = dp[0][N + 1][1][0] = 0;
    // 0 time needed for 0 stamps at origin
    for (int i = 0; i < N; i++) {
        for (int j = N + 1; j > i + 1; j--) {
            for (int m = 0; m <= N; m++) {
                int64 time = min(dp[i][j][0][m] + stations[i + 1].position - stations[i].position,
                                 dp[i][j][1][m] + L - stations[j].position + stations[i + 1].position);
                assign_min(dp[i + 1][j][0][m + (time <= stations[i + 1].closing)], time);
                time = min(dp[i][j][0][m] + L - stations[j - 1].position + stations[i].position,
                           dp[i][j][1][m] + stations[j].position - stations[j - 1].position);
                assign_min(dp[i][j - 1][1][m + (time <= stations[j - 1].closing)], time);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j <= N + 1; j++) {
            for (int k = 0; k < 2; k++) {
                for (int m = 0; m <= N; m++) {
                    if (dp[i][j][k][m] != INT64_INF) assign_max(ans, m);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
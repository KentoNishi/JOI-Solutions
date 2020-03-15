// Test case path: [path]
// https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_d

#include <bits/stdc++.h>
using namespace std;

const long long INF = INT_MAX;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> roads;
    roads.resize(N);
    vector<int> days;
    days.resize(M);
    for (int i = 0; i < N; i++) {
        cin >> roads[i];
    }
    for (int j = 0; j < M; j++) {
        cin >> days[j];
    }
    vector<vector<long long>> dp = vector<vector<long long>>(N + 1, vector<long long>(M + 1, INF));
    // dp[i][j] = minimum exhaustion at city i after j days
    for (int i = 0; i <= M; i++) {
        dp[0][i] = 0;
    }
    for (int city = 0; city < N; city++) {
        int &road = roads[city];
        for (int day = city; day < M; day++) {
            for (int i = 1; i + day <= M; i++) {
                /*
                cout << "Going from ";
                cout << city << " to " << city + 1;
                cout << " during day " << day + i - 1;
                cout << " - the weather is " << days[day + i - 1];
                cout << " and road is in condition " << road << ". ";
                cout << "Current exhaustion level: " << dp[city][day] << endl;
                */
                dp[city + 1][day + i] = min(dp[city + 1][day + i], dp[city][day] + road * days[day + i - 1]);
            }
        }
    }
    long long ans = INF;
    for (int i = 0; i <= M; i++) {
        ans = min(ans, dp[N][i]);
    }
    cout << ans << endl;
    /*
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}
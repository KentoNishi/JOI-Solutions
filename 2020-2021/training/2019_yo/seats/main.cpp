// Test case path: [path]
// https://atcoder.jp/contests/joi2019yo/tasks/joi2019_yo_f

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N;
int numFromCountry[100];
vector<vector<int>> dp[2];
// dp[a][b][c] = ways
// a = seat index
// b = country in seat
// c = counts for each country

int main() {
    cin >> N;
    if (N > 10) return 0;
    int numSeats = 0;
    for (int i = 0; i < N; i++) {
        cin >> numFromCountry[i];
        numSeats += numFromCountry[i];
    }
    auto init = vector<vector<int>>(N, vector<int>((1 << (2 * N)) + 1));
    dp[0] = init;
    dp[1] = init;
    for (int i = 0; i < N; i++) {
        dp[0][i][1 << (2 * i)] = numFromCountry[i];
    }
    for (int i = 0; i < numSeats - 1; i++) {
        dp[(i + 1) % 2] = init;
        for (int j = 0; j < N; j++) {
            for (int a = 1; a <= (1 << 2 * N); a++) {
                if (!dp[i % 2][j][a]) continue;
                for (int k = 0; k < N; k++) {
                    if (abs(j - k) <= 1) continue;
                    int numSeated = (a >> (2 * k)) & 3;
                    if (numSeated == numFromCountry[k]) continue;
                    int nextA = a;
                    nextA &= ~(3 << (2 * k));
                    nextA |= (numSeated + 1) << (2 * k);
                    dp[(i + 1) % 2][k][nextA] += dp[i % 2][j][a] * (numFromCountry[k] - numSeated);
                    dp[(i + 1) % 2][k][nextA] %= 10007;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int a = 1; a <= (1 << 2 * N); a++) {
            ans += dp[(numSeats - 1) % 2][i][a];
            ans %= 10007;
        }
    }
    cout << ans << endl;
    return 0;
}
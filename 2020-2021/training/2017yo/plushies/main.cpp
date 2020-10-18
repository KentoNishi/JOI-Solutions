// Test case path: [path]
// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N, M;
int numToLeft[20][100001];
int numPlushies[20];

map<int, int> dp[100001];
// dp[a][b] = c
// a: everything left of plushie a is placed
// b: bits holding which plushies have been placed
// c: minimum number of mismatches

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        for (int j = 0; j < M; j++) {
            numToLeft[j][i + 1] = numToLeft[j][i];
        }
        numToLeft[a][i + 1]++;
        numPlushies[a]++;
    }
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        // cout << i << endl;
        for (auto &p : dp[i]) {
            int usedToLeft = p.first;
            int mismatchToLeft = p.second;
            // cout << "\t" << bitset<20>(usedToLeft) << ": " << mismatchToLeft << endl;
            for (int j = 0; j < M; j++) {
                if (usedToLeft & (1 << j)) continue;
                int mismatch = mismatchToLeft + numPlushies[j] - (numToLeft[j][i + numPlushies[j]] - numToLeft[j][i]);
                int used = usedToLeft | (1 << j);
                auto &next = dp[i + numPlushies[j]];
                if (next.find(used) == next.end()) {
                    next[used] = mismatch;
                } else {
                    next[used] = min(next[used], mismatch);
                }
            }
        }
    }
    int ans = INFINITY;
    for (auto &p : dp[N]) {
        ans = min(ans, p.second);
    }
    cout << ans << endl;
    return 0;
}
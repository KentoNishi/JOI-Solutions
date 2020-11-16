// Test case path: [path]
// https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_b

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N;
int K;
string S;
vector<int> str;
vector<int> prefixSum[3];
vector<int> closestBound[3];

int main() {
    cin >> N >> K;
    cin >> S;
    str.resize(N);
    for (auto &v : prefixSum) v.resize(N + 1);
    for (auto &v : closestBound) v.resize(N);
    for (int i = 0; i < N; i++) {
        str[i] = S[i] == 'J' ? 0 : S[i] == 'O' ? 1 : 2;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            prefixSum[j][i + 1] = prefixSum[j][i];
        }
        prefixSum[str[i]][i + 1]++;
    }
    for (int j = 0; j < 3; j++) {
        for (int left = 0; left < N; left++) {
            auto &p = prefixSum[j];
            closestBound[j][left] =
                (int)(lower_bound(p.begin(), p.end(), p[left] + K) - p.begin()) - 1;
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        int left = i;
        for (int j = 0; j < 3; j++) {
            int right = closestBound[j][left];
            left = right + 1;
            if (left > N) {
                left = -1;
                break;
            }
        }
        int a = left - i - 3 * K;
        if (a >= 0) {
            ans = min(ans, a);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}
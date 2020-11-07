// Test case path: [path]
// https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_a

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N;
vector<pair<int, int>> available;
vector<int> current, fromLeft, fromRight;

int main() {
    cin >> N;
    available.resize(N + 1);
    current.resize(N);
    fromLeft.resize(N + 2);
    fromRight.resize(N + 2);
    for (int i = 0; i <= N; i++) {
        cin >> available[i].first;
        available[i].second = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> current[i];
    }
    sort(available.begin(), available.end());
    sort(current.begin(), current.end());
    for (int i = 0; i < N; i++) {
        fromLeft[i + 1] = max(fromLeft[i], max(available[i].first - current[i], 0));
    }
    for (int i = N; i > 0; i--) {
        fromRight[i] = max(fromRight[i + 1], max(available[i].first - current[i - 1], 0));
    }
    vector<int> ans;
    ans.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        int a = max(fromLeft[i], fromRight[i + 1]);
        ans[available[i].second] = a;
    }
    for (auto &i : ans) cout << i << " ";
    cout << endl;
    return 0;
}
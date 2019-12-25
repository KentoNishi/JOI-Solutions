// Test case path: [path]
// url

#include <bits/stdc++.h>
using namespace std;

vector<bool> seen;
vector<bool> dp;
int N;

bool possible(int i, int h) {
    //cout << i << " " << h << endl;
    if (i == N) {
        return true;
    }
    if (i > N) {
        return false;
    }
    if (seen[i]) {
        return dp[i];
    }
    seen[i] = true;
    int num = i;
    int sum = 0;
    while (num > 0) {
        int a = num % 10;
        num /= 10;
        sum += a;
    }
    dp[i] = possible(sum + i, i);
    return dp[i];
}

int main() {
    cin >> N;
    seen = vector<bool>(N);
    dp = vector<bool>(N);
    int ans = 1;
    for (int i = 1; i < N; i++) {
        if (!seen[i]) {
            if (possible(i, i)) {
                //cout << i << " works " << endl;
                ans++;
            }
        } else {
            if (dp[i]) {
                //cout << i << " works " << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
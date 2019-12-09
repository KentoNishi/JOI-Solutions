// Test case path: [path]
// url

#include <bits/stdc++.h>
using namespace std;

long long M, R;
vector<pair<long long, long long>> coords = {{0, 0}, {0, 1}, {1, 1}, {2, 1}, {0, 2}, {1, 2}, {2, 2}, {0, 3}, {1, 3}, {2, 3}};

long long tryIt(string num) {
    //cout << "Trying " << num << endl;
    long long prev = 0;
    long long sum = 0;
    for (auto &c : num) {
        long long a = c - '0';
        sum += abs(coords[prev].first - coords[a].first) + abs(coords[prev].second - coords[a].second) + 1;
        prev = a;
    }
    return sum;
}

int main() {
    cin >> M >> R;
    // a%M == R
    // a=M*i+R
    int top = tryIt(to_string(R));
    long long ans = top;
    for (long long a = 1; a * M + R <= R * M; a++) {
        ans = min(ans, tryIt(to_string(a * M + R)));
    }
    cout << ans << endl;
    return 0;
}
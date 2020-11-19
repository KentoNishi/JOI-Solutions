// Test case path: [path]
// https://atcoder.jp/contests/joi2020ho/tasks/joi2020ho_c

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N, L;

struct Station {
    int position;
    int closing;
};

struct State {
    int maxStamps = 0;
    int timeUsed = INT_MAX;
    bool operator<(const State &s) const {
        return maxStamps == s.maxStamps ? timeUsed < s.timeUsed : maxStamps < s.maxStamps;
    }
};

vector<Station> stations;
vector<map<pair<int, int>, State>> dp;
// markerPos, markerNeg, index

int main() {
    cin >> N >> L;
    stations.resize(N);
    for (auto &s : stations) cin >> s.position;
    for (auto &s : stations) cin >> s.closing;
    dp.resize(N);
    // basically longest path problem
    // but there are 2 extra dimensions of nodes
    // markerPos = index of the furthest node visited clockwise
    // markerNeg = index of the furthest node visited counterclockwise
    return 0;
}
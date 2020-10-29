// Test case path: [path]
// https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_e

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int64 N, M, K, S, P, Q;

struct City {
    int64 cost;
    int64 minCost = LLONG_MAX;
    int64 maxReach = -1;
    bool zombied;
    vector<int> edges;
};

vector<City> cities;

struct State1 {
    int node;
    bool operator<(const State1 &s) const {
        auto &c1 = cities[node];
        auto &c2 = cities[s.node];
        return c1.maxReach == c2.maxReach ? node < s.node : c1.maxReach < c2.maxReach;
    }
};

struct State2 {
    int node;
    bool operator<(const State2 &s) const {
        auto &c1 = cities[node];
        auto &c2 = cities[s.node];
        return c1.minCost == c2.minCost ? node < s.node : c1.minCost < c2.minCost;
    }
};

set<State1> q1;
set<State2> q2;

int main() {
    cin >> N >> M >> K >> S >> P >> Q;
    cities.resize(N);
    for (int i = 1; i < N - 1; i++) {
        cities[i].cost = P;
    }
    for (int i = 0; i < K; i++) {
        int a;
        cin >> a;
        a--;
        cities[a].maxReach = S;
        cities[a].zombied = true;
        q1.insert({a});
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cities[a].edges.push_back(b);
        cities[b].edges.push_back(a);
    }
    while (!q1.empty()) {
        auto &top = *q1.begin();
        q1.erase(q1.begin());
        auto &node = cities[top.node];
        node.cost = Q;
        int64 distLeft = node.maxReach - 1;
        if (distLeft < 0) continue;
        for (auto &e : node.edges) {
            if (cities[e].maxReach >= distLeft) continue;
            auto f = q1.find({.node = e});
            if (f != q1.end()) {
                q1.erase(f);
            }
            cities[e].maxReach = distLeft;
            q1.insert({.node = e});
        }
    }
    cities[0].minCost = 0;
    cities[0].cost = 0;
    q2.insert({.node = 0});
    while (!q2.empty()) {
        auto &top = *q2.begin();
        q2.erase(q2.begin());
        auto &node = cities[top.node];
        if (top.node == N - 1) {
            cout << node.minCost << endl;
            return 0;
        }
        int64 cost = node.cost + node.minCost;
        for (auto &e : node.edges) {
            if (cities[e].zombied || cost >= cities[e].minCost) continue;
            auto f = q2.find({.node = e});
            if (f != q2.end()) {
                q2.erase(f);
            }
            cities[e].minCost = cost;
            q2.insert({.node = e});
        }
    }
    return 0;
}
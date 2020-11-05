// Test case path: [path]
// https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_e

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N, K;

struct City {
    int minCost = INT_MAX;
    int price;
    int maxDist;
    int index;
    vector<City *> edges;
    bool operator<(City &c) const {
        return minCost == c.minCost ? index < c.index : minCost < c.minCost;
    }
};

struct State {
    City *city;
    bool operator<(const State &s) const {
        return *city < *s.city;
    }
};

struct State2 {
    int dist = 0;
    City *city;
};

int main() {
    cin >> N >> K;
    vector<City> cities;
    cities.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        cities[i].price = a;
        cities[i].maxDist = b;
        cities[i].index = i;
    }
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        auto &c1 = cities[a - 1];
        auto &c2 = cities[b - 1];
        c1.edges.push_back(&c2);
        c2.edges.push_back(&c1);
    }
    set<State> q;
    cities[0].minCost = 0;
    q.insert({.city = &cities[0]});
    while (!q.empty()) {
        auto top = *q.begin();
        q.erase(q.begin());
        // cout << "Can get to city " << top.city->index + 1 << " with cost=" << top.city->minCost << endl;
        if (top.city->index == N - 1) {
            cout << top.city->minCost << endl;
            return 0;
        }
        queue<State2> q2;
        q2.push({.dist = top.city->maxDist, .city = top.city});
        int cost = top.city->price + top.city->minCost;
        vector<bool> visited;
        visited.resize(N);
        while (!q2.empty()) {
            auto t2 = q2.front();
            q2.pop();
            if (!t2.dist--) continue;
            for (auto &e : t2.city->edges) {
                // cout << "\tTrying to go to city " << e->index + 1 << " with cost=" << cost << endl;
                if (cost < e->minCost) {
                    // cout << "\t\t"
                    //      << "Going to city " << e->index + 1 << endl;
                    e->minCost = cost;
                    State s = {.city = e};
                    auto f = q.find(s);
                    if (f != q.end()) q.erase(f);
                    q.insert(s);
                }
                if (!visited[e->index]) {
                    q2.push({.dist = t2.dist, .city = e});
                    visited[e->index] = true;
                }
            }
        }
    }
    return 0;
}
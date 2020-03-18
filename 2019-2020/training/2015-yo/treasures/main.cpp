// Test case path: [path]
// https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_f

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int annaValue;
    int brunoValue;
};

vector<Item> items;
int N;

int main() {
    cin >> N;
    items.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].annaValue >> items[i].brunoValue;
    }
    return 0;
}
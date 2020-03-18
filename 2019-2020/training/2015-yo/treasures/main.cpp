// Test case path: [path]
// https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_f

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int annaValue;
    int brunoValue;
};

vector<Item> items;
vector<vector<Item>> permutations;
int N;

void halfEnum(int side, int lower, int upper, int index, Item total) {
    if (index == upper) {
        permutations[side].push_back(total);
        return;
    }
    Item thisSide = total;
    thisSide.annaValue += items[index].annaValue;
    thisSide.brunoValue += items[index].brunoValue;
    Item otherSide = total;
    otherSide.annaValue -= items[index].annaValue;
    otherSide.brunoValue -= items[index].brunoValue;
    halfEnum(side, lower, upper, index + 1, total);
    halfEnum(side, lower, upper, index + 1, thisSide);
    halfEnum(side, lower, upper, index + 1, otherSide);
}

struct compare {
    bool operator()(Item &a, Item &b) const {
        return a.annaValue < b.annaValue;
    }
};

int main() {
    cin >> N;
    items.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i].annaValue >> items[i].brunoValue;
    }
    int leftSize = N / 2;
    int rightSize = N - leftSize;
    permutations.resize(2);
    halfEnum(0, 0, N / 2, 0, {0, 0});
    halfEnum(1, N / 2, N, 0, {0, 0});
    sort(permutations[0].begin(), permutations[0].end(), compare());
    sort(permutations[1].begin(), permutations[1].end(), compare());
    return 0;
}
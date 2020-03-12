// Test case path: [path]
// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d

#include <bits/stdc++.h>
using namespace std;

int D, N;

struct Shirt {
    int low;
    int high;
    int style;
};

vector<int> days;
vector<Shirt> shirts;

int main() {
    cin >> D >> N;
    days.resize(D);
    shirts.resize(N);
    for (int i = 0; i < D; i++) {
        cin >> days[i];
    }
    for (int i = 0; i < N; i++) {
        Shirt &shirt = shirts[i];
        cin >> shirt.low >> shirt.high >> shirt.style;
    }
    vector<vector<int>> maxWithShirt = vector<vector<int>>(D, vector<int>(N));
    for (int i = 1; i < D; i++) {
        for (int j = 0; j < N; j++) {
            Shirt &thisShirt = shirts[j];
            if (thisShirt.low <= days[i] && thisShirt.high >= days[i]) {
                for (int k = 0; k < N; k++) {
                    Shirt &prevShirt = shirts[k];
                    if (prevShirt.low <= days[i - 1] && prevShirt.high >= days[i - 1]) {
                        maxWithShirt[i][j] = max(maxWithShirt[i][j], maxWithShirt[i - 1][k] + abs(thisShirt.style - prevShirt.style));
                    }
                }
            }
        }
    }
    /*
    for (int i = 1; i < D; i++) {
        for (int j = 0; j < N; j++) {
            cout << maxWithShirt[i][j] << " ";
        }
        cout << endl;
    }
    */
    int ans = 0;
    for (int j = 0; j < N; j++) {
        ans = max(ans, maxWithShirt[D - 1][j]);
    }
    cout << ans << endl;
    return 0;
}
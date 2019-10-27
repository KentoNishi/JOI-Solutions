// url

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int count = 0;
        for (int k = 0; k < N; k++) {
            if (A[k] == i + 1) {
                count++;
            }
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
    return 0;
}

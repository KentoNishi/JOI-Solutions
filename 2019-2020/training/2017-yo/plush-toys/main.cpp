// Test case path: [none]
// https://www.ioi-jp.org/joi/2016/2017-yo/index.html
// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d

#include <bits/stdc++.h>
using namespace std;


int main() {
    int N,M;
    cin >> N >> M;
    vector<int> nums=vector<int>(N);
    for(int i=0;i<N;i++){
        cin>>nums[i];
        nums[i]--;
    }
    return 0;
}
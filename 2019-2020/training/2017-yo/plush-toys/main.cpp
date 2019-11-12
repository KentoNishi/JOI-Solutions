// Test case path: [none]
// https://www.ioi-jp.org/joi/2016/2017-yo/index.html
// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d

#include <bits/stdc++.h>
using namespace std;


int main() {
    int N,M;
    cin >> N >> M;
    vector<int> nums=vector<int>(N);
    vector<pair<int,int>> counts=vector<pair<int,int>>(M);
    // occurences, id
    for(int i=0;i<N;i++){
        cin>>nums[i];
        nums[i]--;
        counts[nums[i]].first++;
        counts[nums[i]].second=nums[i];
    }
    sort(counts.begin(),counts.end());
    for(int i=0;i<M;i++){
        cout << counts[i].first << " " << counts[i].second+1 << endl;
    }
    return 0;
}
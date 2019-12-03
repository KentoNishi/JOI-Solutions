// Test case path: [none]
// https://www.ioi-jp.org/joi/2016/2017-yo/index.html
// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> nums=vector<int>(N);
    vector<vector<int>> toLeft=vector<vector<int>>(M,vector<int>(N+1));
    vector<int> quantities=vector<int>(M,0);
    vector<int> arrangement=vector<int>(M,INFINITY);
    for(int i=0;i<N;i++){
        cin>>nums[i];
        nums[i]--;
        quantities[nums[i]]++;
        toLeft[nums[i]][i+1]++;
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            toLeft[i][j+1]=toLeft[i][j];
        }
    }
    return 0;
}
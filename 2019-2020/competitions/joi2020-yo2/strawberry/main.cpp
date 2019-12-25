// Test case path: [path]
// url

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int,int>> plants=vector<pair<int,int>>(N);
    for(int i=0;i<N;i++){
        cin >> plants[i].first >> plants[i].second;
    }
    sort(plants.begin(),plants.end());/*
    for(auto &plant:plants){
        cout << plant.first << " " << plant.second << endl;
    }*/
    int time=max(plants[N-1].first,plants[N-1].second);
    for(int i=N-2;i>=0;i--){
        time+=plants[i+1].first-plants[i].first;
        if(plants[i].second>time){
            time=plants[i].second;
        }
    }
    cout << time+plants[0].first << endl;
    return 0;
}
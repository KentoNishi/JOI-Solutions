// Test case path: [C:\Users\kento\OneDrive\Files\Documents\GitHub\JOI-Solutions\2019-2020\training\2018-yo\2018-yo\2018-yo-t2]
// https://www.ioi-jp.org/joi/2017/2018-yo/2018-yo-t2.html

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> board=vector<int>(N+2,0);
    for(int i=0;i<N;i++){
        cin>>board[i+1];
    }
    int ans=0;
    int left=0;
    for(int i=0;i<N+2;i++){
        if(board[i]!=1){
            ans=max(ans,i-left-1);
            left=i;
        }
    }
    cout << ans+1 << endl;
    return 0;
}
// url

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
    int N, M;
    cin >> N;
    vector<bool> board=vector<bool>(2019);
    vector<int> positions=vector<int>(N);
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        a--;
        board[a]=true;
        positions[i]=a;
    }
    cin >> M;
    for(int i=0;i<M;i++){
        int a;
        cin >> a;
        a--;
        if(positions[a]<2018 && !board[positions[a]+1]){
            board[positions[a]+1]=true;
            board[positions[a]]=false;
            positions[a]++;
        }
    }
    int ans=0;
    for(int i=0;i<2019;i++){
        if(board[i]){
            cout << i+1 << endl;
        }
    }
    return 0;
}
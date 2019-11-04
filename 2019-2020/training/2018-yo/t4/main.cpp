// Test case path: [C:\Users\kento\OneDrive\Files\Documents\GitHub\JOI-Solutions\2019-2020\training\2018-yo\2018-yo\2018-yo-t4]

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int N;
vector<int> lengths;
int solve(int smallPiece){
    vector<int> shortestMaxLengths=vector<int>(N+1);
    // [i] is the shortest maximum length if lengths was
    // cut from position 0 to i
    shortestMaxLengths[0]=smallPiece;
    // if nothing is cut, then the shortest long piece is the short piece
    for(int pos=0;pos<N;pos++){
        // for each position in lengths
        int pieceLength=0;
        for(int bound=pos;bound>=0 && !(pos==N-1 && bound==0);bound--){
            // for each element to the left of pos
            pieceLength+=lengths[bound];
            // adjust the piece length
            
        }
    }
}


int main() {
    cin >> N;
    lengths=vector<int>(N);
    for(int i=0;i<N;i++){
        cin >> lengths[i];
    }
    int ans=INFINITY;
    for(int leftBound=0;leftBound<N;leftBound++){
        int pieceLength=0;
        for(int rightBound=leftBound;rightBound<N;rightBound++){
            pieceLength+=lengths[rightBound];
            ans=min(ans,solve(pieceLength,lengths));
        }
    }
    cout << ans << endl;
    return 0;
}
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
    int N, a, b;
    cin >> N >> a >> b;
    a--;
    b--;
    string S;
    string output="";
    cin >> S;
    for(int i=0;i<a;i++){
        output+=S[i];
    }
    for(int i=b;i>=a;i--){
        output+=S[i];
    }
    for(int i=b+1;i<S.size();i++){
        output+=S[i];
    }
    cout << output << endl;
}
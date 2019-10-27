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
    int a, b, c;
    cin >> a >> b >> c;
    int minimum = min(min(a, b), c);
    cout << a + b + c - minimum << endl;
    return 0;
}
// Test case path: [path]
// https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_e

#include <bits/stdc++.h>
#define int64 long long
using namespace std;

int N;

struct Node {
    char op = ' ';
    char hand = ' ';
    Node* parent;
    vector<Node*> children;
    Node(Node* p) {
        parent = p;
    }
};

inline bool isOp(char c) {
    return c == '*' || c == '+' || c == '-';
}

inline bool isHand(char c) {
    return c == 'R' || c == 'P' || c == 'S' || c == '?';
}

int main() {
    cin >> N;
    Node* top = new Node(NULL);
    top->children.push_back(new Node(top));
    top = top->children.back();
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == '(') {
            Node node(top);
            top->children.push_back(&node);
            top = &node;
        } else if (c == ')') {
            top = top->parent;
        } else if (isOp(c)) {
            if (c != '*') {
                top = top->parent;
            }
            Node node(top);
            node.op = c;
            top->children.push_back(&node);
            top = &node;
            Node child(&node);
            top->children.push_back(&child);
            top = &child;
        } else if (isHand(c)) {
            top->hand = c;
        }
    }
    return 0;
}
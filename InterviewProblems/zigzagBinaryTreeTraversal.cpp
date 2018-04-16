#include <bits/stdc++.h>

using namespace std;

typedef int T;

struct Node {
    T val;
    Node *left, *right;
};

vector<vector<T>> spiralTraversal(Node * node) {
    vector<vector<T>> spiralOrder;
    if (!node)
        return spiralOrder;
    stack<Node*> s1, s2;
    s1.push(node);
    bool passS1 = false, passS2 = false;
    while (!s1.empty() || !s2.empty()) {
        vector<T> row1, row2;
        while (!s1.empty()) {
            Node * node = s1.top(); s1.pop();
            if (node->left)
                s2.push(node->left);
            if (node->right)
                s2.push(node->right);
            row1.push_back(node->val);
            passS1 = true;
        }
        if (passS1)
            spiralOrder.push_back(row1);
        passS1 = false;
        while (!s2.empty()) {
            Node * node = s2.top(); s2.pop();
            if (node->right)
                s1.push(node->right);
            if (node->left)
                s1.push(node->left);
            row2.push_back(node->val);
            passS2 = true;
        }
        if (passS2)
            spiralOrder.push_back(row2);
        passS2 = false;
    }
    return spiralOrder;
}

void addAttributes(Node * node, T val, Node * leftChild, Node * rightChild, Node * right) {
    node->val = val;
    node->left = leftChild;
    node->right = rightChild;
}

int main() {
    Node * root = new Node();
    Node * left = new Node();
    Node * right = new Node();
    Node * leftleft = new Node();
    Node * leftright = new Node();
    Node * rightleft = new Node();
    Node * rightright = new Node();
    addAttributes(root, 3, left, right, NULL);
    addAttributes(left, 9, NULL, NULL, NULL);
    addAttributes(right, 20, rightleft, rightright, NULL);
    addAttributes(leftleft, 4, NULL, NULL, NULL);
    // addAttributes(leftright, 3, NULL, NULL, NULL);
    addAttributes(rightleft, 15, NULL, NULL, NULL);
    addAttributes(rightright, 7, NULL, NULL, NULL);
    vector<vector<T>> ans = spiralTraversal(root);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
/*
    Given a Binary Tree (not necessarily complete) connect each node to its right node,
    and if it doesn't have a right node, then connect it to the first node
    of the next row.
*/

#include<bits/stdc++.h>

using namespace std;
typedef int T;
struct Node {
    T val;
    Node * rightChild, *leftChild, *right;
};

void connectTree(Node * root) {
    if (!root)
        return;
    queue<Node*> q;
    q.push(root);
    Node * prevNode = NULL;
    while(!q.empty()) {
        Node * curNode = q.front(); q.pop();
        if (prevNode)
            prevNode->right = curNode;
        prevNode = curNode;
        if (curNode->leftChild)
            q.push(curNode->leftChild);
        if (curNode->rightChild)
            q.push(curNode->rightChild);
    }
}

void addAttributes(Node * node, T val, Node * leftChild, Node * rightChild, Node * right) {
    node->val = val;
    node->leftChild = leftChild;
    node->rightChild = rightChild;
    node->right = right;
}

int main() {
    Node * root = new Node();
    Node * left = new Node();
    Node * right = new Node();
    Node * leftleft = new Node();
    Node * leftright = new Node();
    Node * rightleft = new Node();
    Node * rightright = new Node();
    addAttributes(root, 5, left, right, NULL);
    addAttributes(left, 2, leftleft, NULL, NULL);
    addAttributes(right, 1, rightleft, rightright, NULL);
    addAttributes(leftleft, 4, NULL, NULL, NULL);
    // addAttributes(leftright, 3, NULL, NULL, NULL);
    addAttributes(rightleft, 6, NULL, NULL, NULL);
    addAttributes(rightright, 7, NULL, NULL, NULL);
    connectTree(root);
    Node * node = root;
    while (node) {
        cout << node->val << endl;
        node = node->right;
    }
    return 0;
}
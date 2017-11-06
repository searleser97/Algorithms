/*
    Given a complete binary tree connect each node to its right node,
    and if it doesn't have a right node, then connect it to the first node
    of the next row.
*/

#include <bits/stdc++.h>

using namespace std;

typedef int Elem;

class Node {
public:
    Elem value;
    Node *left, *right, *next;
    Node(Elem value, Node * left, Node * right, Node * next) {
        this->value = value;
        this->left = left;
        this->right = right;
        this->next = next;
    }
};

Node * connect(Node* root) {
    if (!root || !root->left)
        return root;
    Node* aux = root;
    while (aux->left) {
        Node *nextLeftMostNode = aux->left;
        while (true) {
            aux->left->next = aux->right;
            if (aux->next) {
                aux->right->next = aux->next->left;
                aux = aux->next;
            } else {
                aux->next = nextLeftMostNode;
                break;
            }
        }
        aux = nextLeftMostNode;
    }
    return root;
}

void printTreeByNext(Node * root) {
    while (root) {
        cout << root->value << endl;
        root = root->next;
    }
}

int main() {
    Node * root = new Node(1, new Node(2, new Node(4, nullptr, nullptr, nullptr), new Node(5, nullptr, nullptr, nullptr), nullptr), new Node(3, new Node(6, nullptr, nullptr, nullptr), new Node(7, nullptr, nullptr, nullptr), nullptr), nullptr);
    printTreeByNext(connect(root));
    return 0;
}

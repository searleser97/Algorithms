#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node * next;
	Node(int v = 0, Node * n = NULL) : val(v), next(n) {}	
};

Node * _reverse(Node * previous, Node * current) {
	Node * head = NULL;
	if (current->next)
		head = _reverse(current, current->next);
	else
		head = current;
	current->next = previous;
	return head;
}

Node * reverse(Node * l) {
	if (!l) return NULL;
	return _reverse(NULL, l);
}


void printList(Node * l) {
	Node * aux = l;
	while (aux) {
		cout << aux->val << " ";
		aux = aux->next;
	}
	cout << endl;
}

int main() {
	Node * l1 = new Node(4, new Node(5, new Node(6)));
	printList(reverse(l1));
	return 0;
}
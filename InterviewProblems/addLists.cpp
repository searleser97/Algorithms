#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node * next;
	Node(int v = 0, Node * n = NULL) : val(v), next(n) {}	
};


Node * _add(Node * l1, Node * l2) {
	if (!l1) return l2;
	if (!l2) return l1;
	if (!l1 && !l2) return NULL;
	if (l1->next) {
		Node * ans = new Node();
		ans->next = _add(l1->next, l2->next);
		int carry = 0;
		if (ans->next->val > 9) {
			ans->next->val = ans->next->val - 10;
			carry = 1;
		}
		ans->val = carry + l1->val + l2->val;
		return ans;
	} else {
		return new Node(l1->val + l2->val);
	}
}

Node * add(Node * l1, Node * l2) {
	Node * head = _add(l1, l2);
	if (head->val > 9) {
		head->val = head->val - 10;
		Node * newHead = new Node(1);
		newHead->next = head;
		return newHead;
	} else {
		return head;
	}
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

	Node * l1 = new Node(5, new Node(5, new Node(6)));
	Node * l2 = new Node(5, new Node(5, new Node(6)));
	Node * ans = add(l1, l2);
	printList(ans);
	return 0;
}
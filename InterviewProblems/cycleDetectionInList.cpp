#include <bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node * next;
	Node(int v = 0, Node * n = NULL) : val(v), next(n) {}	
};

bool _detectCycle(Node * turtle, Node * hare) {
	if (!hare || !hare->next) return false;
	if (hare == turtle) return true;
	return _detectCycle(turtle->next, hare->next->next);
}

bool detectCycle(Node * l) {
	if (!l || !l->next) return false;
	return _detectCycle(l, l->next->next);
}

int main() {

	Node * _0 = new Node(0);
	Node * _1 = new Node(1);
	Node * _2 = new Node(2);
	Node * _3 = new Node(3);
	Node * _4 = new Node(4);
	Node * _5 = new Node(5);
	Node * _6 = new Node(6);

	_0->next = _1;
	_1->next = _2;
	_2->next = _3;
	_3->next = _4;
	_4->next = _5;
	_5->next = _6;
	_6->next = _4; // cycle here

	cout << detectCycle(_0) << endl;
	return 0;
}
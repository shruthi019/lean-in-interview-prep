#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};

class stack{
public:
	node* head;
	stack() {
		head = NULL;
	}

	bool is_empty() {
		return head == NULL;
	}

	void push(int x) {
		node* temp = new node(x);
		temp->next = head;
		head = temp;
		return;
	}

	int pop() {
		if (is_empty()) {
			return -1;
		}

		int top = head->data;
		node* temp = head;
		head = temp->next;
		delete temp;
		return top;
	}

	int top() {
		if (is_empty()) {
			return -1;
		}
		return head->data;
	}
};

int main() {
	stack s;
	for (int i = 0; i < 10; i++) {
		s.push(i);
	}

	while (!s.is_empty()) {
		cout << s.pop() << " ";
	}

	s.push(100);
	cout << s.top() << endl;
	return 0;
}
#include <iostream>
using namespace std;
#define n 10

class stack{
	int top = -1;
	int st[n];
public:
	stack() {

	}

	bool is_empty() {
		return top == -1;
	}

	bool is_full() {
		return top == n - 1;
	}

	void push(int x) {
		if (is_full()) {
			return;
		}
		top++;
		st[top] = x;
		return;
	}

	int pop() {
		if (is_empty()) {
			return -1;
		}
		top--;
		return st[top + 1];
	}

	int getTop() {
		if (is_empty()) {
			return -1;
		}
		return st[top];
	}
};


int main() {
	stack s;
	for (int i = 0; i < n; i++) {
		s.push(i);
	}

	while (!s.is_empty()) {
		cout << s.pop() << " ";
	}

	s.push(100);
	cout << s.getTop() << endl;
	return 0;
}
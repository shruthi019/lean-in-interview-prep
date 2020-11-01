#include <iostream>
using namespace std;

// Problem: https://leetcode.com/problems/odd-even-linked-list/ (MEDIUM level)

class node {
public:
    int data;
    node* next;

    node(int d) {
        data = d;
        next = nullptr;
    }
};  

node* insertAtHead(int data, node* &head) {
    if (head == nullptr) {
        return head = new node(data);
    }
    node* new_head = new node(data);
    new_head->next = head;
    head = new_head;
    return head;
}

void print(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

node* separate_odd_even(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* odd = head;
    node* even = head->next;
    node* even_start = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_start;
    return head;
}

int main() {
    node* head = NULL;
    for (int i = 0; i < 5; i++) {
        insertAtHead(i, head);
    }
    cout << "Original LL: ";
    print(head);

    node* ans = separate_odd_even(head);
    cout << "Odd indices before even: ";
    print(ans);
    return 0;
}
#include <iostream>
using namespace std;

// Problem: https://leetcode.com/problems/reverse-linked-list/ (EASY level)

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

node* reverse(node* &head) {
    node* prev = nullptr;
    node* next = nullptr;
    node* current = head;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {
    node* head = nullptr;
    for (int i = 0; i < 10; i++) {
        insertAtHead(i, head);
    }
    cout << "Original Linked List: ";
    print(head);

    reverse(head);
    cout << "Reversed Linked List: ";
    print(head);

    return 0;
}
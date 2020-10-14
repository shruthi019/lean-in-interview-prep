#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

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

int get_nth_node(node* head, int n) {
    node* ref = head;
    node* temp = head;
    int count = 0;

    while (count < n) {
        temp = temp->next;
        count++;
    }

    while (temp != nullptr) {
        temp = temp->next;
        ref = ref->next;
    }

    return ref->data;
}

int main() {
    node* head = nullptr;
    for (int i = 0; i < 10; i++) {
        insertAtHead(i, head);
    }
    int n = 5;

    cout << "Linked List: ";
    print(head);

    cout << "Value of nth node from end of linked list, where n = " << n << " is " << get_nth_node(head, n) << endl;
    return 0;
}
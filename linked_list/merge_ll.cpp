#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/merge-a-linked-list-into-another-linked-list-at-alternate-positions/

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

node* merge(node* &head1, node* &head2) {
    node* temp1 = head1;
    node* temp2 = head2;
    node* next1 = nullptr;
    node* next2 = nullptr;

    while (temp1 != nullptr && temp2 != nullptr) {
        next1 = temp1->next;
        temp1->next = temp2;
        next2 = temp2->next;
        temp2->next = next1;
        temp1 = next1;
        temp2 = next2;
    }

    return head1;
}

int main() {
    node* head1 = nullptr;
    for (int i = 0; i < 3; i++) {
        insertAtHead(i, head1);
    }

    cout << "First Linked List: ";
    print(head1);
    
    node* head2 = nullptr;
    for (int i = 10; i < 15; i++) {
        insertAtHead(i, head2);
    }

    cout << "Second Linked List: ";
    print(head2);

    head1 = merge(head1, head2);

    cout << "Merged Linked List: ";
    print(head1);
    return 0;
}
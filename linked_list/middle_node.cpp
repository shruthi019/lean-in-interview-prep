#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/ 

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

int get_middle(node* head) {
    if (head == nullptr) {
        cout << "Linked List is empty!" << endl;
        exit(1);
    }

    node* slow = head;
    node* fast = head;

    while (slow && fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}

int main() {
    node* head = nullptr;
    for (int i = 0; i < 6; i++) {
        insertAtHead(i, head);
    }

    cout << "Linked List: ";
    print(head);
    cout << "Value at middle node of Linked List is " << get_middle(head) << endl;
    
    return 0;
}
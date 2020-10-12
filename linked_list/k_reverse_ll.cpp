#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/

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

node* k_reverse(node* head, int k) {
    node* prev = nullptr;
    node* next = nullptr;
    node* current = head;
    
    int count = 0;
    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != nullptr) {
        head->next = k_reverse(next, k);
    }

    return prev;
}

int main() {
    node* head = nullptr;
    for (int i = 0; i < 10; i++) {
        insertAtHead(i, head);
    }
    cout << "Original Linked List: ";
    print(head);

    int k = 3;
    head = k_reverse(head, k);
    cout << "Reversed Linked List: ";
    print(head);

    return 0;
}
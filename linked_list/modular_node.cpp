#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/find-modular-node-linked-list/ 

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

node* modular_node(node* &head, int k) {
    if (k <= 0 || head == nullptr) {
        return nullptr;
    }

    int i = 1;
    node* temp = head;
    node* ans = nullptr;
    while (temp != nullptr) {
        if (i % k == 0) {
            ans = temp;
        }
        i++;
        temp = temp->next;
    }
    return ans;
}

int main() {
    node* head = nullptr;
    for (int i = 5; i > 0; i--) {
        insertAtHead(i, head);
    }
    cout << "Linked List: ";
    print(head);

    int k = 2;
    cout << "k = " << k << endl;

    node* ans = modular_node(head, k);
    if (ans) {
        cout << "Modular node = " << ans->data << endl;
    } else {
        cout << "No modular node exists" << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

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

bool cycle_exists(node* &head) {
    // Floyd's cycle finding algorithm
    node* slow = head;
    node* fast = head;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    node* head = nullptr;
    for (int i = 0; i < 10; i++) {
        insertAtHead(i, head);
    }
    
    // Creating a cycle for testing
    head->next->next->next = head;

    cout << cycle_exists(head) << endl;

    return 0;
}
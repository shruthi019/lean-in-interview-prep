#include <iostream>
using namespace std;

// 1 2 2 3 3 3 4 4 4 4 

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
// 1 1

node* remove_duplicates(node* &head) {
    node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        node* next_node = temp->next;
        if (temp->data == next_node->data) {
            temp->next = next_node->next;
            delete next_node;
        } else {
            temp = temp->next; 
        }
    }
    return head;
}

int main() {
    node* head = nullptr;
    insertAtHead(10, head);
    insertAtHead(10, head);
    insertAtHead(10, head);
    insertAtHead(10, head);
    insertAtHead(7, head);
    insertAtHead(6, head);
    insertAtHead(6, head);
    insertAtHead(6, head);
    insertAtHead(3, head);
    insertAtHead(3, head);
    insertAtHead(2, head);
    insertAtHead(1, head);
    insertAtHead(1, head);

    cout << "Original Linked List: ";
    print(head);

    cout << "After removing duplicates: ";
    remove_duplicates(head);
    print(head);
    return 0;
}
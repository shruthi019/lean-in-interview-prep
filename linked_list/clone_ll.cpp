#include <iostream>
using namespace std;

// Problem: https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/ 

class node {
public:
    int data;
    node* next;
    node* random;

    node(int d) {
        data = d;
        next = nullptr;
        random = nullptr;
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

node* insertAtTail(int data, node* &head) {
    if (head == nullptr) {
        return head = new node(data);
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new node(data);
    return head;
}

void print(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << "Node value: " << temp->data << ", Random address: " << temp->random << ", Random value: " << temp->random->data << endl;
        temp = temp->next;
    }
    cout << endl;
    return;
}

node* clone(node* head) {
    node* head2 = nullptr;
    node* temp = head;
    while (temp != nullptr) {
        insertAtTail(temp->data, head2);
        temp = temp->next;
    }
    temp = head;
    node* temp2 = head2;
    while (temp != nullptr) {
        node* next_of_temp = temp->next;
        temp->next = temp2;
        temp2->random = temp;
        temp2 = temp2->next;
        temp = next_of_temp;
    }
    temp2 = head2;
    while (temp2 != nullptr) {
        temp2->random = temp2->random->random->next;
        temp2 = temp2->next;
    }

    return head2;
}

int main() {
    node* head = nullptr;
    for (int i = 0; i < 5; i++) {
        insertAtHead(i, head);
    }
    //setting the random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    cout << "Original Linked List: " << endl;
    print(head);
    node* head2 = clone(head);
    cout << "Cloned Linked List: " << endl;
    print(head2);
    return 0;
}
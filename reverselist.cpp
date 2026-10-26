#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverselist(Node* head) {
    Node*prev = nullptr;
    Node*current = head;
    while (current != nullptr) {
        Node* nextcurrent = current->next;
        current->next = prev;
        prev = current;
        current = nextcurrent;
    }
    return prev;
}
void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}    
int main() {
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};

    cout << "Original list: ";
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;

    head = reverselist(head);

    cout << "Reversed list: ";
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;

    deleteList(head);
    return 0;
}
#include <iostream>

struct Node {
    int number;
    Node* next;
};

// Insert at head
void insertAtHead(Node** head, int value) {
    Node* newNode = new Node;
    newNode->number = value;
    newNode->next = *head;
    *head = newNode;
}

// Print list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->number << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Start with an empty list
    Node* head = nullptr;

    // Add some numbers
    insertAtHead(&head, 3);  // List: 3
    insertAtHead(&head, 7);  // List: 7 -> 3
    insertAtHead(&head, 11); // List: 11 -> 7 -> 3
    
    // Print the list
    printList(head);

    return 0;
}
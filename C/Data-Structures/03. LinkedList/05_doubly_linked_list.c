#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct node {
    struct node *prev; // Pointer to the previous node
    int data; // Data stored in the node
    struct node *next; // Pointer to the next node
};

typedef struct node Node; // Typedef for simplicity

// Function declarations
Node *createNode(int data); // Creates a new node
void printLinkedList(Node *head); // Prints the linked list
void insertAtBegining(Node **head, int data); // Inserts a node at the beginning
void insertAtEnd(Node **head, int data); // Inserts a node at the end
void removeNode(Node **head, int data); // Removes a node by value
void reverseList(Node **head); // Reverses the linked list

// Main function
int main() {
    Node *head = NULL; // Initializing an empty linked list

    // Inserting nodes at the beginning and end of the list
    insertAtBegining(&head, 10);
    insertAtBegining(&head, 5);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);



    // Printing the original list
    printf("Linked List: ");
    printLinkedList(head);

    // Removing a node and printing the updated list
    int removeValue = 5;
    removeNode(&head, removeValue);
    printf("List after removing %d: ", removeValue);
    printLinkedList(head);

    // Reversing the list
    reverseList(&head);

    // Displaying the reversed list
    printf("Reversed List: ");
    printLinkedList(head);

    return 0;
}

// Function to reverse the doubly linked list
void reverseList(Node **head) {
    Node *temp = NULL, *current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to remove a node by value
void removeNode(Node **head, int data) {
    if (*head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    Node *temp = *head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found!\n");
        return;
    }

    if (temp->prev == NULL) {
        *head = temp->next;
    } else {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to insert a node at the beginning of the list
void insertAtBegining(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = createNode(data);
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to create a new node
Node *createNode(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the linked list
void printLinkedList(Node *head) {
    Node *current = head;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

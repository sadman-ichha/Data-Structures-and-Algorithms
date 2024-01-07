#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node Node;

Node *createNode(int data, Node *next, Node *prev);
void printLinkedList(Node *head);

int main() {
    // Creating nodes and linking them to form a linked list
    Node *head = createNode(10, NULL, NULL);
    head->next = createNode(20, NULL, head);
    head->next->next = createNode(30, NULL, head->next);

    // Printing the linked list
    printf("Linked List: ");
    printLinkedList(head);

    return 0;
}

Node *createNode(int data, Node *next, Node *prev) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error! Could Not Allocate The memory\n");
        exit(1);
    }

    new_node->data = data;
    new_node->prev = prev;
    new_node->next = next;
    return new_node;
}

void printLinkedList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

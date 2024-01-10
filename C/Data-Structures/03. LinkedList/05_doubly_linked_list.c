#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct node
{
    struct node *prev; // Pointer to the previous node
    int data;          // Data stored in the node
    struct node *next; // Pointer to the next node
};

typedef struct node Node; // Typedef for simplicity

// Function declarations
Node *createNode(int data);                   // Creates a new node
void printLinkedList(Node *head);             // Prints the linked list
void insertAtBegining(Node **head, int data); // Inserts a node at the beginning
void insertAtEnd(Node **head, int data);      // Inserts a node at the end
void removeNode(Node **head, int data);       // Removes a node by value
void reverseList(Node **head);                // Reverses the linked list

int main()
{
    int input_value;
    Node *head = NULL;

    do
    {
        printf("\n----Menu----\n");
        printf("\n1. Insert At Begining Linked List");
        printf("\n2. Insert At Ending Linked List");
        printf("\n3. Remove a Node Linked List");
        printf("\n4. Reverse a Linked List");
        printf("\n5. Display List");
        printf("\n6. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &input_value);
        printf("\n");

        switch (input_value)
        {
        case 1:
            printf("Enter value to insert at beginning: ");
            int value;
            scanf("%d", &value);
            insertAtBegining(&head, value);
            break;
        case 2:
            printf("Enter value to insert at Ending: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;
        case 3:
            printf("Enter value to Removing a node: ");
            scanf("%d", &value);
            removeNode(&head, value);
            printLinkedList(head);
            break;
        case 4:
            printf("Reverse the linked list: ");
            reverseList(&head);
            printLinkedList(head);
            break;
        case 5:
            printf("Linked List: ");
            printLinkedList(head);
            break;
        case 6:
            printf("Have a nice day!!!\n");
            exit(0);
            break;
        default:
            printf("\n----INVALID CHOICE!----\n");
            break;
        }

    } while (input_value);

    return 0;
}
// Function to reverse the doubly linked list
void reverseList(Node **head)
{
    // Declarations of pointers 'temp' and 'current'
    Node *temp = NULL, *current = *head;

    // Check if the linked list is empty
    if (current == NULL)
    {
        printf("Linked List is empty!\n");
        return;
    }

    // Reversing the linked list
    while (current != NULL)
    {
        temp = current->prev;          // Store the previous node
        current->prev = current->next; // Reversing pointers
        current->next = temp;          // Assign next to previous
        current = current->prev;       // Move to the next node
    }

    // Adjusting the head if needed
    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

// Function to remove a node by value
void removeNode(Node **head, int data)
{
    // Check if the linked list is empty
    if (*head == NULL)
    {
        printf("Linked List is empty!\n");
        return;
    }

    // Pointer to traverse the list
    Node *temp = *head;

    // Traversing the list to find the node with given data
    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }

    // Node not found
    if (temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    // Adjusting pointers to remove the node
    if (temp->prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    // Freeing memory for the removed node
    free(temp);
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data)
{
    // Creating a new node
    Node *newNode = createNode(data);

    // If the list is empty, the new node becomes the head
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else
    {
        // Traverse the list to find the last node
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to insert a node at the beginning of the list
void insertAtBegining(Node **head, int data)
{
    // Creating a new node
    Node *newNode = createNode(data);

    // If the list is empty, the new node becomes the head
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else
    {
        // Inserting at the beginning
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to create a new node
Node *createNode(int data)
{
    // Allocating memory for the new node
    Node *new_node = (Node *)malloc(sizeof(Node));

    // Check for memory allocation failure
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initializing the new node
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    // Starting from the head of the list
    Node *current = head;

    // Check if the list is empty
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    // Traversing and printing the list
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

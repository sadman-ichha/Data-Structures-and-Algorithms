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
            break;
        case 4:
            printf("Reverse the linked list: ");
            reverseList(&head);
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

    Node *temp = NULL, *current = *head;
    if (current == NULL)
    {
        printf("Linked List is empty!\n");
        return;
    }
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

// Function to remove a node by value
void removeNode(Node **head, int data)
{
    if (*head == NULL)
    {
        printf("Linked List is empty!\n");
        return;
    }

    Node *temp = *head;
    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Node not found!\n");
        return;
    }

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
    free(temp);
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to insert a node at the beginning of the list
void insertAtBegining(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = createNode(data);
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to create a new node
Node *createNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *current = head;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

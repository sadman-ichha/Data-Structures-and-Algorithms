#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;

// Function declarations/Prototypes
Node *createLinkedList(int arr[], int length);
void print_list(Node *head);
int searchingNode(Node *head, int value);
void reverse_linked_list(Node **head);
void insertAtBeginning(Node **head, int data);
void insertAtEnd(Node *head, int data);
Node *removeNode(Node *head, int data);

int main()
{
    int arr[] = {5, 10, 15, 20, 25};
    int length = sizeof(arr) / sizeof(arr[0]);

    Node *head = NULL; // Initialize the head pointer to NULL

    // Creating a linked list from the array
    head = createLinkedList(arr, length);
    Node *newHead = head; // Creating a new pointer to the head

    // Printing the array list using the created linked list
    printf("Linked List: ");
    print_list(head);

    // Searching for a node with value 15 and printing its index
    printf("Search Node Index: ");
    int result = searchingNode(head, 15);
    printf("%d \n", result);

    // Inserting a node with value 80 at the beginning
    insertAtBeginning(&newHead, 80);
    printf("List after inserting 80 at the beginning: ");
    print_list(newHead);

    // Reversing the linked list and printing it
    reverse_linked_list(&newHead);
    printf("Reverse Linked List: ");
    print_list(newHead);

    // Removing a node with specific value
    int dataToRemove = 155;
    newHead = removeNode(newHead, dataToRemove);
    printf("List after removing %d: ", dataToRemove);
    print_list(newHead);

    return 0;
}

// Function to create a linked list from an array of integers
Node *createLinkedList(int arr[], int length)
{
    Node *head = NULL;    // Initialize head pointer to NULL
    Node *temp = NULL;    // Temporary pointer for creating nodes
    Node *current = NULL; // Pointer to keep track of the current node

    for (int i = 0; i < length; i++)
    {
        // Allocate memory for a new node
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("Error! Could Not Allocate The memory\n");
            exit(1);
        }
        temp->data = arr[i]; // Set data for the new node
        temp->link = NULL;   // Set the link of the new node to NULL

        // If the list is empty, set the new node as the head
        if (head == NULL)
        {
            head = temp;
            current = temp; // Update the 'current' pointer
        }
        else // If the list is not empty
        {
            current->link = temp;    // Link the new node to the list
            current = current->link; // Update the 'current' pointer
        }
    }
    return head; // Return the head of the linked list
}

// Function to print the elements of a linked list
void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data); // Print the data of the current node
        head = head->link;            // Move to the next node
    }
    printf("NULL\n"); // Print NULL at the end
}

// Function to search for a value in the linked list and return its index
int searchingNode(Node *head, int value)
{
    int index = 1; // Initialize the index to 1
    while (head != NULL)
    {
        if (head->data == value) // Check if the current node's data matches the value
        {
            return index; // Return the index of the node
        }
        index++;           // Increment the index
        head = head->link; // Move to the next node
    }
    return 0; // Return 0 if the value is not found in the linked list
}

// Function to reverse a linked list using a double pointer
void reverse_linked_list(Node **head)
{
    Node *current = *head, *previous = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    *head = previous; // Update the head pointer to the new head of the reversed list
}

// Function to insert a node at the beginning of a linked list using a double pointer
void insertAtBeginning(Node **head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Error! Could Not Allocate Memory\n");
        exit(1);
    }
    temp->data = data;
    temp->link = *head; // Set the new node's link to the current head
    *head = temp;       // Update the head pointer to the new node
}

// Function to insert a node at the end of a linked list
void insertAtEnd(Node *head, int data)
{
    if (head == NULL)
    {
        printf("Error! Head is NULL\n");
        return;
    }
    Node *current = head;
    while (current->link != NULL)
    {
        current = current->link; // Traverse the list until the last node
    }
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Error! Could Not Allocate Memory\n");
        exit(1);
    }
    temp->data = data;
    temp->link = NULL;
    current->link = temp; // Link the new node at the end of the list
}

// Function to remove a node with a specific value from a linked list
Node *removeNode(Node *head, int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    Node *temp = head;
    if (head->data == data)
    {
        head = head->link; // Move the head to the next node
        free(temp);        // Free memory of the deleted node
        return head;       // Return the new head
    }
    while (temp->link != NULL && temp->link->data != data)
    {
        temp = temp->link; // Traverse the list until the node before the one to remove
    }
    if (temp->link == NULL)
    {
        printf("-----Data not found in the list-----\n");
        return head; // Return the original head if the data is not found
    }
    Node *toRemove = temp->link;
    temp->link = temp->link->link; // Remove the node by bypassing it
    free(toRemove);                // Free memory of the deleted node
    return head;                   // Return the head of the modified list
}

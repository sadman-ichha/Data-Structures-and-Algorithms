#include <stdio.h>
#include <stdlib.h>

// Node structure representing a linked list node
struct node
{
    int data;          // Data stored in the node
    struct node *link; // Pointer to the next node
};

typedef struct node Node; // Creating an alias 'Node' for 'struct node'

// Function declarations/Prototyps
Node *createLinkedList(int arr[], int length);
void print_list(Node *head);
int searchingNode(Node *head, int value);
void reverse_linked_list(Node *head);

int main()
{

    int arr[] = {5, 10, 15, 20, 25};
    int length = sizeof(arr) / sizeof(arr[0]); // Calculating the length of the array

    Node *head, *current; // Declaring pointers for linked list manipulation

    // Creating a linked list from the array
    head = createLinkedList(arr, length);
    current = head; // Storing the head pointer in 'current'

    // Printing the array list using the created linked list
    printf("Array List: ");
    print_list(head);

    // Searching for a node with value 5 and printing its index
    printf("Search Node Index: ");
    int result = searchingNode(head, 5);
    printf("%d \n", result);
    //
    Node *newHead;
    newHead = head;
    printf("Reverse Linked List: ");
    print_list(newHead);
    reverse_linked_list(newHead);

    return 0; // Indicates successful completion
}

void insertAtBeginning(Node *head, int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    
}

void reverse_linked_list(Node *head)
{
    Node *current = head, *previous = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

// Function to search for a value in the linked list and return its index
int searchingNode(Node *head, int value)
{
    int index = 1; // Index starts at 1
    while (head != NULL)
    {
        if (head->data == value) // Checking if the current node's data matches the value
        {
            return index; // Return the index of the node
        }
        index++;           // Incrementing the index
        head = head->link; // Move to the next node
    }
    return 0; // Return 0 if the value is not found in the linked list
}

// Function to create a linked list from an array of integers
Node *createLinkedList(int arr[], int length)
{
    int i;
    Node *head = NULL;    // Initializing the head pointer to NULL
    Node *temp = NULL;    // Temporary node pointer
    Node *current = NULL; // Pointer to keep track of the current node

    for (i = 0; i < length; i += 1)
    {
        // Allocating memory for a new node
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("Error! Could Not Allocate The memory\n");
            exit(1); // Exit the program in case of memory allocation failure
        }
        temp->data = arr[i]; // Setting data for the new node
        temp->link = NULL;   // Setting the link of the new node to NULL

        if (head == NULL) // If the list is empty
        {
            head = temp;    // Set the new node as the head
            current = temp; // Update the 'current' pointer
        }
        else
        {
            current->link = temp;    // Linking the new node to the list
            current = current->link; // Updating the 'current' pointer
        }
    }

    return head; // Return the head of the linked list
}

// Function to print the elements of a linked list
void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d-> ", head->data); // Printing the data of the current node
        head = head->link;           // Moving to the next node
    }
    printf("NULL\n");
}

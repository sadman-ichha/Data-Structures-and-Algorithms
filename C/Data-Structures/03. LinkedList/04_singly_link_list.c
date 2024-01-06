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

    Node *head = NULL; // Declaring pointers for linked list manipulation

    // Creating a linked list from the array
    head = createLinkedList(arr, length);
    Node *newHead = head; // Creating a new pointer to the head

    // Printing the array list using the created linked list
    printf("Array List: ");
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
    int dataToRemove = 15;
    newHead = removeNode(newHead, dataToRemove);
    printf("List after removing %d: ", dataToRemove);
    print_list(newHead);

    return 0;
}

Node *createLinkedList(int arr[], int length)
{
    Node *head = NULL;
    Node *temp = NULL;
    Node *current = NULL;

    for (int i = 0; i < length; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("Error! Could Not Allocate The memory\n");
            exit(1);
        }
        temp->data = arr[i];
        temp->link = NULL;

        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->link = temp;
            current = current->link;
        }
    }
    return head;
}

void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

int searchingNode(Node *head, int value)
{
    int index = 1;
    while (head != NULL)
    {
        if (head->data == value)
        {
            return index;
        }
        index++;
        head = head->link;
    }
    return 0;
}

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
    *head = previous;
}

void insertAtBeginning(Node **head, int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Error! Could Not Allocate Memory\n");
        exit(1);
    }
    temp->data = data;
    temp->link = *head;
    *head = temp;
}

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
        current = current->link;
    }
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Error! Could Not Allocate Memory\n");
        exit(1);
    }
    temp->data = data;
    temp->link = NULL;
    current->link = temp;
}

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
        head = head->link;
        free(temp);
        return head;
    }
    while (temp->link != NULL && temp->link->data != data)
    {
        temp = temp->link;
    }
    if (temp->link == NULL)
    {
        printf("Data not found in the list\n");
        return head;
    }
    Node *toRemove = temp->link;
    temp->link = temp->link->link;
    free(toRemove);
    return head;
}

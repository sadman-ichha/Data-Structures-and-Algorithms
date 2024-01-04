#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node
{
    int data;
    struct Node *next;
};
// create Link List function protype
struct Node *createLinkedList(int arr[], int length);

int main()
{
    int arrList[] = {5, 10, 15, 20,2};
    int length = sizeof(arrList) / sizeof(arrList[0]);
    struct Node *head; // Declare a pointer to the head of the linked list

    // Create the linked list and assign the returned head to 'head' pointer
    head = createLinkedList(arrList, length);

    // Traverse the linked list and print the data of each node
    while (head != NULL)
    {
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("NULL\n"); // Print NULL to signify the end of the list
    return 0;
}


// Function to create a linked list from an array
struct Node *createLinkedList(int arr[], int length)
{
    int i;
    // Declare pointers for head, temporary node, and current node
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *current = NULL;

    for (i = 0; i < length; i++)
    {
        // Create a new node
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;

        // If the list is empty, make the new node the head and the current node
        if (head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            // Otherwise, add the new node to the end of the list
            current->next = temp;
            current = current->next;
        }
    }
    return head; // Return the head of the linked list
}


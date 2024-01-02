#include <stdio.h>
#include <stdlib.h>

// Creating Node 
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    // Define three nodes: a, b, and c
    struct Node *a;
    struct Node *b;
    struct Node *c;

    // Allocate memory for each node
    a = (struct Node *)malloc(sizeof(struct Node));
    b = (struct Node *)malloc(sizeof(struct Node));
    c = (struct Node *)malloc(sizeof(struct Node));

    // Assign values to data members of each node
    a->data = 12;
    b->data = 20;
    c->data = 30;

    // Link the nodes together to form a linked list
    a->next = b;
    b->next = c;
    c->next = NULL; // Indicates the end of the linked list

    // Traversal: Printing the linked list
    while (a != NULL)
    {
        printf("%d,", a->data); // Print the data of each node
        a = a->next;            // Move to the next node
    }

    return 0;
}

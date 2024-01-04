#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

typedef struct node Node;

void createLinkedList(int arr[], int length);
Node *create_node(int item, Node *next);
Node *prepend(int item, Node *head);

int main()
{
    Node *n1, *n2, *n3, *head;
    n1 = create_node(10, NULL);
    head = n1;
    head =prepend(20 , head);
    n2 = head;

    printf("First data : %d", n2->data);

    return 0;
}

Node *create_node(int item, Node *next)
{
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Error! Could Not Create a New Node\n");
        exit(1);
    }
    new_node->data = item;
    new_node->link = next;
    return new_node;
}

Node *prepend(int item, Node *head)
{
    Node *new_node;
    new_node = create_node(item, head);
    return new_node;
}


#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct node
{
  int data;
  struct Node *next;
};
typedef struct node Node;
void insertAtBeginning(Node *head, int data);

int main()
{
  int arrList[] = {5, 10, 15, 20, 2};
  int length = sizeof(arrList) / sizeof(arrList[0]);
  insertAtBeginning();
  return 0;
}
void insertAtBeginning(Node *head, int data)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL)
  {
    printf("Error! Could Not Allocate Memory\n");
    exit(1);
  }
  temp->data = data;
  temp->link = head; // Set the new node's link to the current head
  print_list(head);
  head = temp;
  printf("Updated List After Insertion: ");
  print_list(head); // Print the entire updated list from the new node
}
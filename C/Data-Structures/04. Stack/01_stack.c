#include <stdio.h>
#define MAX 3

// Global Variables
int stack_arr[MAX]; // Array to hold stack elements
int top = -1;       // Variable to keep track of the top of the stack

void push(int data);
int pop();
int peek();

// Driver code
int main()
{
    peek();   // Trying to peek from an empty stack
    push(10); // Adding elements to the stack
    push(11);
    push(20);
    push(30);                             // Trying to push when the stack is full
    printf("Pop Item: %d\n", pop());      // Removing an element from the stack
    printf("Top Of Stack: %d\n", peek()); // Checking the top element of the stack
    push(30);                             // Adding an element after a pop
    printf("Top Of Stack: %d\n", peek()); // Checking the top element of the stack again

    return 0;
}

// Function to add an element to the top of the stack
void push(int data)
{
    // Check if the stack is not full
    if (top < MAX - 1)
    {
        top = top + 1;         // Move the top pointer
        stack_arr[top] = data; // Add the element to the stack
        printf("Successfully Added %d\n", data);
    }
    else
    {
        printf("Exceptions! Stack is Full/Overflow\n");
    }
}

// Function to remove an element from the top of the stack
int pop()
{
    // Check if the stack is not empty
    if (top >= 0)
    {
        int removeVal = stack_arr[top]; // Store the top element to be removed
        top = top - 1;                  // Decrement the top pointer
        return removeVal;               // Return the removed element
    }
    printf("Exceptions from POP! Stack is Empty..\n");
    return -1; // Return -1 for an empty stack
}

// Function to return the element at the top of the stack without removing it
int peek()
{
    // Check if the stack is not empty
    if (top >= 0)
    {
        return stack_arr[top]; // Return the top element of the stack
    }
    printf("Exceptions from Peek! Empty Stack..\n");
    return -1; // Return -1 for an empty stack
}
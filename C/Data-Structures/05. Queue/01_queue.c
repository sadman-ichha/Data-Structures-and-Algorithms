#include <stdio.h>       // Include necessary header files
#include <stdbool.h>

#define MAXQUEUE 5        // Define the maximum size of the queue

int queue[MAXQUEUE];      // Declare an array to represent the queue
int front = 0, rear = -1, totalData = 0;  // Initialize queue variables

// Function prototype
void enqueue(int data);    
int dequeue();            
bool isFull();            
bool isEmpty();           
void printQueue();        

int main()
{
    enqueue(1);            // Enqueue the value 1
    enqueue(2);            // Enqueue the value 2
    enqueue(3);            // Enqueue the value 3
    enqueue(4);            // Enqueue the value 4
    enqueue(5);            // Enqueue the value 5
    dequeue();             // Dequeue an element Front element removed
    enqueue(100);          // Enqueue the value 100

    return 0;              // Return 0 to indicate successful execution
}

bool isFull()
{
    if (totalData == MAXQUEUE)  // Check if the queue is full
    {
        return true;           // Return true if the queue is full
    }
    return false;              // Return false if the queue is not full
}

bool isEmpty()
{
    if (totalData == 0)         // Check if the queue is empty
    {
        return true;            // Return true if the queue is empty
    }
    return false;               // Return false if the queue is not empty
}

void enqueue(int data)
{
    if (isFull())               // Check if the queue is full
    {
        printf("Sorry, Couldn't be Added (%d)! Queue is Full..\n \n", data);
        return;                 // Exit the function if the queue is full
    }

    rear = (rear + 1) % MAXQUEUE;   // Calculate the next rear index with wrap-around
    queue[rear] = data;             // Enqueue the data at the calculated rear index
    totalData++;                    // Increment the total number of elements in the queue

    printf("Enqueued: %d\n", data);  // Print a message indicating the enqueued value
    printQueue();                    // Print the current state of the queue
}

int dequeue()
{
    if (isEmpty())                  // Check if the queue is empty
    {
        printf("Sorry, The Queue is Empty..\n");
        return -1;                  // Return -1 if the queue is empty
    }

    int frontItem = queue[front];   // Retrieve the front item of the queue
    queue[front] = -1;              // Set the front position to -1 (indicating no data)
    front = (front + 1) % MAXQUEUE;  // Move the front index to the next position with wrap-around
    totalData--;                    // Decrement the total number of elements in the queue

    printf("Dequeued: %d\n", frontItem);  // Print a message indicating the dequeued value
    printQueue();                         // Print the current state of the queue

    return frontItem;                     // Return the dequeued value
}

void printQueue()
{
    printf("Queue: ");
    int i;
    for (i = 0; i < MAXQUEUE; i++)
    {
        printf("%d ", queue[i]);   // Print each element of the queue
    }
    printf("\n");
}

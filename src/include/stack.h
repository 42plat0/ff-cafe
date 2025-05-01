#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Datatype used
typedef int DT;

// Stack structure with dynamic array
typedef struct {
    DT* array;        // Dynamic array to store elements
    int top;           // Index of the top element
    int capacity;      // Total capacity of the stack
} Stack;

// Initialize a new stack with given capacity
Stack* createStack(int capacity);

// Check if stack is empty
bool isEmpty(Stack* stack);

// Check if stack is full
bool isFull(Stack* stack);

// Push an element onto the stack
void push(Stack* stack, DT item);

// Pop an element from the stack
int pop(Stack* stack);

// Return the top element without removing it
int peek(Stack* stack);

// Get current size of the stack
int size(Stack* stack);

// Free memory allocated for the stack
void destroyStack(Stack* stack);

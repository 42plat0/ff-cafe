#include "stack.h"

// Initialize a new stack with given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack)
        return NULL;
    
    stack->capacity = capacity;
    stack->top = -1;  // Stack is initially empty
    stack->array = (DT*)malloc(stack->capacity * sizeof(DT));
    
    if (!stack->array) {
        free(stack);
        return NULL;
    }
    
    return stack;
}

// Check if stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// TODO update input datatype
// Push an element onto the stack
void push(Stack* stack, DT item) {
    // TODO needs to go to its own functionk

    if (isFull(stack)) {
        // Resize the stack by doubling its capacity
        int newCapacity = stack->capacity * 2;
        int* newArray = (DT*)realloc(stack->array, newCapacity * sizeof(DT));
        
        if (!newArray) {
            printf("Stack overflow. Cannot allocate more memory.\n");
            return;
        }
        
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    
    stack->array[++stack->top] = item;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1;  // Return a sentinel value indicating error
    }
    
    return stack->array[stack->top--];
}

// Return the top element without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;  // Return a sentinel value indicating error
    }
    
    return stack->array[stack->top];
}

// Get current size of the stack
int size(Stack* stack) {
    return stack->top + 1;
}

// Free memory allocated for the stack
void destroyStack(Stack* stack) {
    if (stack) {
        free(stack->array);
        free(stack);
    }
}

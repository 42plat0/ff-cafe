#include "include/stack.h"

// Example usage
int main() {
    // Create a stack with initial capacity of 5
    Stack* stack = createStack(5);
    
    // Push some elements
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    
    printf("Top element: %d\n", peek(stack));
    printf("Stack size: %d\n", size(stack));
    
    // Pop elements
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    
    printf("Stack size after pops: %d\n", size(stack));
    
    // Push more elements to show automatic resizing
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);
    push(stack, 70);
    push(stack, 80);
    push(stack, 90);
    
    printf("Stack size after multiple pushes: %d\n", size(stack));
    printf("Stack capacity after resize: %d\n", stack->capacity);
    
    // Clean up
    destroyStack(stack);
    
    return 0;
}

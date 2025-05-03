#include "stack.h"
#include <stdlib.h>

/**
 * Initialize a new empty stack
 */
Stack* stack_create(void) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;  // Memory allocation failed
    }
    
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

/**
 * Check if the stack is empty
 */
bool stack_is_empty(const Stack* stack) {
    if (stack == NULL) {
        return true;  // NULL stack is considered empty
    }
    return stack->top == NULL;
}

/**
 * Get the current size of the stack
 */
int stack_size(const Stack* stack) {
    if (stack == NULL) {
        return 0;  // NULL stack has size 0
    }
    return stack->size;
}

/**
 * Push an element onto the stack
 */
bool stack_push(Stack* stack, void* data) {
    if (stack == NULL) {
        return false;  // Invalid stack
    }
    
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    if (new_node == NULL) {
        return false;  // Memory allocation failed
    }
    
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
    
    return true;
}

/**
 * Pop an element from the stack
 */
void* stack_pop(Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;  // Stack is empty or invalid
    }
    
    StackNode* top_node = stack->top;
    void* data = top_node->data;
    
    stack->top = top_node->next;
    stack->size--;
    
    free(top_node);  // Free the node (but not the data)
    return data;
}

/**
 * Peek at the top element without removing it
 */
void* stack_peek(const Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;  // Stack is empty or invalid
    }
    
    return stack->top->data;
}

/**
 * Clear all elements from the stack
 */
void stack_clear(Stack* stack, void (*free_data)(void*)) {
    if (stack == NULL) {
        return;  // Invalid stack
    }
    
    StackNode* current = stack->top;
    StackNode* next;
    
    while (current != NULL) {
        next = current->next;
        
        if (free_data != NULL) {
            free_data(current->data);  // Free the data using the provided function
        }
        
        free(current);  // Free the node
        current = next;
    }
    
    stack->top = NULL;
    stack->size = 0;
}

/**
 * Destroy the stack and free all allocated memory
 */
void stack_destroy(Stack* stack, void (*free_data)(void*)) {
    if (stack == NULL) {
        return;  // Invalid stack
    }
    
    stack_clear(stack, free_data);  // Clear all nodes and optionally free data
    free(stack);  // Free the stack itself
}
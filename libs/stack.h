#ifndef STACK_H
#define STACK_H

// Define the type of elements stored in the stack
typedef int type;

// Define new name for more convenient use
typedef struct Node Stack;

// A node in stack structure
struct Node;

// Function to print the whole stack for debbuging
void print_stack(struct Node *head);

// Function to initialize the stack
struct Node* initialize_stack();

// Function to check if the stack is empty
int is_empty(struct Node *head);

// Function to check if the stack is full
int is_full(struct Node *head);

// Function to push an element onto the stack and return 1 if successful, 0 otherwise
int push(struct Node **head, type value);

// Function to pop an element from the stack
type pop(struct Node **head);

// Function to peek at the top element of the stack without removing it
type peek(struct Node *head);

// Function to remove and free the entire stack
void remove_stack(struct Node **head);

#endif

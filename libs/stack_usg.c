#include "stack.h"
#include <stdio.h>

/* Main function is used to show how the stack library works */
int main() {
    Stack *stack = initialize_stack();
    printf("Is empty: %d\n", is_empty(stack));
    print_stack(stack);
    push(&stack, 45);
    print_stack(stack);
    push(&stack, 33);
    push(&stack, 12);
    push(&stack, 100);
    push(&stack, -789);
    push(&stack, 0);
    print_stack(stack);
    printf("Is empty: %d\n", is_empty(stack));
    printf("Is full: %d\n", is_full(stack));
    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));
    print_stack(stack);
    printf("Peek: %d\n", peek(stack));
    print_stack(stack);
    remove_stack(&stack);
    print_stack(stack);

    return 0;
}

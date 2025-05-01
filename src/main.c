#include "include/stack.h"
#include "include/queue.h"
#include "include/config.h"


// Example usage
int main() {
    use_queue();

    return 0;
}

 void use_queue(){
     Queue* queue = queue_init(); 

    if (queue==NULL){
        return;
    }
     int* data = malloc(sizeof(int));

    if(data == NULL){
        return ;
    }
    *data = 3;
    queue_enqueue(queue, data);

     printf("Top element: %d\n", *((int*) queue_peek(queue)));
     printf("Queue size: %d\n", queue_size(queue));
 

 }

void use_stack(){
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

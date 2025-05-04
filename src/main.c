#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "include/stack.h"
#include "include/queue.h"
#include "include/config.h"
#include "include/sandwich.h"
#include "include/dispenser.h"

void use_dispenser();
void store_func();
bool is_sandwich_taken(double p);

// Example usage
int main() {


    srand(time(NULL));
    double sandwich_taken_probability = SANDWICH_EAT_PER_S_PROBABILITY;
    int sandwiches_taken = 0;
    Sandwich* s = sandwich_init(SANDWICH_PRICE, SANDWICH_FRESH_LENGTH);
    printf("Sandwich exp time left %d\n",s->expires_in);

    for (int i = 0; i <  WORKDAY_LENGTH; i++){
        sandwich_decrement_expiration_time(s);
        if (is_sandwich_taken(sandwich_taken_probability)){
            // printf("Taken\n");
            sandwiches_taken++;
            
        }
        else{
            // printf("Not taken\n");
        }

    }
    printf("Sandwiches taken in %d time is:  %d\n", WORKDAY_LENGTH, sandwiches_taken);
    printf("Sandwich exp time left %d\n",s->expires_in);
    return 0;
}

bool is_sandwich_taken(double p){
    if (p == 1){
        return true;
    }else if(p == 0){
        return false;
    }

    double random = (double) rand() / RAND_MAX;
    return random < p;
}

void store_func(){
    Dispenser* dispenser_1 = dispenser_init();
    Dispenser* dispenser_2 = dispenser_init();

}

void use_dispenser(){
    Dispenser* dispenser = dispenser_init();

    int count = dispenser_get_sandwich_count(dispenser);
    printf("Count: %d\n", count);

     dispenser_load_sandwiches(
         dispenser, 
         SANDWICH_PROD_COUNT,
         SANDWICH_PRICE,
         SANDWICH_FRESH_LENGTH
     );
    
     count = dispenser_get_sandwich_count(dispenser);
     printf("Count: %d\n", count);

     dispenser_remove_item(dispenser);

     count = dispenser_get_sandwich_count(dispenser);
     printf("Count: %d\n", count);

     dispenser_add_item(dispenser, sandwich_init(3, 300));

     count = dispenser_get_sandwich_count(dispenser);
     printf("Count: %d\n", count);

     count = dispenser_unload_sandwiches(dispenser);

     printf("Unloaded Count: %d\n", count);
     count = dispenser_get_sandwich_count(dispenser);
     printf("Count: %d\n", count);
}

//  void use_queue(){
//      Queue* queue = queue_init(); 

//     if (queue==NULL){
//         return;
//     }
//      int* data = malloc(sizeof(int));

//     if(data == NULL){
//         return ;
//     }
//     *data = 3;
//     queue_enqueue(queue, data);

//      printf("Top element: %d\n", *((int*) queue_peek(queue)));
//      printf("Queue size: %d\n", queue_size(queue));
 

//  }

// void use_stack(){
//     // Create a stack with initial capacity of 5
//     Stack* stack = createStack(5);
    
//     // Push some elements
//     push(stack, 10);
//     push(stack, 20);
//     push(stack, 30);
    
//     printf("Top element: %d\n", peek(stack));
//     printf("Stack size: %d\n", size(stack));
    
//     // Pop elements
//     printf("Popped: %d\n", pop(stack));
//     printf("Popped: %d\n", pop(stack));
    
//     printf("Stack size after pops: %d\n", size(stack));
    
//     // Push more elements to show automatic resizing
//     push(stack, 40);
//     push(stack, 50);
//     push(stack, 60);
//     push(stack, 70);
//     push(stack, 80);
//     push(stack, 90);
    
//     printf("Stack size after multiple pushes: %d\n", size(stack));
//     printf("Stack capacity after resize: %d\n", stack->capacity);
    
//     // Clean up
//     destroyStack(stack);
    
//     return 0;
// }

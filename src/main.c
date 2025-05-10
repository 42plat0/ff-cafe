#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "include/stack.h"
#include "include/queue.h"
#include "include/config.h"
#include "include/sandwich.h"
#include "include/dispenser.h"
#include "include/cafe.h"

const double sandwich_taken_probability = SANDWICH_EAT_PER_S_PROBABILITY;
const int sandwich_fresh_len = SANDWICH_FRESH_LENGTH;
const int sandwich_prod_time = SANDWICH_PROD_TIME; 
const int sandwich_prod_count = SANDWICH_PROD_COUNT;
const float sandwich_price = SANDWICH_PRICE;

void functional_store();
void use_dispenser();
void store_func();

// Example usage
int main() {

    store_func();

    return 0;
}

// STORE.C
void store_func(){

    Cafe* cafe_stack = cafe_init(2, sandwich_prod_time);
    cafe_stack->dispensers[0] = dispenser_init(false);
    cafe_stack->dispensers[1] = dispenser_init(false);
    cafe_initial_dispenser_load(cafe_stack, sandwich_prod_count, sandwich_price, sandwich_fresh_len);

    Cafe* cafe_queue = cafe_init(1, sandwich_prod_time);
    cafe_queue->dispensers[0] = dispenser_init(true);
    cafe_initial_dispenser_load(cafe_queue, sandwich_prod_count, sandwich_price, sandwich_fresh_len);

    int time_seconds;
    srand(time(NULL));
    for (time_seconds = 0; time_seconds < WORKDAY_LENGTH; time_seconds++){
        if (dispenser_is_sandwich_taken(sandwich_taken_probability)){

            // // While there are sandwiches and next one is expired
            // // Take sandwiches and either sell or throwaway
            cafe_run_sandwiches(cafe_stack, time_seconds);
            cafe_run_sandwiches(cafe_queue, time_seconds);

        }

        if (cafe_is_sandwich_load_time(cafe_stack, time_seconds)){
            dispenser_load_sandwiches(
                cafe_get_emptiest_dispenser(cafe_stack), 
                sandwich_prod_count, 
                sandwich_price, 
                sandwich_fresh_len, 
                time_seconds
            );
            cafe_stack->total_sandwich_made += sandwich_prod_count;

            dispenser_load_sandwiches(
                cafe_get_emptiest_dispenser(cafe_queue), 
                sandwich_prod_count, 
                sandwich_price, 
                sandwich_fresh_len, 
                time_seconds
            );
            cafe_queue->total_sandwich_made += sandwich_prod_count;
        }
    }
    // END OF WORKDAY
    printf("----------------------------\n");
    printf("--- STACK implementation ---\n");
    printf("----------------------------\n");
    cafe_display_leftovers(cafe_stack, time_seconds);
    cafe_show_stats(cafe_stack);
    cafe_destroy(cafe_stack);

    printf("----------------------------\n");
    printf("--- QUEUE implementation ---\n");
    printf("----------------------------\n");
    cafe_display_leftovers(cafe_queue, time_seconds);
    cafe_show_stats(cafe_queue);
    cafe_destroy(cafe_queue);
    printf("----------------------------\n");
    return;
}

void functional_store(){
    srand(time(NULL));

    int total_s_made = 0;
    int sandwiches_taken = 0;
    int expired_s = 0;

    Dispenser* dispenser_1 = dispenser_init(0);
    Dispenser* dispenser_2 = dispenser_init(0);
    Dispenser* dispenser_3 = dispenser_init(0);
    Dispenser* dispenser_4 = dispenser_init(0);

    dispenser_load_sandwiches(
        dispenser_1, 
        sandwich_prod_count, 
        sandwich_price, 
        sandwich_fresh_len, 
        0
    );
    dispenser_load_sandwiches(
        dispenser_2, 
        12, 
        sandwich_price, 
        sandwich_fresh_len, 
        0
    );

    Cafe* cafe = cafe_init(2, sandwich_prod_time);

    cafe->dispensers[0] = dispenser_1;
    cafe->dispensers[1] = dispenser_2;

    cafe_initial_dispenser_load(cafe, sandwich_prod_count, sandwich_price, sandwich_fresh_len);

    int time_seconds;
    for (time_seconds = 0; time_seconds < WORKDAY_LENGTH; time_seconds++){
        if (dispenser_is_sandwich_taken(sandwich_taken_probability)){
            Dispenser* not_empty_disp = cafe_get_non_empty_dispenser(cafe);
            Sandwich* taken_sandwich = (Sandwich*) dispenser_remove_item(not_empty_disp);

            // // While there are sandwiches and next one is expired
            // // Take sandwiches and either sell or throwaway
            // while(dispenser_get_sandwich_count(dispenser_1) > 0 && sandwich_is_expired(taken_sandwich, time_seconds)){
            //     expired_s++;
            //     printf("\t\r%d total sandwiches\n", dispenser_get_sandwich_count(dispenser_1));
            //     printf("taken sandwich is expired, loss: %f\n", taken_sandwich->price);
            //     taken_sandwich = (Sandwich*) dispenser_remove_item(dispenser_1);
            // }
            // if (taken_sandwich){
            //     sandwiches_taken++;
            //     printf("taken sandwich is good, profit: %f\n", taken_sandwich->price);
            // }
            // else{
            //     printf("No sandwiches left: %d\n", dispenser_get_sandwich_count(dispenser_1));
            // }
            cafe_run_sandwiches(cafe, time_seconds);
        }

        if (cafe_is_sandwich_load_time(cafe, time_seconds)){
            dispenser_load_sandwiches(
                cafe_get_emptiest_dispenser(cafe), 
                sandwich_prod_count, 
                sandwich_price, 
                sandwich_fresh_len, 
                time_seconds
            );
            cafe->total_sandwich_made=+sandwich_prod_count;
        }
    }
    // END OF WORKDAY
    printf("Sandwiches made: %d\n", cafe->total_sandwich_made);
    // printf("Sandwiches taken in %d time is: %d\n", WORKDAY_LENGTH, sandwiches_taken);
    // printf("Sandwiches taken in %d time that were expired is: %d\n", WORKDAY_LENGTH, expired_s);
    // printf("Sandwiches left %d\n", dispenser_get_sandwich_count(dispenser_1));
    
    // if (!dispenser_get_sandwich_count(dispenser_1)){
    //     return 0;
    // }

    // Calculates leftovers

    // Sandwich* taken_sandwich = (Sandwich*) dispenser_remove_item(dispenser_1);

    // int left_exp = 0;
    // int left_good = 0;
    //     if (sandwich_is_expired(taken_sandwich, time_seconds)){
    //         left_exp++;
    //     }
    //     else{
    //         left_good++;
    //     }
    // // While there are sandwiches, check how many expired and not
    // while(dispenser_get_sandwich_count(dispenser_1) > 0){
    //     if (sandwich_is_expired(taken_sandwich, time_seconds)){
    //         left_exp++;
    //     }
    //     else{
    //         left_good++;
    //     }
    //     taken_sandwich = (Sandwich*) dispenser_remove_item(dispenser_1);
    // }
    // printf("Sandwiches left good:  %d\n", left_good);
    // printf("Sandwiches left exp:  %d\n", left_exp);
    cafe_display_leftovers(cafe, time_seconds);

    return;
}

void use_dispenser(){
    Dispenser* dispenser = dispenser_init(0);

    int count = dispenser_get_sandwich_count(dispenser);
    printf("Count: %d\n", count);

     dispenser_load_sandwiches(
         dispenser, 
         SANDWICH_PROD_COUNT,
         SANDWICH_PRICE,
         SANDWICH_FRESH_LENGTH,
        0
     );
    
     count = dispenser_get_sandwich_count(dispenser);
     printf("Count: %d\n", count);

     dispenser_remove_item(dispenser);

     count = dispenser_get_sandwich_count(dispenser);
     printf("Count: %d\n", count);

     dispenser_add_item(dispenser, sandwich_init(3, 300, 0));

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

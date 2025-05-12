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

    Cafe* cafe_queue = cafe_init(2, sandwich_prod_time);
    cafe_queue->dispensers[0] = dispenser_init(true);
    cafe_queue->dispensers[1] = dispenser_init(true);
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


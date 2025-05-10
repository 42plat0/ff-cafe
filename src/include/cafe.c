#include "cafe.h"

Cafe* cafe_init(int disp_count, int sandwich_prod_time){
    Cafe* cafe = (Cafe*) malloc(sizeof(Cafe));

    if (cafe == NULL || disp_count < 0 || sandwich_prod_time < 0){
        perror("Cafe, Dispenser count or Sandwich produce time is invalid");
        return NULL;
    }

    cafe->dispenser_count = disp_count;
    cafe->sandwich_prod_time = sandwich_prod_time;
    cafe->loss = 0, cafe->profit = 0, cafe->total_sandwich_made = 0, cafe->expired = 0;

    cafe->dispensers = malloc(cafe->dispenser_count * sizeof(Dispenser *));

    if (cafe->dispensers == NULL){
        perror("Couldn't initialize Cafe struct");
        return NULL;
    }

    return cafe;
}

Dispenser* cafe_get_emptiest_dispenser(Cafe* cafe){
    if (cafe == NULL || cafe->dispensers == NULL){
        perror("Cafe or its dispensers are null, returning empty");
        return NULL;
    }

    Dispenser* min_disp = cafe->dispensers[0];
    int min = 9999;

    // Check item count for each dispenser in Cafe
    for(int i = 0; i < cafe->dispenser_count; i++){
        int item_count = dispenser_get_sandwich_count(cafe->dispensers[i]);
        if (item_count < min){
            min = item_count; 
            min_disp = cafe->dispensers[i];
        }
    }
    return min_disp;
}

// TODO - update to random disp?
Dispenser* cafe_get_non_empty_dispenser(Cafe* cafe){
    if (cafe == NULL || cafe->dispensers == NULL){
        perror("Cafe or its dispensers are null, returning empty");
        return NULL;
    }

    int random = rand() % cafe->dispenser_count;
    Dispenser* disp = cafe->dispensers[random];
    while (disp == NULL){
        disp = cafe->dispensers[rand() % cafe->dispenser_count];
    }
    
    return disp; 
}

bool cafe_is_sandwich_load_time(Cafe* cafe, int curr_time){
    if (cafe == NULL){
        perror("Cafe is null, returning empty");
        return NULL;
    }

    return curr_time % cafe->sandwich_prod_time == 0 && curr_time >= cafe->sandwich_prod_time;
}

void cafe_initial_dispenser_load(Cafe* cafe, int prod_count, float price, int fresh_len){
    if (cafe == NULL){
        perror("Cafe is null, returning empty");
        return;
    }
    for(int i = 0; i < cafe->dispenser_count; i++){
        dispenser_load_sandwiches(
            cafe->dispensers[i],
            prod_count / cafe->dispenser_count,
            price,
            fresh_len,
            0
        );
        cafe->total_sandwich_made += prod_count / cafe->dispenser_count;
    }
}

void cafe_run_sandwiches(Cafe* cafe, int current_time){
    if (cafe == NULL || current_time < 0){
        perror("Cafe/Sandwich/current_time is null, returning");
        return;
    }

    Dispenser* disp = cafe_get_non_empty_dispenser(cafe);
    if (!disp) {
        printf("No sandwiches available.\n");
        return;
    }

    Sandwich* taken_sandwich = (Sandwich*) dispenser_remove_item(disp);

    if (taken_sandwich == NULL){
        return;
    }
    if (sandwich_is_expired(taken_sandwich, current_time)){
        cafe->expired++;
        disp->items_expired++;
        printf("Taken sandwich was expired, incurred loss of: $%.2f\n", taken_sandwich->price);

        cafe_increase_loss(cafe, taken_sandwich->price);
    }
    else{
        cafe_increase_profit(cafe, taken_sandwich->price);
        printf("Taken sandwich is good, profit: %.2f\n", taken_sandwich->price);
    }
    disp->items_taken++;
}

void cafe_increase_profit(Cafe* cafe, float price){

    if (cafe == NULL){
        perror("Cafe is null, returning empty");
        return;
    }

    cafe->profit += price;
}

void cafe_increase_loss(Cafe* cafe, float price){

    if (cafe == NULL){
        perror("Cafe is null, returning empty");
        return;
    }

    cafe->loss += price;
}

int* cafe_get_leftovers(Cafe* cafe, int end_time){
    int* leftovers = (int*) malloc(2 * sizeof(int));
    // exp          ,  good
    leftovers[0] = 0, leftovers[1] = 0;

    if (cafe == NULL || cafe->dispensers == NULL || end_time < 0){
        perror("Cafe or its dispensers are null, returning empty");
        return NULL;
    }

    for(int i = 0; i < cafe->dispenser_count; i++){
        Dispenser* curr_disp = cafe->dispensers[i];
        bool has_items = dispenser_get_sandwich_count(curr_disp);
        if (!has_items) continue;

        while(has_items){
            Sandwich* taken_sandwich = (Sandwich*) dispenser_remove_item(curr_disp);
            // if sandwich is expired, increment exp or good
            if (sandwich_is_expired(taken_sandwich, end_time)){
                leftovers[0]++;
                curr_disp->items_expired++;
            }else{
                leftovers[1]++;
            }

            cafe_increase_loss(cafe, taken_sandwich->price);
            has_items = dispenser_get_sandwich_count(curr_disp);
        }
    }

    return leftovers;
}

void cafe_display_leftovers(Cafe* cafe, int end_time){
    if (cafe == NULL){
        perror("Cafe is null, returning empty");
        return;
    }

    int* leftover_arr = cafe_get_leftovers(cafe, end_time);

    printf("Sandwiches left: %d\n", leftover_arr[0] + leftover_arr[1]);
    printf("Sandwiches left exp: %d\n", leftover_arr[0]);
    printf("Sandwiches left good: %d\n", leftover_arr[1]);

    free(leftover_arr);
}

void cafe_show_stats(Cafe* cafe){
    if (cafe == NULL){
        perror("Cafe is null, returning empty");
        return;
    }
    printf("Gross: $%.2f\n", cafe->profit + cafe->loss);
    printf("Total profit: $%.2f\n", cafe->profit);
    printf("Total loss: $%.2f\n", cafe->loss);
    printf("Sandwiches made: %d\n", cafe->total_sandwich_made);
    printf("Sandwiches expired: %d\n", cafe->expired);

}

void cafe_destroy(Cafe* cafe){
    for(int i = 0; i < cafe->dispenser_count; i++){
        Dispenser* curr_disp = cafe->dispensers[i];
        if (curr_disp == NULL) continue;
        dispenser_unload_sandwiches(curr_disp);
        dispenser_destroy(curr_disp);
    }

    free(cafe);
}
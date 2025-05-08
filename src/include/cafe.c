#include "cafe.h"

Cafe* cafe_init(int disp_count, int sandwich_prod_time){
    Cafe* cafe = (Cafe*) malloc(sizeof(Cafe));

    if (cafe == NULL || disp_count < 0 || sandwich_prod_time < 0){
        perror("Cafe, Dispenser count or Sandwich produce time is invalid");
        return NULL;
    }

    cafe->dispenser_count = disp_count;
    cafe->sandwich_prod_time = sandwich_prod_time;

    cafe->dispensers = (Dispenser*)malloc(cafe->dispenser_count * sizeof(Dispenser));

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

Dispenser* cafe_get_non_empty_dispenser(Cafe* cafe){
    if (cafe == NULL || cafe->dispensers == NULL){
        perror("Cafe or its dispensers are null, returning empty");
        return NULL;
    }

    // Check item count for each dispenser in Cafe
    for(int i = 0; i < cafe->dispenser_count; i++)
        if (dispenser_get_sandwich_count(cafe->dispensers[i]) > 0)
            return cafe->dispensers[i]; 

    perror("No dispensers have sandwiches, returning null");
    return NULL;
}

bool cafe_is_sandwich_load_time(Cafe* cafe, int curr_time){
    if (cafe == NULL){
        perror("Cafe is null, returning empty");
        return NULL;
    }

    // First load
    if (curr_time == 0 && cafe->sandwich_prod_time){
        return true;
    }

    return curr_time % cafe->sandwich_prod_time == 0 && curr_time >= cafe->sandwich_prod_time;
}

void cafe_run_sandwiches(Cafe* cafe, Sandwich* taken_sandwich, int current_time){
    if (cafe == NULL || taken_sandwich == NULL || current_time < 0){
        perror("Cafe/Sandwich/current_time is null, returning");
        return;
    }

    Dispenser* disp = cafe_get_non_empty_dispenser(cafe);

    bool has_disp_items = dispenser_get_sandwich_count(disp) > 0;
    bool is_sandwich_exp = sandwich_is_expired(taken_sandwich, current_time);

    while(has_disp_items && is_sandwich_exp)
    {
        disp->items_expired++;
        cafe_increase_loss(cafe, taken_sandwich->price);

        printf("\t\r%d total sandwiches\n", dispenser_get_sandwich_count(disp));
        printf("taken sandwich is expired, loss: %f\n", taken_sandwich->price);

        taken_sandwich = (Sandwich*) dispenser_remove_item(disp);
    }

    if (taken_sandwich){
        disp->items_taken++;
        cafe_increase_profit(cafe, taken_sandwich->price);
        printf("taken sandwich is good, profit: %f\n", taken_sandwich->price);
    }
    else{
        printf("No sandwiches left: %d\n", dispenser_get_sandwich_count(disp));
    }
}

void cafe_increase_profit(Cafe* cafe, float price){

    if (cafe == NULL){
        perror("Cafe is null, returning empty");
        return NULL;
    }

    cafe->profit += price;
}

void cafe_increase_loss(Cafe* cafe, float price){

    if (cafe == NULL){
        perror("Cafe is null, returning empty");
        return NULL;
    }

    cafe->loss += price;
}
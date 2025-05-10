#include "sandwich.h"

// Gets you a sandwich
Sandwich* sandwich_init(float sandwich_price, int sandwich_exp_in, int sandwich_made){
    Sandwich* new_sandwich = (Sandwich*) malloc(sizeof(Sandwich));         
    
    if (new_sandwich == NULL){
        perror("Couldn't alloc mem for sandwich struct");
        return NULL;
    }
    new_sandwich->expires_in = sandwich_exp_in;
    new_sandwich->price = sandwich_price;
    new_sandwich->made = sandwich_made;
    
    return new_sandwich;
}

// Tells if sandwich is no good to eat
bool sandwich_is_expired(Sandwich* sandwich, int curr_time){
    if (sandwich == NULL){
        perror("Sandwich struct is null");
        return NULL;
    }

    return sandwich->expires_in + sandwich->made < curr_time;  
}

void sandwich_decrement_expiration_time(Sandwich* sandwich){
    if (sandwich == NULL){
        perror("Sandwich struct is null");
        return;
    }

    sandwich->expires_in -= 1; // Second
}

// You eat sandwich
void sandwich_destroy(Sandwich* sandwich){
    if (sandwich == NULL) return;
    free(sandwich);
}

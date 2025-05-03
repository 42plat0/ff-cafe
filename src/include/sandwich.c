#include "sandwich.h"

// Gets you a sandwich
Sandwich* init_sandwich(float sandwich_price, int sandwich_exp_in){
    Sandwich* new_sandwich = (Sandwich*) malloc(sizeof(Sandwich));         
    
    if (new_sandwich == NULL){
        perror("Couldn't alloc mem for sandwich struct");
        return NULL;
    }

    new_sandwich->price = sandwich_price;
    new_sandwich->expires_in = sandwich_exp_in;

    return new_sandwich;
}

// Tells if sandwich is no good to eat
bool is_expired(Sandwich* sandwich){
    if (sandwich == NULL){
        perror("Sandwich struct is null");
        return NULL;
    }

    return sandwich->expires_in > 0;
}

// You eat sandwich
void destroy_sandwich(Sandwich* s){
    if (s == NULL) return;
    free(s);
}
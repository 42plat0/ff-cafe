#include "sandwich.h"

// Gets you a sandwich
Sandwich* init_sandwich(float sandwich_price, int sandwich_exp_in){
    Sandwich* new_sandwich = (Sandwich*) malloc(sizeof(Sandwich));         
    
    if (new_sandwich == null){
        perror("Couldn't alloc mem for sandwich struct");
        return null;
    }

    new_sandwich->price = sandwich_price || NULL;
    new_sandwich->expires_in = sandwich_exp_in || NULL;

    return new_sandwich;
}

// Tells if sandwich is no good to eat
bool is_expired(Sandwich* sandwich){
    if (sandwich == null){
        perror("Sandwich struct is null");
        return null;
    }

    return sandwich->expires_in > 0;
}


#include "dispenser.h"

const int SANDWICH_MAX_TOTAL= 9999;

Dispenser* dispenser_init(int isQueue){
    Dispenser* dispenser = (Dispenser*)malloc(sizeof(Dispenser));

    if (!dispenser){
        perror("Dispenser couldn't be created");
        return NULL;
    }

    if (!isQueue){
        dispenser->item_rack = stack_create();
    }else{
        // TODO queue
    }

    dispenser->items_in_total = 0;
    dispenser->items_expired = 0;
    dispenser->items_taken = 0;

    if (!dispenser->item_rack){
        perror("Item rack for dispenser couldn't be created");
        return NULL;
    }

    return dispenser;
}

void dispenser_add_item(Dispenser* sandwich_dispenser, Sandwich* sandwich){
    if (
        sandwich_dispenser == NULL || 
        sandwich == NULL || 
        sandwich_dispenser->item_rack == NULL
    ){
        perror("Dispenser/sandwich/stack is null, cant add item");
        return;
    }
    
    stack_push(sandwich_dispenser->item_rack, sandwich); 
    sandwich_dispenser->items_in_total++;
}

void* dispenser_remove_item(Dispenser* sandwich_dispenser){
    if (sandwich_dispenser == NULL){
        perror("Dispenser is null, cant remove item");
        return NULL;
    }

    return stack_pop(sandwich_dispenser->item_rack);
}

int dispenser_get_sandwich_count(Dispenser* sandwich_dispenser){
    if (sandwich_dispenser == NULL || sandwich_dispenser->item_rack == NULL){
        perror("Dispenser or rack is null");
        return -1;
    }

    return stack_size(sandwich_dispenser->item_rack);
}

bool dispenser_is_sandwich_taken(double prob){
    if (prob == 1){
        return true;
    }else if(prob == 0){
        return false;
    }

    double random = (double) rand() / RAND_MAX;
    return random < prob;
}

int dispenser_load_sandwiches(Dispenser* sandwich_dispenser, int count, float s_price, int s_expires_in, int s_made){
    if (sandwich_dispenser == NULL  || sandwich_dispenser->item_rack == NULL){
        perror("Dispenser/stack is null");
        return -1;
    }
    
    while(
        count-- > 0 && 
        stack_size(sandwich_dispenser->item_rack) < SANDWICH_MAX_TOTAL // Manually limit stack size
    ){
        dispenser_add_item(
            sandwich_dispenser, 
            sandwich_init(s_price, s_expires_in, s_made)
        );
    }

    return dispenser_get_sandwich_count(sandwich_dispenser);

}

int dispenser_unload_sandwiches(Dispenser* sandwich_dispenser){
    if (sandwich_dispenser == NULL  || sandwich_dispenser->item_rack == NULL){
        perror("Dispenser/stack is null");
        return -1;
    }
    int count = stack_size(sandwich_dispenser->item_rack);
    
    stack_clear(sandwich_dispenser->item_rack, free);

    return count;
}

void dispenser_destroy(Dispenser* sandwich_dispenser){
    if (sandwich_dispenser == NULL){
        perror("Dispenser/stack is null");
        return;
    }

    free(sandwich_dispenser);
}

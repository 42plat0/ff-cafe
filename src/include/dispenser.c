#include "dispenser.h"

void dispenser_add_sandwich(Dispenser* sandwich_dispenser, Sandwich* sandwich){
    if (sandwich_dispenser == NULL || sandwich == NULL || sandwich_dispenser->sandwich_rack == NULL){
        perror("Dispenser/sandwich/stack is null");
        return NULL;
    }
    
    push(sandwich_dispenser->sandwich_rack, sandwich); 
}

int dispenser_get_sandwich_count(Dispenser sandwich_dispenser){
    if (sandwich_dispenser == NULL || sandwich_dispenser->sandwich_rack == NULL){
        perror("Dispenser or rack is null");
        return NULL;
    }

    return size(sandwich_dispenser->sandwich_rack);
}

int dispenser_unload_sandwiches(Dispenser* sandwich_dispenser);

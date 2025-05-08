#ifndef DISPENSER_H
#define DISPENSER_H

#include "sandwich.h"
#include "stack.h"

typedef struct Dispenser{
    void* item_rack; 
    int   items_in_total;
    int   items_expired;
    int   items_taken;
} Dispenser;

/**
 * @brief Get pointer to Dispenser struct with Stach initialized
 * 
 * @param  0 if Stack, 1 - queue
 * 
 * @return pointer to Dispenser or null if failed
 */
Dispenser* dispenser_init(int isQueue);

/**
 * @brief  Add sandwich to rack
 * 
 * @param  Pointer to Dispenser struct
 * @param  Pointer to Sandwich struct
 */
void dispenser_add_item(Dispenser* sandwich_dispenser, Sandwich* sandwich);

/**
 * @brief  Remove sandwich from rack
 * 
 * @param  Pointer to Dispenser struct
 *
 * @return Void pointer to data
 */
void* dispenser_remove_item(Dispenser* sandwich_dispenser);

/**
 * @brief  Get current count of sandwiches in rack
 * 
 * @param  Pointer to Dispenser struct
 * 
 * @return Count of elements in Dispenser or NULL if bug
 */
int dispenser_get_sandwich_count(Dispenser* sandwich_dispenser);

/**
 * @brief  Get if sandwich is taken
 * 
 * @param  Probability for item to be taken
 * 
 * @return True if taken ,false otherwise
 */
bool dispenser_is_sandwich_taken(double prob);

/**
 * @brief  Load sandwiches 
 * 
 * @param  Pointer to Dispenser struct
 * @param  int count of sandwiches
 * @param  float sandwich price
 * @param  int sandwich expiration time in seconds
 * @param  int sandwich when it was made time in seconds
 * 
 * @return int number of sandwiches added, -1 if bug
*/
int dispenser_load_sandwiches(
    Dispenser* sandwich_dispenser, 
    int count, 
    float s_price, 
    int s_expires_in,
    int s_made
);

/**
 * @brief  Unload sandwiches if there are any that are expired
 * 
 * @param  Pointer to Dispenser struct
 * 
 * @return Returns number of items unloaded
*/
int dispenser_unload_sandwiches(Dispenser* sandwich_dispenser);

#endif
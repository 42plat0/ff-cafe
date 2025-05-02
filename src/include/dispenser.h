#include "sandwich.h"
#include "stack.h"

typedef struct Dispenser{
    Stack* item_rack; 
} Dispenser;

/**
 * @brief  Add sandwich to rack
 * @param  Pointer to Dispenser struct
 * @param  Pointer to Sandwich struct
 */
void dispenser_add_sandwich(Dispenser* sandwich_dispenser, Sandwich* sandwich);

/**
 * @brief  Get current count of sandwiches in rack
 * @param  Pointer to Dispenser struct
 * @return Count of elements in Dispenser or NULL if bug
 */
int dispenser_get_sandwich_count(Dispenser* sandwich_dispenser);

/** TODO
 * @brief  Unload sandwiches if there are any that are expired
 * @param  Pointer to Dispenser struct
 * @return Returns number of items unloaded
*/
int dispenser_unload_sandwiches(Dispenser* sandwich_dispenser);

/** TODO
 * @brief  Remove sandwich ?????
*/

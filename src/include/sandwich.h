#ifndef SANDWICH_H
#define SANDWICH_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Sandwich{
    float price;
    int expires_in; // Seconds 
} Sandwich;

/**
 * @brief get pointer to sandwich struct
 * @param int price of sandwich
 * @param float expiration time in seconds
 * @return pointer to sandwich or null if failed
 */
Sandwich* init_sandwich(float sandwich_price, int sandwich_exp_in);

/**
 * @brief Check if sandwich expired
 * @param Ptr to sandwich
 * @return true if expired, false otherwise
 */
bool is_expired(Sandwich* sandwich);

/** TODO
 * @brief Decrement expiration time
 * @param ptr to sandwich
 * @param decrement by
 */

/** TODO
 * @brief Unload Sandwich from memory
 */
void destroy_sandwich(Sandwich* s);

#endif
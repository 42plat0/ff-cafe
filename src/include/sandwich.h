#ifndef SANDWICH_H
#define SANDWICH_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Sandwich{
    float price;
    int expires_in; // Seconds 
    int made;       // When was made in day (seconds)
} Sandwich;

/**
 * @brief get pointer to sandwich struct
 * 
 * @param float expiration time in seconds
 * @param int price of sandwich
 * @param int when sandwich was made
 * 
 * @return pointer to sandwich or null if failed
 */
Sandwich* sandwich_init(float sandwich_price, int sandwich_exp_in, int made);

/**
 * @brief Check if sandwich expired
 * 
 * @param Ptr to sandwich
 * @param Current time in seconds
 * 
 * @return true if expired, false otherwise
 */
bool sandwich_is_expired(Sandwich* sandwich, int curr_time);

/**
 * @brief Decrement expiration time
 * 
 * @param ptr to sandwich
 */
// not needed
void sandwich_decrement_expiration_time(Sandwich* sandwich);

/**
 * @brief Unload Sandwich from memory
 * 
 * @param ptr to sandwich
 */
void sandwich_destroy(Sandwich* sandwich);

#endif

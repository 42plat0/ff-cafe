#include <stdbool.h>
#include <stdlib.h>

typedef struct Sandwich{
    float price;
    int expires_in; // Seconds 
} Sandwich;

/**
 * @brief Get pointer to Sandwich struct
 * @param price floating point
 * @param expiration time in seconds
 * @return pointer to Sandwich or null
 */
Sandwich* init_sandwich(float sandwich_price, int sandwich_exp_in);

/**
 * @brief Check if sandwich expired
 * @param ptr to sandwich
 * @return true if expired, false otherwise
 */
bool is_expired(Sandwich* sandwich);

/** TODO
 * @brief Decrement expiration time
 * @param ptr to sandwich
 * @param decrement by
 */

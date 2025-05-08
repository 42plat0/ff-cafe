#ifndef CAFE_H
#define CAFE_H

#include "dispenser.h"
#include <stdbool.h>

typedef struct Cafe{
    Dispenser** dispensers;
    int dispenser_count; 
    int sandwich_prod_time;
    float loss;
    float profit;
}Cafe;

// Builds you a cafe for free
Cafe* cafe_init(int disp_count, int sandwich_prod_time);

// Gets emptiest dispenser ptr to load 
Dispenser* cafe_get_emptiest_dispenser(Cafe* cafe);

// Gets first not empty dispenser ptr to take sandwich from 
Dispenser* cafe_get_non_empty_dispenser(Cafe* cafe);

// Lets you know if its sandwich load time
bool cafe_is_sandwich_load_time(Cafe* cafe, int curr_time);

// While there are sandwiches and next one is expired
// Take sandwiches and either sell or throwaway
void cafe_run_sandwiches(Cafe* cafe, Sandwich* taken_sandwich, int current_time);

// Increases profit amount for cafe
void cafe_increase_profit(Cafe* cafe, float price);

// Increases loss amount for cafe
void cafe_increase_loss(Cafe* cafe, float price);

#endif
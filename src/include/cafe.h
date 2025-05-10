#ifndef CAFE_H
#define CAFE_H

#include "dispenser.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct Cafe{
    Dispenser** dispensers;
    int dispenser_count; 
    int sandwich_prod_time;
    float loss;
    float profit;
    int total_sandwich_made;
}Cafe;

// Builds you a cafe for free
Cafe* cafe_init(int disp_count, int sandwich_prod_time);

// Gets emptiest dispenser ptr to load 
Dispenser* cafe_get_emptiest_dispenser(Cafe* cafe);

// Gets first not empty dispenser ptr to take sandwich from 
Dispenser* cafe_get_non_empty_dispenser(Cafe* cafe);

// Lets you know if its sandwich load time
bool cafe_is_sandwich_load_time(Cafe* cafe, int curr_time);

void cafe_initial_dispenser_load(Cafe* cafe, int prod_count, float price, int fresh_len);

// While there are sandwiches and next one is expired
// Take sandwiches and either sell or throwaway
void cafe_run_sandwiches(Cafe* cafe, int current_time);

// Increases profit amount for cafe
void cafe_increase_profit(Cafe* cafe, float price);

// Increases loss amount for cafe
void cafe_increase_loss(Cafe* cafe, float price);

// Gets leftovers at the end of day
int* cafe_get_leftovers(Cafe* cafe, int end_time);

// Knows how to display stuff that was returned just above
void cafe_display_leftovers(Cafe* cafe, int end_time);

// Show stats after day
void cafe_show_stats(Cafe* cafe);

// Sells cafe for no profit
void cafe_destroy(Cafe* cafe);

#endif
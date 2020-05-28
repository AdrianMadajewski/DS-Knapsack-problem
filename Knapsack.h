#ifndef KNAPSACK_H
#define KNAPSACK_H

#include "Item.h"

#include <vector>	// for std::vector

void knapsackGreedy(std::vector<Item> items, int knapsackCapacity);
void knapsackBrute(std::vector<Item> items, int knapsackCapacity);
void knapsackDynamic(std::vector<Item> items, int knapsackCapacity);

#endif // !KNAPSACK_H

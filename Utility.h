#ifndef UTILITY_H
#define UTILITY_H

#include "Item.h"

#include <vector>	// for std::vector

bool compareByMassUnit(Item first, Item second);
void printResults(int bestValue, int bestWeight, std::vector<int> results);

#endif // !UTILITY_H

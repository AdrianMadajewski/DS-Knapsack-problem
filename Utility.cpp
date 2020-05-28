#include "Utility.h"

#include <iostream>		// for std::cout

bool compareByMassUnit(Item first, Item second) {
	double worthFirst = static_cast<double>(first.value) / first.weight;
	double worthSecond = static_cast<double>(second.value) / second.weight;
	return worthFirst > worthSecond;
}

void printResults(int bestValue, int bestWeight, std::vector<int> inside) {
	std::cout << "Maximum value = " << bestValue << '\n';
	std::cout << "Weight: " << bestWeight << '\n';
	std::cout << "Inside knapsack: ";
	for (const auto& id : inside) {
		std::cout << id + 1 << ' ';
	}
	std::cout << '\n';
}
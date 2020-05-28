#include "Knapsack.h"
#include "Utility.h"

#include <algorithm>	// for std::sort
#include <cmath>		// for std::pow

void knapsackGreedy(std::vector<Item> items, int knapsackCapacity) {
	const int numberOfItems = items.size();
	std::vector<int> inside;

	// Sort items in descending order - O(nlogn)
	std::sort(items.begin(), items.end(), compareByMassUnit);

	int maxWeight = 0;
	int bestValue = 0;

	for (int i = 0; i < numberOfItems; ++i) {
		if (maxWeight + items[i].weight <= knapsackCapacity) {
			maxWeight += items[i].weight;
			bestValue += items[i].value;
			inside.push_back(items[i].id);
		}
	}

	printResults(bestValue, maxWeight, inside);
}

void knapsackBrute(std::vector<Item> items, int knapsackCapacity) {
	const int numberOfItems = items.size();
	int bestValue = 0;
	int maxWeight = 0;
	int solution = 0;

	std::vector<int> inside;

	int permutations = static_cast<int>(std::pow(2, numberOfItems));
	for (int X = 1; X < permutations; ++X) {

		int weightX = 0;
		int valueX = 0;

		for (int itemIndex = 0; itemIndex < numberOfItems; ++itemIndex) {
			if (((X >> itemIndex) & 1) != 1) {
				continue;
			}

			weightX += items[itemIndex].weight;
			valueX += items[itemIndex].value;
		}

		if (weightX <= knapsackCapacity && valueX >= bestValue) {
			bestValue = valueX;
			maxWeight = weightX;
			solution = X;
		}
	}

	// Check which item is in the knapsack
	for (int itemIndex = 0; itemIndex < numberOfItems; ++itemIndex) {
		if (((solution >> itemIndex) & 1) == 1) {
			inside.push_back(itemIndex + 1);
		}
	}
	
	printResults(bestValue, maxWeight, inside);
}

// TODO:
void knapsackDynamic(std::vector<Item> items, int knapsackCapacity) {

}
#include "Knapsack.h"
#include "Utility.h"

#include <algorithm>	// for std::sort
#include <cmath>		// for std::pow

#include <iostream>

void knapsackGreedy(std::vector<Item> items, int knapsackCapacity) {
	const int numberOfItems = items.size();
	std::vector<int> itemsInside;

	// Sort items in descending order - O(nlogn)
	std::sort(items.begin(), items.end(), compareByMassUnit);

	int maxWeight = 0;
	int bestValue = 0;

	for (int i = 0; i < numberOfItems; ++i) {
		if (maxWeight + items[i].weight <= knapsackCapacity) {
			maxWeight += items[i].weight;
			bestValue += items[i].value;
			itemsInside.push_back(items[i].id);
		}
	}

	printResults(bestValue, maxWeight, itemsInside);
}

void knapsackBrute(std::vector<Item> items, int knapsackCapacity) {
	const int numberOfItems = items.size();
	int bestValue = 0;
	int maxWeight = 0;
	int solution = 0;
	std::vector<int> itemsInside;

	int permutations = static_cast<int>(std::pow(2, numberOfItems));
	for (int X = 1; X < permutations; ++X) {

		int weightX = 0;
		int valueX = 0;

		for (int itemIndex = 0; itemIndex < numberOfItems; ++itemIndex) {
			if (((X >> itemIndex) & 1) == 1) {
				weightX += items[itemIndex].weight;
				valueX += items[itemIndex].value;
			}
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
			itemsInside.push_back(itemIndex);
		}
	}
	
	printResults(bestValue, maxWeight, itemsInside);
}

void knapsackDynamic(std::vector<Item> items, const int knapsackCapacity) {
	const int numberOfItems = items.size();
	std::vector<int> itemsInside;

	// DP matrix initialization
	int** DPmatrix = new int* [numberOfItems + 1]{};
	for (int itemIndex = 0; itemIndex <= numberOfItems; ++itemIndex) {
		DPmatrix[itemIndex] = new int[knapsackCapacity + 1]{};
	}
	
	for (int itemIndex = 1; itemIndex <= numberOfItems; ++itemIndex) {
		int value = items[itemIndex - 1].value;
		int weight = items[itemIndex - 1].weight;

		for (int slot = 0; slot <= knapsackCapacity; ++slot) {
			
			if (weight > slot) {
				DPmatrix[itemIndex][slot] = DPmatrix[itemIndex - 1][slot];
			}
			else {
				int previous = DPmatrix[itemIndex - 1][slot];
				int possibleNext = DPmatrix[itemIndex - 1][slot - weight] + value;
				DPmatrix[itemIndex][slot] = std::max(previous, possibleNext);
			}
		}
	}
	
	// printMatrix(DPmatrix, numberOfItems + 1, knapsackCapacity + 1);

	int leftCapacity = knapsackCapacity;
	int bestValue = DPmatrix[numberOfItems][knapsackCapacity];

	// Check which item is in the knapsack
	for (int item = numberOfItems; item > 0; --item) {
		
		if (DPmatrix[item][leftCapacity] == 0) {
			break;
		}

		if (DPmatrix[item][leftCapacity] > DPmatrix[item - 1][leftCapacity]) {
			itemsInside.push_back(item - 1);
			leftCapacity -= items[item - 1].weight;
		}
	}

	int bestWeight = knapsackCapacity - leftCapacity;

	printResults(bestValue, bestWeight, itemsInside);

	// Release allocated memory
	for (int i = 0; i <= numberOfItems; ++i) {
		delete[] DPmatrix[i];
	}
	delete[] DPmatrix;
}


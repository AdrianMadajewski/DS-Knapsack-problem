#include "Utility.h"

#include <iostream>		// for std::cout

bool compareByMassUnit(Item first, Item second) {
	double worthFirst = static_cast<double>(first.value) / first.weight;
	double worthSecond = static_cast<double>(second.value) / second.weight;
	return worthFirst > worthSecond;
}

void printResults(int bestValue, int bestWeight, std::vector<int> itemsInside) {
	std::cout << "Maximum value: " << bestValue << '\n';
	std::cout << "Weight: " << bestWeight << '\n';
	std::cout << "Inside knapsack: ";
	for (const auto& id : itemsInside) {
		std::cout << id + 1 << ' ';
	}
	std::cout << '\n';
}

void printMatrix(int** matrix, int ROWS, int COLS) {
	for (int row = 0; row < ROWS; ++row) {
		for (int col = 0; col < COLS; ++col) {
			std::cout << matrix[row][col] << '\t';
		}
		std::cout << '\n';
	}
}
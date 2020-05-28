#include <iostream>
#include "File.h"
#include "Knapsack.h"

int main()
{
	int knapsackCapacity;
	int numberOfitems;
	auto items = loadDataFromFile("data.txt", knapsackCapacity, numberOfitems);

	std::cout << "-----------KNAPSACK GREEDY-----------" << '\n';
	knapsackGreedy(items, knapsackCapacity);
	std::cout << "-------------------------------------" << '\n';

	std::cout << "-----------KNAPSACK BRUTE------------" << '\n';
	knapsackBrute(items, knapsackCapacity);
	std::cout << "-------------------------------------" << '\n';

	std::cout << "-----------KNAPSACK DYNAMIC----------" << '\n';
	knapsackDynamic(items, knapsackCapacity);
	std::cout << "-------------------------------------" << '\n';

	return 0;
}
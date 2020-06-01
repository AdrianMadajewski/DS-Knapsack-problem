#include <iostream>
#include "File.h"
#include "Knapsack.h"
#include "User.h"

int main()
{
	if (askUser("Enter user data? : 1 = yes, 0 = no")) {
		int knapsackCapacity = getUserInput("Enter knapsack size: ");
		int numberOfItems = getUserInput("Enter number of items: ");
		auto items = getItemsFromUser(numberOfItems);
		
		std::cout << "KNAPSACK GREEDY" << '\n';
		knapsackGreedy(items, knapsackCapacity);
		std::cout << '\n';

		std::cout << "KNAPSACK BRUTE" << '\n';
		knapsackBrute(items, knapsackCapacity);
		std::cout << '\n';

		std::cout << "KNAPSACK DYNAMIC" << '\n';
		knapsackDynamic(items, knapsackCapacity);
		std::cout << '\n';

	}

	if (askUser("Enter file data? : 1 = yes, 0 = no")) {
		std::string filename;
		std::cout << "Enter a filename: ";
		std::cin >> filename;

		// Clear console buffer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		int knapsackCapacity;
		int numberOfItems;
		auto items = loadDataFromFile(filename, knapsackCapacity, numberOfItems);

		std::cout << "KNAPSACK GREEDY" << '\n';
		knapsackGreedy(items, knapsackCapacity);
		std::cout << '\n';

		std::cout << "KNAPSACK BRUTE" << '\n';
		knapsackBrute(items, knapsackCapacity);
		std::cout << '\n';

		std::cout << "KNAPSACK DYNAMIC" << '\n';
		knapsackDynamic(items, knapsackCapacity);
		std::cout << '\n';
	}

	return 0;
}
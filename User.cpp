#include "User.h"
#include "Item.h"

#include <iostream>		// for std::cerr, std::cout
#include <limits>		// for sts::numeric_limits
#include <vector>		// for std::vector

int getUserInput(const std::string& message) {
	if (!message.empty())
		std::cout << message << '\n';

	while (true) {
		int x{};
		std::cin >> x;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Invalid input - please try again." << '\n';
			std::cout << message << '\n';
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (x <= 0) {
				std::cerr << "Invalid input - must be greater than 0" << '\n';
				std::cout << message << '\n';
			}
			else return x;
		}
	}
}

std::vector<Item> getItemsFromUser(int numberOfItems) {

	std::cout << "Enter items: " << '\n';
	std::vector<Item> loadedItems;

	for (int i = 0; i < numberOfItems; ++i) {
		std::cout << "Item index: " << i + 1 << " -> weight = ";
		int weight = getUserInput("");

		std::cout << "Item index: " << i + 1 << " -> value  = ";
		int value = getUserInput("");

		Item it(i, value, weight);
		loadedItems.emplace_back(it);
	}

	return loadedItems;
}

bool askUser(const std::string& message)
{
	if (!message.empty())
		std::cout << message << '\n';

	int x{};

	while (true)
	{
		while (true) {
			
			std::cin >> x;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cerr << "Invalid input - please try again." << '\n';
				std::cout << message << '\n';
			}
			else {
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
		}


		switch (x)
		{
		case 0:
			return false;
		case 1:
			return true;
		default:
			std::cerr << "Invalid input - please try again." << '\n';
			break;
		}
	}
}
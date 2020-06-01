#include "File.h"

#include <iostream>		// for std::cerr, std::cout
#include <fstream>		// for std::ifstream

std::vector<Item> loadDataFromFile(const std::string& filename, int &knapsackSize, int &itemsSize)
{
	if (filename.empty()) {
		std::cerr << "Empty filename - quiting." << '\n';
		std::cin.get();
		exit(1);
	}

	std::ifstream file;
	file.open(filename);

	std::vector<Item> loadedData;

	if (!file.is_open()) {
		std::cerr << "Couldn't find the file. Please restart." << '\n';
		std::cin.get();
		exit(1);
	}
	else {
		std::cout << "Succesfully read from file " << filename << '\n';
		int value{};
		int weight{};

		file >> itemsSize >> knapsackSize;

		if (itemsSize <= 0 || knapsackSize <= 0) {
			std::cerr << "Invalid data - must be greater than 0. - Please restart.";
			std::cin.get();
			exit(1);
		}

		std::cout << "Knapsack size = " << knapsackSize << '\n';
		std::cout << "Items size = " << itemsSize << '\n';
		std::cout << '\n';

		int id = 0;
		while(!file.eof()) {
			file >> weight >> value;

			if (weight <= 0 || value <= 0) {
				std::cerr << "Invalid data - must be greater than 0. - Please restart.";
				std::cin.get();
				exit(1);
			}

			Item it(id, value, weight);
			loadedData.push_back(it);
			id++;
		}

	}

	if (loadedData.size() != itemsSize) {
		std::cerr << "Invalid data - not enough items defined. - Please restart.";
		std::cin.get();
		exit(1);
	}

	file.close();
	return loadedData;
}

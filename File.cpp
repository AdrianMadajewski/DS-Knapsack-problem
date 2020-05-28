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
		for (int i = 0; i < itemsSize; ++i) {
			file >> weight >> value;
			Item it(i, value, weight);
			loadedData.push_back(it);
		}

	}
	file.close();
	return loadedData;
}

#ifndef FILE_H
#define FILE_H

#include "Item.h"
#include <vector>	// for std::vector
#include <string>	// for std::string

std::vector<Item> loadDataFromFile(const std::string& filename, int& knapsackSize, int& itemsSize);

#endif // !FILE_H

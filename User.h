#ifndef USER_H
#define USER_H

#include "Item.h"

#include <string>	// for std::string
#include <vector>	// for std::vector

int getUserInput(const std::string& message = "");
std::vector<Item> getItemsFromUser(int numberOfItems);
bool askUser(const std::string& message = "");

#endif // !USER_H

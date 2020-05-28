#ifndef ITEM_H
#define ITEM_H

struct Item {
	int id;
	int value;
	int weight;

	Item(int id, int _value, int _weight) : id(id), value(_value), weight(_weight) {};
	Item() = default;
};

#endif // !ITEM_H

#ifndef ITEM_H
#define ITEM_H

struct Item {
	int id;
	int value;
	int weight;

	Item(int _id, int _value, int _weight) : id(_id), value(_value), weight(_weight) {};
	Item() = default;
};

#endif // !ITEM_H

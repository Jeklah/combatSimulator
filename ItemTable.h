#pragma once

#include <vector>
#include "item.h"
#include <string>

class ItemTable
{
public:
	ItemTable(void);
	~ItemTable(void);

	int getWeight(int itemID);
	item* getItem(int id);

	void addItem(item* item_);

private:
	std::vector<item*> _items;
};


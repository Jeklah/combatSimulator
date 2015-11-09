#pragma once
#include "ItemTable.h"
#include "item.h"
#include <string>

ItemTable::ItemTable(void) {}

// They are new'ed elsewhere...but who deletes?
ItemTable::~ItemTable(void) {}

int ItemTable::getWeight(int itemID) {
	return _items[itemID]->getWeight();
}

void ItemTable::addItem(item* item_) {
	_items.push_back(item_);
}

item* ItemTable::getItem(int id) {
	item* giveItem = _items[id];
	return giveItem;
}
#include "itemTable.h"

itemTable::itemTable(void) {}
itemTable::~itemTable(void) {}

int itemTable::getWeight(int itemID){
	return _items[itemID]->getWeight();
}

void itemTable::addItem(item* item_){
	_items.push_back(_item);
}

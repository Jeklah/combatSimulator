#pragma once

#include "item.h"
#include <vector>

class itemTable{
	public:
		itemTable(void);
		~itemTable(void);
		
		int getWeight(int itemID);
		void addItem(item* item_);
		
	private:
		std::vector<item*> _items;
};

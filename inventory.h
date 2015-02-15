#pragma once

#include "stdafx.h"
#include "itemTable.h"

#include <iostream>
#include <vector>

class inventory{
	private:
		int gold:
		int size;
		int usedSize;
		int freeSize;
		std::vector<int> invIndex;
		itemTable* itemTable;
	
	public:
		inventory(itemTable* itemTable_, int startingSize_);
		int getGold();
		int getSize();
		int getUsedSize();
		int getFreeSize();	
		void addItem(int itemID);
		void removeItem(int itemID);
};

#pragma once

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "ItemTable.h"
#include <string>
#include "item.h"
#include <Windows.h>

// by the way... .h are where you declare things. .cpp is where you define them, so generally shorter.
//here we just are saying whats going to be in the class inventory and what type.
//the functions are also done here they end in ()
class inventory
{
	private:
		int gold;
		int size;
		int usedSize;
		int freeSize;
		std::vector<int> invIndex;
		ItemTable* itemTable;

	public:
		inventory(ItemTable* itemTable_, int startingSize_);

		int getGold();
		int getSize();
		int getUsedSize();
		int getFreeSize();
		void printItem(std::ostream& stream_, int id_);

		void addItem(int itemID);
		void removeItem(int itemID);
};

#include "stdafx.h"
#include "inventory.h"
#include <iostream>

using namespace std;

inventory::inventory(itemTable* itemTable_, int startingSize) :
	size(startinSize_),
	gold(0),
	usedSize(0),
	freeSize(0),
	invIndex.reserve(size);
	itemTable = itemTable_;
}

//return functions

int inventory::getGold(){
	return gold;
}

int inventory::getSize(){
	return size;
}

int inventory::getUsedSize(){
	return usedSize;
}

int inventory::getFreeSize(){
	return freeSize;
}

void inventory::addItem(int itemID){
	int weight = itemTable->getWeight(itemID);
	if ((usedSize + weight) <= size){
		invIndex.push_back(itemID);
		usedSize++;
		freeSize--;
	}
}

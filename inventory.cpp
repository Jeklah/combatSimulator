#pragma once
#include "stdafx.h"
#include <iostream>
#include "inventory.h"
#include <Windows.h>
#include <string>
#include "item.h"
#include "ItemTable.h"


using namespace std;
//same as the item class, definging the class inventory, although I wasn't quite sure
//how to go about it. I tried array but it didn't work cos you couldn't increase the size
// (i think? while ago now...) and vectors they increase as you put stuff in i think 
//so yeah
inventory::inventory(ItemTable* itemTable_, int startingSize_) : 
	size(startingSize_), 
	gold(0),
	usedSize(0), 
	freeSize(0) {
	invIndex.reserve(size);
    itemTable = itemTable_;
}

//return functions
int inventory::getGold() {
	return gold;
}

int inventory::getSize() {
	return size;
}

int inventory::getUsedSize() {
	return usedSize;
}

//either i was being a retard or i was planning on changing the value of usedSize
//by using a function yet to be made cos you can't define usedSize with values that
//haven't been defined yet at runtime i think. or pointers. i'm not sure.
int inventory::getFreeSize() {
	return freeSize;
}


void inventory::printItem(std::ostream& stream_, int id_) {

	int id = id_;
	int mainSt = itemTable->getItem(id)->getMainStat();
	int offSt = itemTable->getItem(id)->getOffStat();
	int minorSt = itemTable->getItem(id)->getMinorStat();
	string itemName = itemTable->getItem(id)->getName();
	std::string vertSpcPadding = "               ";

	stream_ << "Name      : " << itemName << '\n';
	stream_ << vertSpcPadding << "Id        : " << id << '\n';
	stream_ << vertSpcPadding << "MainStat  : " << mainSt << '\n';
	stream_ << vertSpcPadding << "OffStat   : " << offSt << '\n';
	stream_ << vertSpcPadding << "MinorStat : " << minorSt << '\n';
	stream_ << std::endl;
}


void inventory::addItem(int itemID) {
	int weight = itemTable->getWeight(itemID);
	if ((usedSize + weight) <= size) {
		invIndex.push_back(itemID);
		usedSize++;
		freeSize--;
	}
}




#include "stdafx.h"
#include <iostream>
#ifndef SHOP_H
#define SHOP_H
#include "item.h"
#include "inventory.h"
//Check inventory.h for comments. pretty much the same./ lol this is way ahead of where i am at the moment...disregard for now!
using namespace std;

class shop
{
	private:
		int shopGold;
		inventory bag;
	public:
		shop(int gold, inventory bag);
		int getShopGold();
		void fillBag();
		item sellItem();
		void buyItem();









};
#endif
#ifndef SHOP_H
#define SHOP_H

#include "stdafx.h"
#include "item.h"
#include "inventory.h"
#include <iostream>

using namespace std;

class shop{
	
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

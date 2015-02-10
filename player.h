#pragma once

#include "stdafx.h"
#include "inventory.h"
#include <iostream>

using namespace std;
//Check inventory.h for comments, they are similar here.
class player{
	private:
		int health;
		int intelligence;
		int strength;
		int agility;
		int lvl;
		int xp;
		string name;
		int armour;
		

	public:
		player();
		player(string name, int startStr, int startAgi, int startInt);
		void attack();
		int heal();
		int gainXP();
		int getHP();
		string getName();
		int getInt();
		int getAgi();
		int getStr();
		int getLvl();
		int getXP();
		int getArmour();
		inventory *playersInv;
		void createInv(itemTable* itemsTable_, int invSize_);
		int getInvSize();
};

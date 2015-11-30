#pragma once

#include "stdafx.h"
#include <iostream>
#include "inventory.h"

using namespace std;
//Check inventory.h for comments. pretty much the same.
class player
{
	private:
		string clss;
		int health;
		int intelligence;
		int strength;
		int agility;
		int lvl;
		int xp;
		string name;
		int def;
		int clssID;
		int hit;
		
		
	public:
		player();
		player(string name, int startStr, int startAgi, int startInt);

		int heal();
		int gainXP();
		int getHP();
		string getName();
		int getInt();
		int getAgi();
		int getStr();
		int getLvl();
		int getXP();
		int getDef();
		//playing around with pointers. i can not remember at all at the moment.
		inventory *playersInv;
		void createInv(ItemTable* itemsTable_, int invSize_);
		int getInvSize();
		void setClass(int classChoice);
		void setDef(int classChoice);
		int getClassID();
		int getHit();
		void setHit(int classChoice);
};		

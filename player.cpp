#include "stdafx.h"
#include "player.h"
#include "inventory.h"
#include <iostream>
using namespace std;


//Creating the player. did have more inventory if stronger but it caused problems so
//yeah.
player::player(string name, int startStr, int startAgi, int startInt):
	name(name),
	strength(startStr),
	agility(startAgi),
	intelligence(startInt)
{
	lvl = 0;
	xp = 0;
	health = strength / 2;
	//attackDmg = 0;
	
	/*if (strength > 15)
		playersInventory = new inventory(50);
	else
		playersInventory = new inventory(30);*/

}

int player::getAtt() {
	switch (clssID) {
		case 1:
		{
			return (strength / 2) + 3;
		}
		break;
		case 2:
		{
			return (agility/ 2) + 3;
		}
		break;
		case 3:
		{
			return (intelligence / 2) + 3;
		}
		break;
		default:
			break;
	}
}

int player::heal()
{
	cout << "\n I'm healing, watch my back!";
	return (intelligence /2) +3;
}

int player::gainXP()
{
	return (lvl /10);
}

string player::getName()
{
	return name;
}

int player::getHP()
{
	return health;
}

int player::getInt()
{
	return intelligence;
}

int player::getAgi()
{
	return agility;
}

int player::getStr()
{
	return strength;
}

int player::getLvl()
{
	return lvl;
}

int player::getDef()
{
	return def;
}

int player::getInvSize()
{
	return playersInv->getSize();
}

void player::createInv(ItemTable* itemsTable_, int invSize_)
{
	playersInv = new inventory(itemsTable_, invSize_);
}

void player::setClass(int classChoice) {
	switch (classChoice) {
		case 1:
		{
			clss = "Warrior";
			clssID = 1;
		}
		break;
		case 2:
		{
			clss = "Ranger";
			clssID = 2;
		}
		break;
		case 3:
		{
			clss = "Wizard";
			clssID = 3;
		}
		break;
	}
		
}

int player::getClassID() {
	return clssID;
}




























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
	
	/*if (strength > 15)
		playersInventory = new inventory(50);
	else
		playersInventory = new inventory(30);*/

}

void player::attack()
{
	cout << "\nI'm attacking! Rawwwr. I do " << (strength * 2) /2 << endl;
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

int player::getArmour()
{
	return armour;
}

int player::getInvSize()
{
	return playersInv->getSize();
}

void player::createInv(ItemTable* itemsTable_, int invSize_)
{
	playersInv = new inventory(itemsTable_, invSize_);
}






























#include "stdafx.h"
#include "player.h"
#include "inventory.h"

#include <iostream>

using namespace std;

//Creating the player.

player::player(string name, int startStr, int startAgi, int startInt):
	name(name),
	strength(startStr),
	agility(startAgi),
	intelligence(startInt)
{
	lvl = 0;
	xp = 0;
}

void player::attack(){
	count << "\nI'm attacking! To War! I do " << (strength * 2) / 2 endl;
}

int player::heal(){
	cout << "\nI'm healing, cover me!";
	return (intelligence /2) +3;
}

int player::gainXP(){
	return (lvl + 1) / 5;
}

string player::getName(){
	return name;
}

int player::getHP(){
	return health;
}

int player::getInt(){
	return intelligence;
}

int player::getAgi(){
	return agility;
}

int player::getStr{
	return strength;
}

int player::getLvl(){
	return lvl;
}

int player::getArmour(){
	return armour;
}

int player::getInvSize(){
	return playersInv->getSize();
}

void player::createInv(itemTable* itemsTable_, int invSize_){
	playersInv = new inventory(itemsTable_, invSize_);
}	







#include "stdafx.h"
#include "item.h"

#include <iostream>

using nmaespace std;

item::item(string name, int id, int weight, int mainStat, int offStat, int minorStat);
	name(name),
	id(id),
	weight(weight),
	mainStat(mainStat),
	offStat(offStat),
	minorStat(minorStat)
{
}

string item::getName(){
	return name;
}

int item::getWeight(){
	return weight;
}

int item::getMainStat(){
	return mainStat;
}

int item::getOffStat(){
	return offStat;
}

int item::getMinorStat(){
	return minorStat;
}

int item::getID(){
	return id;
}

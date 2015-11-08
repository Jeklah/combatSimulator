#pragma once
#include "stdafx.h"
#include <iostream>
#include "item.h"
#include <string>
using namespace std;
//Creating the item class to have some stuff to add to the inventory objects.
//Defining the stats from parameters and the function return values.
item::item(string name, int id, int weight, int mainStat, int offStat, int minorStat):
	name(name),
	id(id),
	weight(weight),
	mainStat(mainStat),
	offStat(offStat),
	minorStat(minorStat)
{
}

string item::getName()
{
	return name;
}

int item::getWeight()
{
	return weight;
}

int item::getMainStat()
{
	return mainStat;
}

int item::getOffStat()
{
	return offStat;
}

int item::getMinorStat()
{
	return minorStat;
}

int item::getID()
{
	return id;
}


#include "stdafx.h"

#include <iostream>

#ifndef ITEM_H
#define ITEM_H

using namespace std;

class item{
	private:
		string name;
		int weight;
		int mainStat;
		int offStat;
		int minorStat;
		int id;
		
	public:
		item(string name, int id, int weight, int mainS, int offS, int minS);
		string getName();
		int getWeight();
		int getMainStat();
		int getOffStat();
		int getMinorStat();
		int getID();
};
#endif

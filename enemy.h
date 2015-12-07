#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
#ifndef ENEMY_H
#define ENEMY_H

using namespace std;

class enemy
{
	private:
		string name;
		int str;
		int def;
		int hp;
		int diffclty;
		int enemyID;
		int hit;

	public: //need to make getHit and refactor fight.cpp to use it instead of the mess it does atm.
		enemy(string name, int str, int def, int hp, int diff, int enemyID, int hit);
		string getName();
		int attack(int defence);
		int getHP();
		void defend(int attacker);
		double giveXP();
		int getDiff();
		int getStr();
		int getDef();
		int getHit();
	
};

#endif
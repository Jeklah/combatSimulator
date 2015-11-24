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

	public:
		enemy(string name, int str, int def, int hp, int diff, int enemyID);
		void getName();
		int attack(int defence);
		int getHP();
		void defend(int attacker);
		double giveXP();
	
};






















#endif
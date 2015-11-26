#pragma once
#include <string>
#include "stdafx.h"
#include <iostream>
#include "enemy.h"
#include "player.h"

#ifndef FIGHT_H
#define FIGHT_H

using namespace std;

class fight
{

	public:
		player* defendant;
		enemy* attacker;
		fight(player*, enemy*);
		void beginFight();
		void fighting(int attDmg, int attArmr, int defDmg, int defArmr);
		int defDmg;
		int attDmg;
		int defArmr;
		int attArmr;

};

#endif
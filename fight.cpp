#pragma once
#include "fight.h"
#include <string>
#include "stdlib.h"


fight::fight(player* defendant, enemy* attacker) :
	defendant(defendant),
	attacker(attacker)

{}

void fight::beginFight() {
	system("CLS");
	cout << defendant->getName() << " is about to fight " << attacker->getName();
	attDmg = attacker->attack(defendant->getDef());
	attArmr = attacker->getDef();
	switch (defendant->getClassID())
	{
		case 1:
		{
			defDmg = ((defendant->getStr() / attacker->getDef()) + (attacker->getDiff() / 2) + (defendant->getStr() / 5));
			defArmr = (defendant->getDef() + (defendant->getStr() / 3));
			
		}
		break;
		case 2:
		{
			defDmg = (defendant->getAgi() / attacker->getDef()) + (attacker->getDiff() / 2);
			defArmr = (defendant->getDef() + (defendant->getAgi() / 2));
		}
		break;
		case 3:
		{
			defDmg = (defendant->getInt() / attacker->getDef()) + (attacker->getDiff() / 2);
			defArmr = (defendant->getDef() + (defendant->getInt() / 4));
		}
		break;
		default:
			break;
	}
	
}

void fight::fighting(int attDmg, int attArmr, int defDmg, int defArmr) {
	cout << "\n" << "Let the fighting commence! \n";
	while (defendant->getHP() != 0 | attacker->getHP() != 0) {

	}
}
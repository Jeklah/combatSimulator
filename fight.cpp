#pragma once
#include "fight.h"
#include <string>
#include "stdlib.h"



fight::fight(player* defendant, enemy* attacker) :
	defendant(defendant),
	attacker(attacker)

{
	switch (defendant->getClassID())
	{
		case 1:
		{
			defDmg = defendant->getStr() -(attacker->getDiff() / 2) + (defendant->getStr() + 5);
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
	}
}

void fight::beginFight() {
	system("CLS");
	cout << defendant->getName() << " is about to fight " << attacker->getName();
	attDmg = attacker->attack(defendant->getDef());
	attArmr = attacker->getDef();

	
}

void fight::fighting() {
	int defHP = defendant->getHP();
	int attHP = attacker->getHP();
	int dDmg = getRand(1, defDmg);
	cout << "\n" << "Let the fighting commence! \n";
	while ((attHP > 0) | (defHP > 0)) {
		if (defendant->getAtt() > attacker->getDef()) {
			cout << defendant->getName() << " hit " << attacker->getName() << " for " << (dDmg - attArmr);
			cout << "\nAttack: " << dDmg <<  "\nArmour: " << attArmr << "\nDefStr: " << defendant->getStr() << "\n";
			Sleep(10000);
			attHP = attHP - (dDmg - attArmr);
			cout << attHP;
			if (attHP < 0) {
				cout << "The fight is over!";
				break;
			}
		}
		else {
			cout << defendant->getName() << " missed!";
		}
			
	}
}

int fight::getRand(int rangeMin, int rangeMax)
{
	return (int)floor(rand() / (RAND_MAX + 1.0) * ((rangeMax - rangeMin) + 1) + rangeMin);
}
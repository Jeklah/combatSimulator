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
			defDmg = defendant->getStr() -(attacker->getDiff() / 2) + defendant->getStr();
			defArmr = defendant->getDef() +(defendant->getStr() / 3);

		}
		break;
		case 2:
		{
			defDmg = (defendant->getAgi() / attacker->getDef()) + attacker->getDiff() ;
			defArmr = (defendant->getDef() + (defendant->getAgi() / 2));
		}
		break;
		case 3:
		{
			defDmg = (defendant->getInt() / attacker->getDef()) + (attacker->getDiff() / 2);
			defArmr = (defendant->getDef() + (defendant->getInt() / 3.5));
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

	cout << "\n" << "Let the fighting commence! \n";
	while ((attHP > 0) | (defHP > 0)) {
		int dDmg = getRand(1, defDmg);
		int aDmg = getRand(1, attDmg);
		//defender attacks first
		if (getRand(1, defendant->getHit()) > attacker->getDef()) {
			cout << defendant->getName() << "'s turn!\n";
			if (dDmg - attArmr <= 0) {
				cout << defendant->getName() << " missed!\n";
			}
			else
			{
				cout << defendant->getName() << " hit " << attacker->getName() << " for " << (dDmg - attArmr);
				cout << "\ndefAttack: " << defendant->getHit() << "\nattMaxArmour: " << attacker->getDef() << "\n";
				attHP = attHP - (dDmg - attArmr);
				cout << "defDmg: " << (dDmg - attArmr) << "\n";
				cout << "attacker hp: " << attHP << "\n\n";
				Sleep(5000);
			}
			if (attHP <= 0) {
				cout << "The fight is over!\n" << defendant->getName() + " won the fight";
				break;
			}
		}
		else {
			cout << defendant->getName() << " missed!\n";
			Sleep(3000);
		}
		//attacker attacks second

		if (getRand(1, attacker->getHit()) >  defendant->getDef() ) {
			cout << attacker->getName() << "'s turn!\n";
			if (aDmg <= 0) {
				cout << attacker->getName() << " missed!\n";
			}
			else {
				cout << attacker->getName() << " hit " << defendant->getName() << " for " << aDmg;
				cout << "\nattAttack: " << attDmg << "\ndefMaxArmour: " << defendant->getDef() << "\n";
				defHP = defHP - aDmg;
				cout << "player hp: " << defHP << "\n\n";
				Sleep(5000);
			}
			if (defHP <= 0) {
				cout << "The fight is over!\n" << attacker->getName() + " won the fight";
				break;
			}
		}
		else {
			cout << attacker->getName() << " missed!\n";
			Sleep(3000);
		}

	}
}

int fight::getRand(int rangeMin, int rangeMax)
{
	return (int)floor(rand() / (RAND_MAX + 1.0) * ((rangeMax - rangeMin) + 1) + rangeMin);
}

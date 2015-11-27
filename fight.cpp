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
			defDmg = defendant->getStr();// -(attacker->getDiff() / 2)) + (defendant->getStr() + 5));
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
	//switch (defendant->getClassID())
	//{
	//	case 1:
	//	{
	//		defDmg = defendant->getStr();// -(attacker->getDiff() / 2)) + (defendant->getStr() + 5));
	//		defArmr = (defendant->getDef() + (defendant->getStr() / 3));
	//		
	//	}
	//	break;
	//	case 2:
	//	{
	//		defDmg = (defendant->getAgi() / attacker->getDef()) + (attacker->getDiff() / 2);
	//		defArmr = (defendant->getDef() + (defendant->getAgi() / 2));
	//	}
	//	break;
	//	case 3:
	//	{
	//		defDmg = (defendant->getInt() / attacker->getDef()) + (attacker->getDiff() / 2);
	//		defArmr = (defendant->getDef() + (defendant->getInt() / 4));
	//	}
	//	break;

	//}
	
}

void fight::fighting() {
	int defHP = defendant->getHP();
	int attHP = attacker->getHP();
	cout << "\n" << "Let the fighting commence! \n";
	while ((defHP != 0) | (attHP != 0)) {
		if (defendant->getAtt() > attacker->getDef()) {
			cout << defendant->getName() << " hit " << attacker->getName() << " for " << (defDmg - attArmr);
			cout << "\n" << defDmg <<  "\n" << attArmr << "\n" << defendant->getStr();
			Sleep(10000);
			attHP = attHP - (defDmg - attArmr);
		}
		else {
			cout << defendant->getName() << " missed!";
		}
			
	}
}
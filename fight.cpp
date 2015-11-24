#pragma once
#include "fight.h"
#include <string>


fight::fight(player* defendant, enemy* attacker) :
	defendant(defendant),
	attacker(attacker)

{}

void fight::beginFight() {
	cout << "\n" << defendant->getName() << " is about to fight " << attacker->getName();
	while (defendant->getHP() != 0 | attacker->getHP() != 0) {
	
	}
}
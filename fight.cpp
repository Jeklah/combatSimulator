#pragma once
#include "fight.h"
#include <string>


fight::fight(player* defendant, enemy* attacker) :
	defendant(defendant),
	attacker(attacker)

{}

void fight::beginFight() {
	cout << defendant->getName() << "test";
}
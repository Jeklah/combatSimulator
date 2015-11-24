#pragma once
#include "enemyTable.h"
#include "enemy.h"
#include <string>

enemyTable::enemyTable(void) {}

// They are new'ed elsewhere...but who deletes?
enemyTable::~enemyTable(void) {}

int enemyTable::getHP(int enemyID) {
	return _enemys[enemyID]->getHP();
}

void enemyTable::addEnemy(enemy* enemy_) {
	_enemys.push_back(enemy_);
}

enemy* enemyTable::getEnemy(int id) {
	enemy* giveEnemy = _enemys[id];
	return giveEnemy;
}
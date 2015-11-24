#pragma once

#include <vector>
#include "enemy.h"
#include <string>


class enemyTable
{
public:
	enemyTable(void);
	~enemyTable(void);

	int getHP(int enemyID);
	enemy* getEnemy(int id);

	void addEnemy(enemy* item_);

private:
	std::vector<enemy*> _enemys;
};


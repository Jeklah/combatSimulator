#pragma once
#include "stdafx.h"
#include <iostream>
#include "enemy.h"
#include <string>

using namespace std;

enemy::enemy(string name, int str, int def, int hp, int diff, int enemyID) :
	name(name),
	str(str),
	def(def),
	diffclty(diff),
	hp(hp),
	enemyID(enemyID)
	

{
}

string enemy::getName() {
	return name;
}

int enemy::getHP() {
	return hp;
}

double enemy::giveXP() {
	return diffclty * 0.5;
}

int enemy::attack(int defence) {
	return (str + diffclty) - defence;
}

void enemy::defend(int attacker) {
	if (def == attacker) { cout << "The hit grazed the enemy for 1 dmg"; hp--; }
	if (def > attacker) {
		cout << "The attack was blocked!";
	}
	else {
		cout << "The attack hit sucessfully! It did " << (attacker - diffclty) << " damage!";
	}

}

int enemy::getDiff() {
	return diffclty;
}

int enemy::getStr() {
	return str;
}

int enemy::getDef() {
	return def;
}
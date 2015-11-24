// Combat Simulator.cpp : Defines the entry point for the console application.
//
#pragma once

	
#include "stdafx.h"
#include <iostream>
#include "player.h"
#include "item.h"
#include <Windows.h>
#include <string>
#include <ctime>
#include <cmath>
#include "inventory.h"
#include "globals.h"
#include "stdlib.h"
#include <locale>
#include "enemy.h"
#include "enemyTable.h"



using namespace std;
//spacing to make a box around the welcome screen.

extern const string horiSpcPadding = "                                                   ";
//defining the functions
void welcome();
int quit();
int classChoose();
int getRand(int rangeMin, int rangeMax);
player* createPlayer(int classChoice);
void typeText(string text);
//declaring the function testing creating an item to see if i could add to inv..
item* createTestItem()
{
	string name = "The Great Item of Testing";
	int id = 0;
	int weight = 5;
	int mainStat = 15;
	int offStat = 10;
	int minorStat = 3;

	return new item(name, id, weight, mainStat, offStat, minorStat);
}

enemy* createEnemy() {
	string name = "Imp";
	int str = 2;
	int def = 1;
	int hp = 3;
	int diffclty = 1;
	int ID = 0;

	return new enemy(name, str, def, hp, diffclty, ID);
}
//from now on it all it worked.
int main()
{
	ItemTable itemsTable;
	enemyTable enemysTable;
	string path;
	player* playersChar;
	inventory playersInv(&itemsTable, 30);
	string pathChoice;

	item* testItem = createTestItem();
	itemsTable.addItem(createTestItem());

	enemy* newEnemy = createEnemy();
	enemysTable.addEnemy(newEnemy);

	welcome();  //welcome screen. see welcome declaration

	int classChoice;
	classChoice = classChoose();  //deciding class

	
	playersChar =  createPlayer(classChoice);  //create character of chosen class
	cout <<  vertSpcPadding << "Hello, I am name is " << playersChar->getName() << endl; //check character was created

	playersChar->createInv(&itemsTable, 30);
	cout << vertSpcPadding << "Your bag has " << playersChar->getInvSize() << '\n' <<  endl; //checking stats of inv
	
	;

	//Test code, please don't remove, for future reference.
	//cout << vertSpcPadding << "Test item stats: " << testItem->getMainStat() << endl; //checking item
	
	//typeText("this is a test"); works  //this. is special. this is a nice little function that prints out charaters slowly. its cool.

	testItem = itemsTable.getItem(0);
	
	cout << vertSpcPadding;
	playersInv.addItem(0);
	playersInv.printItem(std::cout, 0);

	cout << vertSpcPadding;
	typeText("Your story begins...");
	Sleep(50);
	system("CLS");
	cout << "\n\n";
	cout << "Your story begins as you find yourself lost in a forest. There are two paths, one leading east with a faint light along it, the other is a dark, black path leading west. \n" << "Which way do you want to go? \n";
	cin >> pathChoice;
	if (pathChoice == "west") {
		cout << "You walk slowly down the gloomy path, feeling your way through the darkness. Eventually you start to see some light ahead, you quicken your pace, but suddenly an imp jumps out!";
	}
	else {
		cout << "You walk eastwards towards the light path, but suddenly something rustles in the bushes and jumps out! It's an Imp!";
	}
	
	quit();
}


//declaring creating the character 
player* createPlayer(int classChoice)
{
	string name;
	int startingStr;
	int startingAgi;
	int startingInt;
	player *playersChar;

	srand((long)time(0));
	switch (classChoice)  //choosing the class
	{
		case 1:
			{
				cout << vertSpcPadding <<  "You have chosen the Warrior.\n";
				cout << vertSpcPadding << "What would you like to call your character?: ";
				cin >> name;
				playersChar = new player(name, startingStr = getRand(7,20),startingAgi = getRand(1,10),startingInt = getRand(1, 10));
				return playersChar;
			}
			break;
		case 2:
			{
				cout << vertSpcPadding << "You chose the Ranger.\n";
				cout << vertSpcPadding << "What would you like to call your character?: ";
				cin >> name;
				playersChar = new player(name, startingStr = getRand(1,10),startingAgi = getRand(7,20),startingInt = getRand(1, 10));
				return playersChar;
			}
			break;
		case 3:
			{
				cout << vertSpcPadding << "You chose the Wizard.\n";
				cout << vertSpcPadding << "What would you like to call your character?: ";
				cin >> name;
				playersChar = new player(name, startingStr = getRand(1,10),startingAgi = getRand(1,10),startingInt = getRand(7, 20));
				return playersChar;
			}
			break;
	}
	
}

string directionChoice(int pathChoice) {
	string path;
	//writr a function to turn words into numbers for switch cases. switch accepts ints not strings.
	
	switch (pathChoice) {
		case 1:{
		
			cout << "The east path. It looks dark and gloomy.";
			cin >> path;
			return path;
		}
		break;
		case 2: {
			cout << "The west path. There is a dark path but a faint light at the end...";
			cin >> path;
			return path;
		}
	}

}


//asking input for the choice of class
int classChoose()
{
	int choice;

	cout << vertSpcPadding << "Please pick a class:\n";
	cout << vertSpcPadding << "1. Warrior.\n";
	cout << vertSpcPadding << "2. Ranger.\n";
	cout << vertSpcPadding << "3. Wizard.\n";
	cout << horiSpcPadding << endl;
	cout << vertSpcPadding << "You choose: ";
	cin >> choice;
	return choice;
}
//welcome screen. i was proud of this. it made a nice box with a welcome screen. used earlier defined strings.
void welcome()
{
	string horiBlkPadding = "||                                               ||";
	
	for (int i = 0; i < 3; i++)
		cout << horiSpcPadding << endl;
	cout << vertSpcPadding << "===================================================" << endl;
	for (int i =0; i < 2; i++)
		cout << vertSpcPadding << horiBlkPadding << endl;
	cout << vertSpcPadding << "||        Welcome to the combat simulator!       ||" << endl;
	cout << vertSpcPadding << horiBlkPadding << endl;;
	cout << vertSpcPadding << "||              Please pick a class              ||" << endl;
	cout << vertSpcPadding << horiBlkPadding << endl;
	cout << vertSpcPadding << "===================================================" << endl;
	cout << endl;
}

//the nice little function that prints out strings character by character.
void typeText(string text)
{
	for (size_t i = 0; i < text.size(); ++i)
	{
		cout << text[i] << flush;
		Sleep(100);
		
	}
}

//random numbers for random stats for the character stats.
int getRand(int rangeMin, int rangeMax)
{
    return (int)floor(rand() / (RAND_MAX + 1.0) * ((rangeMax - rangeMin) + 1) + rangeMin);
}

int quit()
{
	cout << "\n";
	getchar();
	system("pause");
	return 0;
}
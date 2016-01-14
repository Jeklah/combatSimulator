// Combat Simulator.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include <iostream>
#include "player.h"
#include "item.h"
#include <Windows.h>
#include <string>
#include "inventory.h"
#include "globals.h"
#include "stdlib.h"
#include <locale>
#include "enemy.h"
#include "enemyTable.h"
#include "fight.h"
#include "utf8.h"

using namespace std;

//defining the functions
void welcome();
void howi();
int quit();
int classChoose();
player* createPlayer(int classChoice);

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

enemy* createEnemy(string _name, int _str, int _def, int _hp, int _diff, int _id, int _hit) {
	return new enemy(_name, _str, _def, _hp, _diff, _id, _hit);
}
//entry point
int main()
{
	ItemTable itemsTable;
	enemyTable enemysTable;
	string path;
	player* playersChar;
	inventory playersInv(&itemsTable, 30);
	string pathChoice;
	fight* newFight;
	string rdy;
	item* testItem = createTestItem();
	itemsTable.addItem(createTestItem());

	enemy* imp = createEnemy("Imp", 3, 1, 10, 1, 0, 4);
	enemy* ogre = createEnemy("Ogre", 7, 4, 15, 3, 1, 6);
	enemysTable.addEnemy(ogre);
	enemysTable.addEnemy(imp);

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
	ogre = enemysTable.getEnemy(0);
	imp = enemysTable.getEnemy(1);

	ogre->getHP();
	imp->getHP();
 

	cout << vertSpcPadding;
	playersInv.addItem(0);
	playersInv.printItem(std::cout, 0);

	cout << vertSpcPadding;
	cout << "Are you sitting comfortably? y/n ";
	cin >> rdy;
	
	if (rdy == "y") {
		cout << vertSpcPadding << "Then I'll begin.\n";
		Sleep(20);
		cout << vertSpcPadding;
		typeText("Your story begins...");
		Sleep(1800);
		system("CLS");
		cout << header << "\n";
		cout << "Your story begins as you find yourself lost in a forest. There are two paths, one leading east with a faint light along it, the other is a dark, black path leading west. \n" << "Which way do you want to go? \n";
		cin >> pathChoice;
		if (pathChoice == "west") {
			cout << "You walk slowly down the gloomy path, feeling your way through the darkness. Eventually you start to see some light ahead, you quicken your pace, but suddenly an " << imp->getName() << " jumps out!";
			Sleep(3000);
			newFight = new fight(playersChar, imp);
			newFight->beginFight();
			newFight->fighting();
		}
		else {
			cout << "You walk eastwards towards the light path, but suddenly you hear large stomping. It's an " << ogre->getName() << "!";
			Sleep(3000);
			newFight = new fight(playersChar, ogre);
			newFight->beginFight();
			newFight->fighting();
		}

		quit();
	}

	
}


//declaring creating the character 
player* createPlayer(int classChoice)
{
	string name;
	int startingStr;
	int startingAgi;
	int startingInt;
	player *playersChar;
	int cid;

	srand((long)time(0));
	switch (classChoice)  //choosing the class
	{
		case 1:
			{
				cout << vertSpcPadding << "You have chosen the Warrior.\n";
				cout << vertSpcPadding << "What would you like to call your character?: ";
				cin >> name;
				if (name == "howi" | name == "howard" | name == "Howi" | name == "Howard") { howi(); };
				playersChar = new player(name, startingStr = getRand(4,7),startingAgi = getRand(2,7),startingInt = getRand(1, 3));
				playersChar->setClass(classChoice);
				cid = playersChar->getClassID();
				playersChar->setDef(cid);
				playersChar->setHit(cid);
				return playersChar;
			}
			break;
		case 2:
			{
				cout << vertSpcPadding << "You chose the Ranger.\n";
				cout << vertSpcPadding << "What would you like to call your character?: ";
				cin >> name;
				if (name == "howi" | name == "howard" | name == "Howi" | name == "Howard") { howi(); };
				playersChar = new player(name, startingStr = getRand(2,7),startingAgi = getRand(3,7),startingInt = getRand(1, 5));
				playersChar->setClass(classChoice);
				cid = playersChar->getClassID();
				playersChar->setDef(cid);
				playersChar->setHit(cid);
				return playersChar;
			}
			break;
		case 3:
			{
				cout << vertSpcPadding << "You chose the Wizard.\n";
				cout << vertSpcPadding << "What would you like to call your character?: ";
				cin >> name;
				if (name == "howi" | name == "howard" | name == "Howi" | name == "Howard") { howi(); };
				playersChar = new player(name, startingStr = getRand(1,3),startingAgi = getRand(1,6),startingInt = getRand(5, 10));
				playersChar->setClass(classChoice);
				cid = playersChar->getClassID();
				playersChar->setDef(cid);
				playersChar->setHit(cid);
				return playersChar;
			}
			break;
	}
	
}

string directionChoice(int pathChoice) {
	string path;
		switch (pathChoice) {
		case 1:
		{
			cout << "The east path. It looks dark and gloomy.";
			cin >> path;
			return path;
		}
		break;
		case 2:
		{
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
	cout << vertSpcPadding << welcomeBorder << endl;
	for (int i =0; i < 2; i++)
		cout << vertSpcPadding << horiBlkPadding << endl;
	cout << vertSpcPadding << "||        Welcome to the combat simulator!       ||" << endl;
	cout << vertSpcPadding << horiBlkPadding << endl;;
	cout << vertSpcPadding << "||              Please pick a class              ||" << endl;
	cout << vertSpcPadding << horiBlkPadding << endl;
	cout << vertSpcPadding << welcomeBorder << endl;
	cout << endl;
}




int quit()
{
	cout << "\n";
	getchar();
	system("pause");
	return 0;
}

//thought: entire howi() can be refactored into 3 for loops. 1 for the amount of lines, 1 for the amount of characters per line, and 1 for the seq of chars.
//make an array to store the character seq per line.
void howi() {
	system("CLS");
	char buffer[] = { 176, 223, 220, 177 };
	string output;
	typeText("   master    "); 
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[2]);
	};
	for (int i = 0; i < 8; i++) {
		typeText(output = (char)buffer[1]);
	};
	for (int i = 0; i < 7; i++) {
		typeText(output = (char)buffer[2]);
	};
	for (int i = 0; i < 9; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");

	typeText("    trole    ");
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 12; i++) {
		typeText(output = (char)buffer[3]);
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[1]);
	};
	typeText(output = (char)buffer[2]);
	for (int i = 0; i < 6; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("  wow         \n");

	typeText("   2015      "); 
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 6; i++) {
		typeText(output = (char)buffer[3]);
	};
	for (int i = 0; i < 8; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[3]);
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");

	typeText("             ");
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 6; i++) {
		typeText(output = (char)buffer[0]);
	};
	typeText(output = (char)buffer[2]);
	for (int i = 0; i < 2; i++) {
		std::cout << (unsigned char)219;
	}
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[2]);
	};
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");

	typeText("             ");
	typeText(output = (char)buffer[0]);
	typeText(output = (char)buffer[2]);
	typeText(output = (char)buffer[1]);
	typeText(output = (char)buffer[3]);
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[2]);
	};
	typeText(output = (char)buffer[3]);
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[1]);
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 2; i++) {
		std::cout << (unsigned char)219;
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("     bruh        \n");

	typeText("             ");
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[0]);
	typeText(output = (char)buffer[3]);
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[3]);
	typeText(output = (char)buffer[2]);
	typeText(output = (char)buffer[0]);
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[2]);
	};
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 8; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[3]);
	};
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");

	typeText(" pussys      ");
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[0]);
	typeText(output = (char)buffer[3]);
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	typeText(output = (char)buffer[1]);
	typeText(output = (char)buffer[2]);
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[0]);
	};
	typeText(output = (char)buffer[2]);
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[1]);
	};
	typeText(output = (char)buffer[2]);
	typeText(output = (char)buffer[3]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[0]);
	}; typeText("                 \n");

	typeText("             ");
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[0]);
	typeText(output = (char)buffer[1]);
	typeText(output = (char)buffer[2]);
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[2]);
	typeText(output = (char)buffer[0]);

	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	typeText(output = (char)buffer[0]);
	typeText(output = (char)buffer[1]);
	typeText(output = (char)buffer[0]);
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[1]);
	};
	typeText(output = (char)buffer[0]);
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");

	typeText("             ");
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};
	typeText(output = (char)buffer[1]);
	typeText(output = (char)buffer[2]);
	typeText(output = (char)buffer[1]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[1]);
	};
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[2]);
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[1]);
	};
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 2; i++) {
		std::cout << (unsigned char)219;
	};
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");

	typeText("        wow  ");
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 2; i++) {
		std::cout << (unsigned char)219;
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[0]);
	};
	typeText(output = (char)buffer[1]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[2]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[2]);
	for (int i = 0; i < 4; i++) {
		std::cout << (unsigned char)219;
	};
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 5; i++ ) {
		typeText(output = (char)buffer[0]);
	};	typeText("         noob    \n");

	typeText("             ");
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[1]);
	};
	typeText(output = (char)buffer[2]);
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 6; i++) {
		std::cout << (unsigned char)219;
	};
	typeText(output = (char)buffer[0]);
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");  

	typeText("   fknpssy   ");
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[0]);
	};
	typeText(output = (char)buffer[1]);
	typeText(output = (char)buffer[2]);
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[1]);
	};
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[2]);
	};
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[2]);
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[2]);
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[2]);
	std::cout << (unsigned char)219;
	typeText(output = (char)buffer[2]);
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");

	typeText("             ");
	for (int i = 0; i < 7; i++) {
		typeText(output = (char)buffer[0]);
	};
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	typeText(output = (char)buffer[0]);
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[3]);
	};
	for (int i = 0; i < 10; i++) {
		typeText(output = (char)buffer[0]);
	};
	typeText(output = (char)buffer[3]);
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");

	typeText("             "); 
	for (int i = 0; i < 9; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[1]);
	};
	for (int i = 0; i < 2; i++) {
		typeText(output = (char)buffer[2]);
	};
	typeText(output = (char)buffer[0]);
	for (int i = 0; i < 11; i++) {
		typeText(output = (char)buffer[3]);
	};
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 3; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("  such troles    \n");

	typeText("             ");
	for (int i = 0; i < 13; i++) {
		typeText(output = (char)buffer[0]);
	};
	typeText(output = (char)buffer[1]);
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[2]);
	};
	for (int i = 0; i < 9; i++) {
		typeText(output = (char)buffer[0]);
	};
	std::cout << (unsigned char)219;
	for (int i = 0; i < 4; i++) {
		typeText(output = (char)buffer[0]);
	};	typeText("                 \n");

	typeText("             ");
	for (int i = 0; i < 19; i++) {
		typeText(output = (char)buffer[0]);
	};
	for (int i = 0; i < 9; i++) {
		typeText(output = (char)buffer[1]);
	};
	for (int i = 0; i < 5; i++) {
		typeText(output = (char)buffer[0]);
	}; typeText("                 \n");
	
	Sleep(1000);
	//system("CLS");
}
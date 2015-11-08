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



using namespace std;
//spacing to make a box around the welcome screen.

extern const string horiSpcPadding = "                                                   ";
//defining the functions
void welcome();
int quit();
int classChoose();
int getRand(int rangeMin, int rangeMax);
player* createCharacter(int classChoice);
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
//from now on it all it worked.
int main()
{
	ItemTable itemsTable;
	itemsTable.addItem(createTestItem());

	welcome();  //welcome screen. see welcome declaration

	int classChoice;
	classChoice = classChoose();  //deciding class

	player* playersChar;
	playersChar =  createCharacter(classChoice);  //create character of chosen class
	cout <<  vertSpcPadding << "Hello, I am name is " << playersChar->getName() << endl; //check character was created

	playersChar->createInv(&itemsTable, 30);
	cout << vertSpcPadding << "Your bag has " << playersChar->getInvSize() << '\n' <<  endl; //checking stats of inv
	
	item* testItem = createTestItem();

	//Test code, please don't remove, for future reference.
	//cout << vertSpcPadding << "Test item stats: " << testItem->getMainStat() << endl; //checking item
	
	//typeText("this is a test"); works  //this. is special. this is a nice little function that prints out charaters slowly. its cool.

	testItem = itemsTable.getItem(0);
	inventory playersInv(&itemsTable, 30);
	cout << vertSpcPadding;
	playersInv.addItem(0);
	playersInv.printItem(std::cout, 0);

	cout << vertSpcPadding;
	quit();
}


//declaring creating the character 
player* createCharacter(int classChoice)
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
				cout << vertSpcPadding <<  "What would you like to call your character?: ";
				cin >> name;
				playersChar = new player(name, startingStr = getRand(1,10),startingAgi = getRand(1,10),startingInt = getRand(7, 20));
				return playersChar;
			}
			break;
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
	cout << vertSpcPadding << "You choice: ";
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
		Sleep(300);
	}
}

//random numbers for random stats for the character stats.
int getRand(int rangeMin, int rangeMax)
{
    return (int)floor(rand() / (RAND_MAX + 1.0) * ((rangeMax - rangeMin) + 1) + rangeMin);
}



// This doesn't quit...it waits for user input!
int quit()
{
	//cout << "Press any key to quit" << endl;
	getchar();
	system("pause");
	return 0;
	
	/*char f;
	cin >> f;
	if (f == f)
		return 0;
	
	return 0;*/
}
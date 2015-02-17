//Combat Simulator.cpp 
//
//Written by Arthur Bowers
//Defining the entry point for the console application.
//This is written purely for experimental purposes.


#include "stdafx.h"
#include "player.h"
#include "item.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>
#include <cmaths>

//This is where it all happens
using namespace std;

//Spacing to make the welcome screen

string vertSpcPadding = "               ";
string horiSpcPadding = "                                                   ";

//Defining the functions

void welcome();
void typeText(string text);
int quit();
int classChoose();
int getRand(int rangeMin, int rangeMax);
player* createCharacter(int, classChoice);

//Test function to see if i could add items to inventory
item* createTestItem(){
	string name = "The Great Item of Testing";
	int id =0;
	int weight = 5;
	int mainStat = 15;
	int offStat = 10;
	int minorStat = 3;
	
	return new item(name, id, weight, mainStat, offStat, minorStat);
}

int main(){
	itemTable itemsTable;
	itemsTable.addItem(createTestItem());

	welcome(); //Welcome screen. 

	int classChoice;
	classChoice = classChoice(); //Deciding class choice
	
	player *playersChar;
	playersChar = createCharacter(classChoice); //create character of chosen class
	cout << vertSpcPadding << "Hello, my name is " << playersChar->getName() << endl; //Checking char was created
	
	playersChar->createInv(&itemsTable, 30);
	cout << vertSpcPadding << "My bag has " << playersChar->getInvSize() << endl; //Checking stats of inv

	item* testItem = createTestItem();
	cout << vertSpcPadding << "Test item stats: " << testItem->getMainStat() << endl; //Checking item

	//typeText("this is a test"); this works. nice little function that prints out characters slowly. cool.
	
	inventory player(&itemTable, 30);
	playersInv.addItem(0);

	quit();
}

player* createCharacter(int classChoice){
	string name;
	int startingStr;
	int startingAgi;
	int startingInt;
	player *playersChar;
	
	srand((long)time(0));
	switch (classChoice) //Choosing the class
	{
		case 1:
		{
			cout << vertSpcPadding << "You have chosen the Warrior.\n";
			cout << vertSpcPadding << "What would you like to call your character?: ";
			cin >> name;
			playersChar = new player(name, startingStr = getRand(7,20), startingAgi = getRand(1,10), startingInt = getRand(1,10));
			return playersChar;
		}
		break;
		case 2:
		{
			cout << vertSpcPadding << "You chose the Ranger.\n";
			cout << vertSpcPadding << "What would you like to call your character?: ";
			cin >> name;
			playersChar = new player(name, startingStr = getRand(1,10), startingAgi = getRand(7,20), startingInt = getRand(1,10));
			return playersChar;
		}
		break;
		case 3:
		{
			cout << vertSpcPadding << "You chose the Wizard.\n";
			cout << vertSpcPadding << "What would you like to call your character?: ";
			cin >> name;
			playersChar = new player(name, startingStr = getRand(1,10), startingAgi = getRand(1,10), startingInt = getRand(7,20));
			return playersChar;
		}
		break;
	}
}

//asking input for the choice of class

int classChoice(){
	int choice;
	
	cout << vertSpcPadding << "Please pick a class:\n";
	cout << vertSpcPadding << "1. Warrior.\n";
	cout << vertSpcPadding << "2. Ranger.\n";
	cout << vertSpcPadding << "3. Wizard.\n";
	cout << horiSpcPadding << endl;
	cout << vertSpcPadding << "Your choice: ";
	cin  >> choice;
	return choice;
}

//Welcome screen.

void welcome(){
	string horiBlkPadding = "||                                               ||";
	string equalsPadding  = "===================================================";
	
	for (int i=0; i<3; i++)
		cout << horiSpcPadding << endl;
	cout << vertSpcPadding << equalsPadding << endl;
	for (int i=0; i<2; i++)
		cout << vertSpcPadding << horiBlkPadding << endl;
	cout << vertSpcPadding << "||        Welcome to the combat simulator!       ||" << endl;
	cout << vertSpcPadding << horiBlkPadding << endl;
	cout << vertSpcPadding << "||              Please pick a class              ||" << endl;
	cout << vertSpcPadding << horiBlkPadding << endl;
	cout << vertSpcPadding << equalsPadding << endl;
	cout << endl;
}

void typeText(string text){
	for (size_t i=0; i<text.size(); i++){
		cout << text[i] << flush;
		Sleep(300);
	}
}














































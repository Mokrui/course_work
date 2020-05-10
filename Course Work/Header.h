#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<conio.h>
#include<stdio.h> 
#include<windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<time.h> 
#include<fstream>
#include<list>

using namespace std;

struct timeData {
	int firstNum;

	int indexDay;

	int indexDM;
	string nameDay;

	int indexM;
	string nameM;
	int amountD;

	int year;

	int tomD;
	int tomM;
	int tomY;
};

const int maxSize = 31;
struct habit {
	string title;

	bool shedule[7];
	bool isActive;

	int nMonth;
	int amountD;
	bool progressArr[maxSize];
};
struct Search {
	string title;
	bool isActive;
};

struct Event {
	string title;

	int day;
	int mon;
	int year;

	bool isDone;
};


//***//
void init();
void save();
void gotoxy(int x, int y);
void moveUp(int* currentPos, int first, int last);
void moveDown(int* currentPos, int first, int last);
void switchMove(int key, bool wasd, bool sides, int* currentPos, int first, int last);
void getTime();
void bye();
void showMenu(const int size, string* menu, int posX);

void mainMenu();

//***//
//=========================-HABITS MENU-=================================

void showShedule(int currentX, string* dw, bool* doDw);
void showDate(int day, int mon, int year, int maxInM, int x);
void mainMenuDate();
void showEvents();

void mChoose(bool choose);
void newHabit();
void newGoal();
void newEvent();


void trackHabit();
//=======================================================================


//=========================-TODAY GOALS-=================================
void changeStatus(int* sFrom, int* sTo, string*& From, string*& To, int* posX, bool* posY);
void todayGoals(bool choose);
//=======================================================================
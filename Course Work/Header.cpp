#include "Header.h"
time_t rawtime;
struct tm* timeinfo;
HANDLE Mokryi = GetStdHandle(STD_OUTPUT_HANDLE);

timeData timeObj;
int countH = 0;
int countE = 0;
int countG = 0;
habit* habits = new habit[countH];
Event* events = new Event[countE];
Event* goals = new Event[countG];
int posXmm = 1;

//**
void save() {
	//Save Habits
	ofstream foutHabits;
	foutHabits.open("habits.txt");

	bool is_open_write = foutHabits.is_open();
	if (!is_open_write) {
		system("cls");
		cout << "Eror: your file -habits.txt- can't open";
	}
	else {
		for (int i = 0; i < countH; i++) {
			foutHabits << habits[i].title << ";";
			for (int j = 0; j < 7; j++) {
				foutHabits << habits[i].shedule[j];
			}
			foutHabits << ";" << habits[i].isActive << ";" << habits[i].nMonth << ";";
			for (int j = 0; j < timeObj.amountD; j++) {
				foutHabits << habits[i].progressArr[j];
			}
			if (i != countH - 1) foutHabits << endl;
		}
	}
	foutHabits.close();


	//Save Events
	ofstream foutEvents;
	foutEvents.open("events.txt");
	is_open_write = foutEvents.is_open();


	if (!is_open_write) {
		system("cls");
		cout << "Eror: your file -events.txt- can't open";
	}
	else {
		for (int i = 0; i < countE; i++) {
			foutEvents << events[i].title << ";" << events[i].day << ";" << events[i].mon << ";" << events[i].year << ";" << events[i].isDone;
			if (i != countE - 1) foutEvents << endl;
		}
	}
	foutEvents.close();


	//Save Goals
	//Save Events
	ofstream foutGoals;
	foutGoals.open("goals.txt");
	is_open_write = foutGoals.is_open();


	if (!is_open_write) {
		system("cls");
		cout << "Eror: your file -goals.txt- can't open";
	}
	else {
		for (int i = 0; i < countG; i++) {
			foutGoals << goals[i].title << ";" << goals[i].day << ";" << goals[i].mon << ";" << goals[i].year << ";" << goals[i].isDone;
			if (i != countG - 1) foutGoals << endl;
		}
	}
	foutGoals.close();

}
void init() {
	ifstream finHabits;
	finHabits.open("habits.txt", fstream::app);
	bool is_open_read = finHabits.is_open();

	int cStr = 0;
	bool isClear = false;
	string s;

	if (is_open_read == true) {


		while (!finHabits.eof()) {
			getline(finHabits, s);
			if (cStr == 0 && s == "") isClear = true;
			else if (isClear == false)cStr++;
		}

		countH = cStr;
		habits = new habit[countH];
		cStr = 0;
	}

	if (!isClear) {
		ifstream fin;
		fin.open("habits.txt", fstream::app);
		while (!fin.eof()) {
			//////

			getline(fin, s);
			string ss;
			stringstream a(s);
			for (int i = 0; i < 5; i++) {
				getline(a, ss, ';');

				switch (i) {
				case 0: habits[cStr].title = ss;
					break;
				case 1:
					for (int i = 0; i < 7; i++) {
						if (ss[i] == '1') {
							habits[cStr].shedule[i] = true;
						}
						else habits[cStr].shedule[i] = false;
					}
					break;
				case 2:
					habits[cStr].isActive = atoi(ss.c_str());
					break;
				case 3:
					if (atoi(ss.c_str()) != timeObj.indexM) {
						for (int i = 0; i < timeObj.amountD; i++) {
							habits[cStr].progressArr[i] = false;
						}
						i++;
					}
					habits[cStr].nMonth = timeObj.indexM;
					break;
				case 4:
					for (int i = 0; i < timeObj.amountD; i++) {
						if (ss[i] == '1') {
							habits[cStr].progressArr[i] = true;
						}
						else habits[cStr].progressArr[i] = false;
					}
					break;
				}

				////
			}
			cStr++;
		}
	}

	//Init Events
	ifstream finEvents;
	finEvents.open("events.txt", fstream::app);
	is_open_read = finEvents.is_open();

	isClear = false;
	cStr = 0;

	if (is_open_read == true) {
		while (!finEvents.eof()) {
			getline(finEvents, s);
			if (cStr == 0 && s == "") isClear = true;
			else if (isClear == false)cStr++;
		}
	}
	countE = cStr;
	events = new Event[countE];
	cStr = 0;

	if (!isClear) {
		ifstream finEvents;
		finEvents.open("events.txt", fstream::app);

		while (!finEvents.eof()) {
			getline(finEvents, s);
			string ss;
			stringstream a(s);
			int integer = 0;

			for (int i = 0; i < 5; i++) {
				getline(a, ss, ';');

				if (i > 0) integer = atoi(ss.c_str());

				switch (i) {
				case 0:
					events[cStr].title = ss;
					break;
				case 1:
					events[cStr].day = integer;
					break;
				case 2:
					events[cStr].mon = integer;
					break;
				case 3:
					events[cStr].year = integer;
					break;
				case 4:
					events[cStr].isDone = integer;
					break;
				}
			}
			cStr++;
		}
	}



	//Init Goals
	ifstream finGoals;
	finGoals.open("goals.txt", fstream::app);
	is_open_read = finGoals.is_open();

	isClear = false;
	cStr = 0;

	if (is_open_read == true) {
		while (!finGoals.eof()) {
			getline(finGoals, s);
			if (cStr == 0 && s == "") isClear = true;
			else if (isClear == false)cStr++;
		}
	}
	countG = cStr;
	goals = new Event[countG];
	cStr = 0;

	if (!isClear) {
		ifstream finGoals;
		finGoals.open("goals.txt", fstream::app);

		while (!finGoals.eof()) {
			getline(finGoals, s);
			string ss;
			stringstream a(s);
			int integer = 0;

			for (int i = 0; i < 5; i++) {
				getline(a, ss, ';');

				if (i > 0) integer = atoi(ss.c_str());

				switch (i) {
				case 0:
					goals[cStr].title = ss;
					break;
				case 1:
					goals[cStr].day = integer;
					break;
				case 2:
					goals[cStr].mon = integer;
					break;
				case 3:
					goals[cStr].year = integer;
					break;
				case 4:
					goals[cStr].isDone = integer;
					break;
				}
			}
			cStr++;
		}
	}
}

void gotoxy(int x, int y) {
	COORD p = { x,y };  // STANDART 80/20
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void moveUp(int* currentPos, int first, int last) {
	if (*currentPos == first) {
		*currentPos = last;
	}
	else {
		*currentPos -= 1;
	}
}
void moveDown(int* currentPos, int first, int last) {
	if (*currentPos == last) {
		*currentPos = first;
	}
	else {
		*currentPos += 1;
	}
}
void switchMove(int key, bool wasd, bool sides, int* currentPos, int first, int last) {

	if (wasd == true) {
		if (key == 119 || key == 72) {
			moveUp(currentPos, first, last);
		}
		else if (key == 115 || key == 80) {
			moveDown(currentPos, first, last);
		}
		else if (key == 97 || key == 75) {
			switch (sides) {
			case true:
				moveDown(currentPos, first, last);
				break;
			}
		}
		else if (key == 100 || key == 77) {
			switch (sides) {
			case true:
				moveUp(currentPos, first, last);
				break;
			}
		}
	}
	else {
		switch (key) {
		case 80:
			moveDown(currentPos, first, last);
			break;
		case 77:
			switch (sides) {
			case true:
				moveUp(currentPos, first, last);
				break;
			}
			break;
		case 75:
			switch (sides) {
			case true:
				moveDown(currentPos, first, last);
				break;
			}
			break;
		case 72:
			moveUp(currentPos, first, last);
			break;
		}
	}
}
void getTime() {
	time(&rawtime);
	timeinfo = localtime(&rawtime);

	int dayM = timeinfo->tm_mday;
	timeObj.indexDM = dayM - 1;
	int dayW = timeinfo->tm_wday;

	//cout << dayM << endl;
	//cout << dayW << endl << endl;

	timeObj.firstNum = 0;

	switch (dayW) {
	case 1:
		timeObj.nameDay = "Monday";
		break;
	case 2:
		timeObj.nameDay = "Tuesday";
		break;
	case 3:
		timeObj.nameDay = "Wednesday";
		break;
	case 4:
		timeObj.nameDay = "Thursday";
		break;
	case 5:
		timeObj.nameDay = "Friday";
		break;
	case 6:
		timeObj.nameDay = "Saturday";
		break;
	case 0:
		timeObj.nameDay = "Sunday";
		break;
	}
	if (dayW == 0) dayW = 7;

	if (dayM < 7) {	
		for (int i = dayM; i != 1; i--) {
			dayW--;
			dayM--;

			if (dayM == 1) {
				if (dayW < 0) {
					dayW = 7 - abs(dayW);
				}
				else if (dayW == 0) {
					dayW = 7;
				}
				timeObj.firstNum = dayW;
				//cout << firstNum << endl;
			}
		}
	}
	else {
		int i = dayM;
		while (i % 7 != 0) {
			i--;
			dayW--;
		}
		if (i % 7 == 0) {
			timeObj.firstNum = dayW + 1;
			if (timeObj.firstNum > 7) timeObj.firstNum %= 7;
			//cout << firstNum << endl;
		}
	}
	/*for (int i = dayM; i % 7 != 0; ) {
		i--;
		dayW--;
		if (i % 7 == 0) {
			timeObj.firstNum = dayW + 1;
			if (timeObj.firstNum > 7) timeObj.firstNum %= 7;
			cout << firstNum << endl;
		}
	}*/

	//≤Õƒ≈ — ƒÕﬂ “»∆Õﬂ ¬ «Ã≤ÕÕ”
	timeObj.indexDay = timeinfo->tm_wday;
	if (timeObj.indexDay == 0) {
		timeObj.indexDay = 6;
	}
	else timeObj.indexDay -= 1;


	//MONTHS + YEAR(vusok/nevusok)
	timeObj.indexM = timeinfo->tm_mon + 1;
	switch (timeObj.indexM) {
	case 1: timeObj.nameM = "Jan";
		break;
	case 2: timeObj.nameM = "Feb";
		break;
	case 3: timeObj.nameM = "Mar";
		break;
	case 4: timeObj.nameM = "Apr";
		break;
	case 5: timeObj.nameM = "May";
		break;
	case 6: timeObj.nameM = "Jun";
		break;
	case 7: timeObj.nameM = "Jul";
		break;
	case 8: timeObj.nameM = "Aug";
		break;
	case 9: timeObj.nameM = "Sep";
		break;
	case 10: timeObj.nameM = "Oct";
		break;
	case 11: timeObj.nameM = "Nov";
		break;
	case 12: timeObj.nameM = "Dec";
		break;
	}

	timeObj.year = timeinfo->tm_year + 1900;

	if (timeObj.indexM == 1 || timeObj.indexM == 3 || timeObj.indexM == 5 || timeObj.indexM == 7 || timeObj.indexM == 8 || timeObj.indexM == 10 || timeObj.indexM == 12) timeObj.amountD = 31;
	else if (timeObj.indexM == 2 && (timeObj.year % 4 == 0 && (timeObj.year % 400 == 0 || timeObj.year % 100 != 0))) timeObj.amountD = 29;
	else if (timeObj.indexM == 4 || timeObj.indexM == 6 || timeObj.indexM == 9 || timeObj.indexM == 11) timeObj.amountD = 30;
	else timeObj.amountD = 28;


	//TOMORROW
	if (timeObj.indexM == 12 && (timeObj.indexDM + 1 == timeObj.amountD)) {
		timeObj.tomY = timeObj.year + 1;
		timeObj.tomM = 1;
		timeObj.tomD = 1;
	}
	else if (timeObj.indexDM + 1 == timeObj.amountD) {
		timeObj.tomY = timeObj.year;
		timeObj.tomM = timeObj.indexM + 1;
		timeObj.tomD = 1;
	}
	else {
		timeObj.tomY = timeObj.year;
		timeObj.tomM = timeObj.indexM;
		timeObj.tomD = timeObj.indexDM + 2;
	}
}

//---------ÏÂÌ˛¯Í≥
void bye() {
	system("cls");
	gotoxy(58, 14);
	cout << "Bye";
	SetConsoleTextAttribute(Mokryi, 0);
	exit(0);
}
void showMenu(const int size, string* menu, int posX) {
	//int y = (30 / 2) - (size / 2);
	int y = 6;
	for (int i = 0; i < size; i++) {
		//int x = 60 - (menu[i].length() / 2);
		int x = 10;
		gotoxy(x, y);
		if (posX == i) SetConsoleTextAttribute(Mokryi, 2);
		cout << menu[i];
		SetConsoleTextAttribute(Mokryi, 7);
		y += 2;
	}
	gotoxy(60, 30);
}
void rectangle(int x, int y, bool size) {
	int symb = 0;
	if (size == false) symb = 21;
	else {
		symb = 45;
	}
	int nextLine = symb / 3;


	int index = 0;
	gotoxy(x, y);


	for (int i = 0; i < symb; i++) {
		index++;
		cout << char(219);
		if (index == nextLine) {
			index = 0;
			y++;
			gotoxy(x, y);
		}
	}
}
void mainMenuDate() {
	gotoxy(10, 27);
	SetConsoleTextAttribute(Mokryi, 4);
	cout << timeObj.nameDay;
	SetConsoleTextAttribute(Mokryi, 8);
	cout << ", the ";

	SetConsoleTextAttribute(Mokryi, 4);
	cout << timeObj.indexDM + 1 << " ";
	SetConsoleTextAttribute(Mokryi, 8);
	cout << "of ";

	SetConsoleTextAttribute(Mokryi, 4);
	cout << timeObj.nameM;

	SetConsoleTextAttribute(Mokryi, 7);
	gotoxy(12, 29);
	if (timeObj.indexDM + 1 < 10)cout << "0";
	cout << timeObj.indexDM + 1 << ".";
	if (timeObj.indexM < 10) cout << "0";
	cout << timeObj.indexM << "." << timeObj.year;
}
void showEvents() {
	int countTod = 0;
	int countTom = 0;

	for (int i = 0; i < countE; i++) {
		if ((events[i].day == timeObj.indexDM + 1) && events[i].mon == timeObj.indexM && events[i].year == timeObj.year) countTod++;
		else if (events[i].day == timeObj.tomD && events[i].mon == timeObj.tomM && events[i].year == timeObj.tomY) countTom++;
	}
	string* eventsTod = new string[countTod];
	string* eventsTom = new string[countTom];

	countTod = 0;
	countTom = 0;

	for (int i = 0; i < countE; i++) {
		if ((events[i].day == timeObj.indexDM + 1) && events[i].mon == timeObj.indexM && events[i].year == timeObj.year) {
			eventsTod[countTod] = events[i].title;
			countTod++;
		}
	}

	for (int i = 0; i < countE; i++) {
		if (events[i].day == timeObj.tomD && events[i].mon == timeObj.tomM && events[i].year == timeObj.tomY) {
			eventsTom[countTom] = events[i].title;
			countTom++;
		}
	}


	int x = 80;
	int y = 6;
	if (countTod > 0) {
		gotoxy(x + 10, y);
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "Today:";
		SetConsoleTextAttribute(Mokryi, 7);
		y++;
		for (int i = 0; i < countTod; i++) {
			y++;
			gotoxy(x, y);
			cout << eventsTod[i];
		}
		y += 4;
	}
	if (countTom > 0) {
		gotoxy(x + 7, y);
		SetConsoleTextAttribute(Mokryi, 8);
		cout << "Tomorrow:";
		SetConsoleTextAttribute(Mokryi, 7);
		y++;
		for (int i = 0; i < countTom; i++) {
			y++;
			gotoxy(x, y);
			cout << eventsTom[i];
		}
	}

}

void mChoose(bool choose) {
	system("cls");
	int currentX = 0;

	do {
		SetConsoleTextAttribute(Mokryi, 2);

		if (choose == false) {
			gotoxy(58, 1);
			cout << "New";
		}
		else {
			gotoxy(57, 1);
			cout << "Track";
		}

		if (currentX == 0) SetConsoleTextAttribute(Mokryi, 7);
		else SetConsoleTextAttribute(Mokryi, 8);
		rectangle(30, 4, true);

		if (currentX == 1) SetConsoleTextAttribute(Mokryi, 7);
		else SetConsoleTextAttribute(Mokryi, 8);
		rectangle(30, 8, true);

		if (currentX == 2) SetConsoleTextAttribute(Mokryi, 7);
		else SetConsoleTextAttribute(Mokryi, 8);
		rectangle(30, 12, true);




		if (currentX == 0) SetConsoleTextAttribute(Mokryi, 112);
		else SetConsoleTextAttribute(Mokryi, 128);
		if (!choose) {
			gotoxy(32, 5);
			cout << "Add Routine";
		}
		else {
			gotoxy(32, 5);
			cout << "Track Habit";
		}



		if (currentX == 1) SetConsoleTextAttribute(Mokryi, 112);
		else SetConsoleTextAttribute(Mokryi, 128);
		if (!choose) {
			gotoxy(33, 9);
			cout << "Add  Goal";
		}
		else {
			gotoxy(32, 9);
			cout << "Track Goals";
		}



		if (currentX == 2) SetConsoleTextAttribute(Mokryi, 112);
		else SetConsoleTextAttribute(Mokryi, 128);
		if (!choose) {
			gotoxy(33, 13);
			cout << "Add Event";
		}
		else {
			gotoxy(32, 13);
			cout << "Track Events";
		}



		gotoxy(74, 5);
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "-ESC-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " to Main Menu";


		gotoxy(74, 7);
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "-Enter-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " to choose";

		gotoxy(74, 9);
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "-W/S-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " to move";

		gotoxy(49, 28);
		SetConsoleTextAttribute(Mokryi, 4);
		if (!choose) {
			cout << "Choose what's new...";
		}
		else {
			cout << "Choose what to track";
		}
		SetConsoleTextAttribute(Mokryi, 7);

		int key = _getch();
		if (key == 72 || key == 119) {
			if (currentX != 0) currentX -= 1;
		}

		else if (key == 80 || key == 115) {
			if (currentX != 2) currentX += 1;
		}

		else if (key == 13 || key == 32) {
			switch (currentX) {
			case 0:

				if (!choose)  newHabit();

				else  trackHabit();

				break;
			case 1:

				if (!choose) newGoal();

				else

					break;
			case 2:

				if (!choose) newEvent();

				else

					break;
			}
		}
		else if (key == 27) mainMenu();

	} while (true);
}
void mainMenu() {
	bool showPss = false;
	const int size = 5;
	string mainMenu[size] = { "CREATE","TRACK ROUTINES","GOALS", "ROUTINES" , "EXIT", };
	do {
		system("cls");

		showMenu(size, mainMenu, posXmm);
		mainMenuDate();
		showEvents();

		int key = _getch();
		switchMove(key, true, false, &posXmm, 0, 4);
		if (key == 32 || key == 13) {
			switch (posXmm) {
			case 0:
				mChoose(false);
				break;
			case 1:
				trackHabit();
				break;
			case 2:
				todayGoals(true);
			case 3:
				todayGoals(false);
				break;
			case 4:
				bye();
				break;
			}
		}
		else if (key == 27) bye();
		else if (key == 9) showPss = !showPss;
	} while (true);
}
//***

//=========================-NEW MENU-=================================
//ÕŒ¬¿ œ–»¬»◊ ¿

void showShedule(int currentX, string* dw, bool* doDw) {
	gotoxy(20, 10);
	for (int i = 0; i < 7; i++) {
		if (currentX == i) SetConsoleTextAttribute(Mokryi, 2);
		cout << dw[i] << "   ";
		SetConsoleTextAttribute(Mokryi, 7);
	}


	gotoxy(20, 11);
	cout << "__   __   __   __   __   __   __\n";

	gotoxy(20, 12);
	for (int i = 0; i < 7; i++) {
		if (doDw[i] == true) SetConsoleTextAttribute(Mokryi, 2);
		cout << char(219) << char(219) << "   ";
		SetConsoleTextAttribute(Mokryi, 7);
	}
}
void showDate(int day, int mon, int year, int maxInM, int x) {
	int amountD = 0;

	if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) amountD = 31;
	else if (mon == 2 && (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))) amountD = 29;
	else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) amountD = 30;
	else amountD = 28;

	gotoxy(x, 14);
	if (day < 10) {
		cout << "0";
		cout << day;
	}
	else cout << day;
	//

	gotoxy(x + 7, 14);
	if (mon < 10) {
		cout << "0";
		cout << mon;
	}
	else cout << mon;
	//

	gotoxy(x + 13, 14);
	cout << year;
	//

	//œÓ¯ÎËÈ/¡Û‰Û˘ËÈ
	SetConsoleTextAttribute(Mokryi, 8);

	gotoxy(x, 16);
	if (day == 1) cout << amountD;
	else if (day - 1 < 10) {
		cout << "0";
		cout << day - 1;
	}
	else cout << day - 1;

	gotoxy(x, 12);
	if (day + 1 < 10) {
		cout << "0";
		cout << day + 1;
	}
	else if (day == maxInM) cout << "01";
	else cout << day + 1;
	//

	gotoxy(x + 7, 16);
	if (mon == 1) cout << "12";
	else if (mon - 1 < 10) {
		cout << "0";
		cout << mon - 1;
	}
	else cout << mon - 1;

	gotoxy(x + 7, 12);
	if (mon + 1 < 10) {
		cout << "0";
		cout << mon + 1;
	}
	else if (mon == 12) cout << "01";
	else cout << mon + 1;
	//


	gotoxy(x + 13, 16);
	if (year == 1)cout << "----";
	else cout << year - 1 << endl;

	gotoxy(x + 13, 12);
	cout << year + 1 << endl;
}

void newHabit() {
	int round = 1;
	bool isSet = true;
	bool isExist = false;

	string choose[2] = { "Goal","Habit" };

	string dw[7] = { "Mo", "Tu", "We", "Th", "Fr", "Sa", "Su" };
	bool doDw[7] = { false, false, false, false, false, false, false };

	int currentX = -1;

	string title = "";

	habit newHabit;

	do {
		system("cls");

		SetConsoleTextAttribute(Mokryi, 2);
		if (isExist == true) {
			gotoxy(47, 23);
			cout << "SUCH TITLE ALREADY EXISTS";
		}
		else if (isSet == false) {
			gotoxy(53, 23);
			cout << "AT LEAST 1 DAY";
		}


		gotoxy(58, 1);
		SetConsoleTextAttribute(Mokryi, 2);
		cout << "NEW";
		SetConsoleTextAttribute(Mokryi, 7);


		gotoxy(20, 5);
		cout << "TITLE: ";

		gotoxy(28, 5);
		cout << title;

		if (round == 1) {
			gotoxy(48, 28);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-ESC-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to abort NEW HABIT";
		}
		else if (round == 2 || round == 3) {
			gotoxy(51, 28);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-ESC-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to step BACK";
		}



		if (round == 1) {
			currentX = -1;
			showShedule(currentX, dw, doDw);

			gotoxy(74, 5);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "-Enter- ";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << "to save the Title";

			gotoxy(53, 25);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "type title...";
			SetConsoleTextAttribute(Mokryi, 7);

			int key = _getch();
			if (key == 8 && title.length() > 0) {
				title.pop_back();
			}
			else if (key == 27) {
				mChoose(false);
			}
			else if (key == 13) {

				while (title[title.length() - 1] == ' ') {
					title.pop_back();
				}

				isExist = false;
				for (int i = 0; i < countH; i++) {
					if (habits[i].title == title) isExist = true;
				}

				if (title.length() > 0 && isExist == false) round = 2;
			}
			else if (key != 224 && key != 59 && key != 9 && key != 13 && key != 8 && title.length() < 32) {
				title += char(key);
			}
		}
		else if (round == 2) {
			if (currentX == -1) currentX = 0;


			gotoxy(74, 4);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-A/D-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to moove";

			gotoxy(74, 6);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-Enter-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " save the schedule";

			gotoxy(74, 8);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-Backspace-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to color whole shedule";

			gotoxy(74, 10);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-Space-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to color selected day";

			gotoxy(74, 12);
			cout << "__";
			gotoxy(74, 13);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << char(219) << char(219);
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " = u want";

			gotoxy(74, 14);
			cout << "__";
			gotoxy(74, 15);
			cout << char(219) << char(219);
			cout << " = u don't want";

			showShedule(currentX, dw, doDw);

			gotoxy(36, 25);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "choose which days you want to repeat the habit";



			int key = _getch();
			switch (key) {
			case 97:
				moveUp(&currentX, 0, 6);
				break;
			case 100:
				moveDown(&currentX, 0, 6);
				break;
			case 75:
				moveUp(&currentX, 0, 6);
				break;
			case 77:
				moveDown(&currentX, 0, 6);
				break;
			case 13:

				isSet = false;
				for (int i = 0; i < 7; i++) {
					if (doDw[i] == true) isSet = true;
				}

				if (isSet == true) round = 3;

				break;
			case 32:
				doDw[currentX] = !doDw[currentX];
				break;
			case 8:
				//œÓÍ‡ÒËÚ¸ ‚Ò≥ ‚ Ó‰ËÌ ˆ‚ÂÚ

				doDw[0] = !doDw[0];
				for (int i = 1; i < 7; i++) {
					doDw[i] = doDw[0];
				}

				break;
			case 27:
				round--;
				break;
			}

		}
		else if (round == 3) {
			currentX = -1;
			showShedule(currentX, dw, doDw);

			gotoxy(74, 5);
			cout << "Press ";
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "-Enter- ";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << "to save";

			gotoxy(43, 25);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "New habit sucessfully setted up...";
			SetConsoleTextAttribute(Mokryi, 7);

			int key = _getch();
			if (key == 13) {

				newHabit.title = title;
				newHabit.isActive = true;
				newHabit.nMonth = timeObj.indexM;

				for (int i = 0; i < 7; i++) {
					newHabit.shedule[i] = doDw[i];
				}
				for (int i = 0; i < maxSize; i++) {
					newHabit.progressArr[i] = false;
				}


				///////////	—Œ’–¿Õ»“‹ ƒ¿ÕÕ≤ ¬ Ã¿—≤¬ « œ–»¬»◊ ¿Ã»
				habit* temp = new habit[countH];
				for (int i = 0; i < countH; i++) {
					temp[i] = habits[i];
				}

				countH++;
				habits = new habit[countH];

				for (int i = 0; i < countH - 1; i++) {
					habits[i] = temp[i];
				}
				habits[countH - 1] = newHabit;

				delete[]temp;
				///////////

				system("cls");

				//cout << title << endl;

				gotoxy(47, 14);
				SetConsoleTextAttribute(Mokryi, 2);
				cout << "Try NOT to miss your Goal";
				gotoxy(47, 16);
				SetConsoleTextAttribute(Mokryi, 4);
				cout << "Press any key to continue";
				SetConsoleTextAttribute(Mokryi, 0);
				system("pause");
				SetConsoleTextAttribute(Mokryi, 7);

				save();
				mainMenu();
			}
			else if (key == 27) round--;
		}
	} while (true);
}
void newEvent() {
	int day = timeObj.indexDM + 1;
	int mon = timeObj.indexM;
	int year = timeObj.year;

	int maxInM = 0;
	int round = 1;
	bool isExist = false;
	string title = "";
	Event newEvent;

	int currentY = -1;

	bool SettedCorrectly = true;
	bool isExistE = false;
	do {
		system("cls");

		SetConsoleTextAttribute(Mokryi, 2);
		gotoxy(55, 1);
		cout << "New Event";
		SetConsoleTextAttribute(Mokryi, 7);

		gotoxy(20, 5);
		cout << "TITLE: ";

		gotoxy(27, 5);
		cout << title;


		//NOTE
		if (round == 1) {
			gotoxy(48, 28);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-ESC-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to abort NEW EVENT";

			SetConsoleTextAttribute(Mokryi, 4);
			if (isExistE == true) {
				gotoxy(47, 24);
				cout << "SUCH EVENT ALREADY EXISTS";
			}
		}
		else if (round == 2 || round == 3) {
			gotoxy(51, 28);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-ESC-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to step BACK";
		}

		gotoxy(74, 5);
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "-Enter- ";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << "to save + next step";

		if (round == 2) {
			gotoxy(74, 7);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "-W/S- ";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << "to change date";

			gotoxy(74, 9);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "-A/D- ";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << "to change dd/mm/yy";

			SetConsoleTextAttribute(Mokryi, 4);
			gotoxy(74, 11);
			cout << "-TAB-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to set today's date";
		}


		SetConsoleTextAttribute(Mokryi, 4);
		if (SettedCorrectly == false) {
			gotoxy(48, 24);
			cout << "You setted  passed date!";
		}


		SetConsoleTextAttribute(Mokryi, 2);
		gotoxy(53, 26);
		if (round == 1) {
			cout << "Type title...";
		}
		if (round == 2) {
			cout << "Choose date...";
		}
		SetConsoleTextAttribute(Mokryi, 7);

		//DATE
		gotoxy(20, 10);
		if (currentY == 0) SetConsoleTextAttribute(Mokryi, 4);
		cout << "dd";
		SetConsoleTextAttribute(Mokryi, 7);

		gotoxy(27, 10);
		if (currentY == 1) SetConsoleTextAttribute(Mokryi, 4);
		cout << "mm";
		SetConsoleTextAttribute(Mokryi, 7);

		gotoxy(34, 10);
		if (currentY == 2) SetConsoleTextAttribute(Mokryi, 4);
		cout << "yy";
		SetConsoleTextAttribute(Mokryi, 7);

		showDate(day, mon, year, maxInM, 20);
		//


		if (round == 1) {
			currentY = -1;

			int key = _getch();
			if (key == 8 && title.length() > 0) {
				title.pop_back();
			}
			else if (key == 27) {
				mChoose(false);
			}
			else if (key == 13 && title != "") {
				isExistE = false;

				while (title[title.length() - 1] == ' ') {
					title.pop_back();
				}

				for (int i = 0; i < countE; i++) {
					if (title == events[i].title) isExistE = true;
				}

				if (!isExistE) {
					round += 1;
					currentY = 0;
				}
			}
			else if (key != 224 && key != 59 && key != 9 && key != 13 && key != 8 && title.length() < 32) {
				title += char(key);
			}
		}
		else if (round == 2) {
			if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) maxInM = 31;
			else if (mon == 2 && (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))) maxInM = 29;
			else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) maxInM = 30;
			else if (mon == 2) maxInM = 28;

			if (day > maxInM) day = maxInM;

			int key = _getch();
			if (key == 9) {
				day = timeObj.indexDM + 1;
				mon = timeObj.indexM;
				year = timeObj.year;
			}
			if (key == 27) {
				currentY = -1;
				round -= 1;
			}
			else if (key == 13) {
				SettedCorrectly = false;
				if (year >= timeObj.year) {
					if (year == timeObj.year && mon >= timeObj.indexM) {
						if (mon == timeObj.indexM && day >= timeObj.indexDM + 1) {
							SettedCorrectly = true;
						}
						else if (mon > timeObj.indexM) SettedCorrectly = true;
					}
				}
				else {

				}
				if (SettedCorrectly == true) round += 1;
			}
			else if (key == 119 || key == 72) {
				switch (currentY) {
				case 0:
					if (day == maxInM) day = 1;
					else day++;
					break;
				case 1:
					if (mon == 12) mon = 1;
					else mon++;
					break;
				case 2:
					year++;
					break;
				}
			}
			else if (key == 115 || key == 80) {
				switch (currentY) {
				case 0:
					if (day == 1) day = maxInM;
					else day--;
					break;
				case 1:
					if (mon == 1) mon = 12;
					else mon--;
					break;
				case 2:
					if (year == 1) year = timeObj.year;
					year--;
					break;
				}
			}
			else if (currentY < 2 && (key == 77 || key == 100)) currentY++;
			else if (currentY > 0 && (key == 75 || key == 97)) currentY--;
		}
		else {
			currentY = -1;
			int key = _getch();
			if (key == 27) {
				currentY = 0;
				round -= 1;
			}
			else if (key == 13) {
				newEvent.title = title;
				newEvent.day = day;
				newEvent.mon = mon;
				newEvent.year = year;
				newEvent.isDone = false;

				countE++;
				Event* temp = new Event[countE - 1];
				for (int i = 0; i < countE - 1; i++) {
					temp[i] = events[i];
				}
				events = new Event[countE];

				for (int i = 0; i < countE - 1; i++) {
					events[i] = temp[i];
				}

				events[countE - 1] = newEvent;

				//DODAT'
				system("cls");

				//cout << title << endl;

				gotoxy(47, 14);
				SetConsoleTextAttribute(Mokryi, 2);
				cout << "Successfully added new event";
				gotoxy(47, 16);
				SetConsoleTextAttribute(Mokryi, 4);
				cout << " Press any key to continue";
				SetConsoleTextAttribute(Mokryi, 0);
				system("pause");
				SetConsoleTextAttribute(Mokryi, 7);

				save();
				mainMenu();
			}
		}
	} while (true);

}
void newGoal() {
	int day = timeObj.indexDM + 1;
	int mon = timeObj.indexM;
	int year = timeObj.year;

	int maxInM = 0;
	int round = 1;
	bool isExist = false;
	string title = "";
	Event newGoal;

	int currentY = -1;
	bool currentChoose = true;

	bool SettedCorrectly = true;
	bool isExistE = false;


	do {
		system("cls");

		SetConsoleTextAttribute(Mokryi, 2);
		gotoxy(55, 1);
		cout << "New Goal";
		SetConsoleTextAttribute(Mokryi, 7);

		gotoxy(20, 5);
		cout << "TITLE: ";

		gotoxy(27, 5);
		cout << title;

		gotoxy(74, 5);
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "-Enter- ";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << "to save + next step";

		gotoxy(20, 8);
		if (round != 2) SetConsoleTextAttribute(Mokryi, 8);
		else SetConsoleTextAttribute(Mokryi, 7);
		cout << "With deadline ?";

		if (currentChoose == true) SetConsoleTextAttribute(Mokryi, 2);
		else SetConsoleTextAttribute(Mokryi, 8);
		rectangle(20, 10, false);

		if (!currentChoose) SetConsoleTextAttribute(Mokryi, 4);
		else SetConsoleTextAttribute(Mokryi, 8);
		rectangle(20, 14, false);

		if (currentChoose == true) SetConsoleTextAttribute(Mokryi, 32);
		else SetConsoleTextAttribute(Mokryi, 128);
		gotoxy(22, 11);
		cout << "Yes";

		if (currentChoose == false) SetConsoleTextAttribute(Mokryi, 64);
		else SetConsoleTextAttribute(Mokryi, 128);
		gotoxy(22, 15);
		cout << "No.";

		//NOTE
		if (round == 1) {
			gotoxy(48, 28);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-ESC-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to abort NEW GOAL";

			SetConsoleTextAttribute(Mokryi, 4);
			if (isExistE == true) {
				gotoxy(47, 24);
				cout << "SUCH GOAL ALREADY EXISTS";
			}

			/*if (round == 1 && currentChoose == true) {
				currentY = -1;
				gotoxy(31, 10);
				if (currentY == 0) SetConsoleTextAttribute(Mokryi, 4);
				cout << "dd";
				SetConsoleTextAttribute(Mokryi, 7);

				gotoxy(38, 10);
				if (currentY == 1) SetConsoleTextAttribute(Mokryi, 4);
				cout << "mm";
				SetConsoleTextAttribute(Mokryi, 7);

				gotoxy(45, 10);
				if (currentY == 2) SetConsoleTextAttribute(Mokryi, 4);
				cout << "yy";
				SetConsoleTextAttribute(Mokryi, 7);

				showDate(day, mon, year, maxInM, 31);
			}*/
		}
		else if (round == 2 || round == 3 || round == 4) {
			gotoxy(51, 28);
			SetConsoleTextAttribute(Mokryi, 2);
			cout << "-ESC-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to step BACK";
		}

		if (round == 2) {
			gotoxy(74, 7);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "-W/S- ";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << "to move";
		}
		else if (round == 3) {

			//DATE
			gotoxy(31, 10);
			if (currentY == 0) SetConsoleTextAttribute(Mokryi, 4);
			cout << "dd";
			SetConsoleTextAttribute(Mokryi, 7);

			gotoxy(38, 10);
			if (currentY == 1) SetConsoleTextAttribute(Mokryi, 4);
			cout << "mm";
			SetConsoleTextAttribute(Mokryi, 7);

			gotoxy(45, 10);
			if (currentY == 2) SetConsoleTextAttribute(Mokryi, 4);
			cout << "yy";
			SetConsoleTextAttribute(Mokryi, 7);

			showDate(day, mon, year, maxInM, 31);
			//

			gotoxy(74, 7);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "-W/S- ";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << "to change date";

			gotoxy(74, 9);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "-A/D- ";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << "to change dd/mm/yy";

			SetConsoleTextAttribute(Mokryi, 4);
			gotoxy(74, 11);
			cout << "-TAB-";
			SetConsoleTextAttribute(Mokryi, 7);
			cout << " to set today's date";
		}
		else if (round == 4 && currentChoose == true) {
			//DATE
			gotoxy(31, 10);
			if (currentY == 0) SetConsoleTextAttribute(Mokryi, 4);
			cout << "dd";
			SetConsoleTextAttribute(Mokryi, 7);

			gotoxy(38, 10);
			if (currentY == 1) SetConsoleTextAttribute(Mokryi, 4);
			cout << "mm";
			SetConsoleTextAttribute(Mokryi, 7);

			gotoxy(45, 10);
			if (currentY == 2) SetConsoleTextAttribute(Mokryi, 4);
			cout << "yy";
			SetConsoleTextAttribute(Mokryi, 7);

			showDate(day, mon, year, maxInM, 31);
		}


		SetConsoleTextAttribute(Mokryi, 4);
		if (SettedCorrectly == false) {
			gotoxy(48, 24);
			cout << "You setted  passed date!";
		}


		SetConsoleTextAttribute(Mokryi, 2);
		gotoxy(53, 26);
		if (round == 1) {
			cout << "Type title...";
		}
		else if (round == 2) {
			cout << "Choose smth...";
		}
		else if (round == 3) {
			cout << "Choose date...";
		}
		else cout << "Check evrth...";
		SetConsoleTextAttribute(Mokryi, 7);




		if (round == 1) {
			currentY = -1;

			int key = _getch();
			if (key == 8 && title.length() > 0) {
				title.pop_back();
			}
			else if (key == 27) {
				mChoose(false);
			}
			else if (key == 13 && title != "") {
				isExistE = false;

				while (title[title.length() - 1] == ' ') {
					title.pop_back();
				}

				for (int i = 0; i < countE; i++) {
					if (title == events[i].title) isExistE = true;
				}

				if (!isExistE) {
					round += 1;
					currentY = 0;
				}
			}
			else if (key != 224 && key != 59 && key != 9 && key != 13 && key != 8 && title.length() < 32) {
				title += char(key);
			}
		}
		else if (round == 2) {
			int key = _getch();
			if (key == 72 || key == 119) currentChoose = true;
			else if (key == 115 || key == 80) currentChoose = false;
			else if (key == 13 && currentChoose == true) round += 1;
			else if (key == 13 && currentChoose == false) round += 2;
			else if (key == 27) round -= 1;
		}
		else if (round == 3) {
			if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) maxInM = 31;
			else if (mon == 2 && (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))) maxInM = 29;
			else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) maxInM = 30;
			else if (mon == 2) maxInM = 28;

			int key = _getch();
			if (key == 9) {
				day = timeObj.indexDay;
				mon = timeObj.indexM;
				year = timeObj.year;
			}
			if (key == 27) {
				currentY = -1;
				round -= 1;
			}
			else if (key == 13) {
				currentY = -1;

				SettedCorrectly = false;
				if (year >= timeObj.year) {
					if (year == timeObj.year && mon >= timeObj.indexM) {
						if (mon == timeObj.indexM && day >= timeObj.indexDay) {
							SettedCorrectly = true;
						}
						else if (mon > timeObj.indexM) SettedCorrectly = true;
					}
					else SettedCorrectly = true;
				}
				else {

				}
				if (SettedCorrectly == true) round += 1;
			}
			else if (key == 119 || key == 72) {
				switch (currentY) {
				case 0:
					if (day == maxInM) day = 1;
					else day++;
					break;
				case 1:
					if (mon == 12) mon = 1;
					else mon++;

					if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) maxInM = 31;
					else if (mon == 2 && (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))) maxInM = 29;
					else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) maxInM = 30;
					else maxInM = 28;

					if (day > maxInM) day = maxInM;
					break;
				case 2:
					year++;
					break;
				}
			}
			else if (key == 115 || key == 80) {
				switch (currentY) {
				case 0:
					if (day == 1) day = maxInM;
					else day--;
					break;
				case 1:
					if (mon == 1) mon = 12;
					else mon--;


					if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) maxInM = 31;
					else if (mon == 2 && (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0))) maxInM = 29;
					else if (mon == 4 || mon == 6 || mon == 9 || mon == 11) maxInM = 30;
					else maxInM = 28;

					if (day > maxInM) day = maxInM;
					break;
				case 2:
					if (year == 1) year = timeObj.year;
					year--;
					break;
				}
			}
			else if (currentY < 2 && (key == 77 || key == 100)) currentY++;
			else if (currentY > 0 && (key == 75 || key == 97)) currentY--;
		}
		else {
			currentY = -1;
			int key = _getch();
			if (key == 27 && currentChoose == true) {
				currentY = 0;
				round -= 1;
			}
			else if (key == 27 && currentChoose == false) {
				round -= 2;
			}
			else if (key == 13) {
				if (!currentChoose) {
					day = 0;
					mon = 0;
					year = 0;
				}
				newGoal.title = title;
				newGoal.day = day;
				newGoal.mon = mon;
				newGoal.year = year;
				newGoal.isDone = false;

				countG++;
				Event* temp = new Event[countG - 1];
				for (int i = 0; i < countG - 1; i++) {
					temp[i] = goals[i];
				}
				goals = new Event[countG];

				for (int i = 0; i < countG - 1; i++) {
					goals[i] = temp[i];
				}

				goals[countG - 1] = newGoal;

				//DODAT'
				system("cls");

				//cout << title << endl;

				gotoxy(47, 14);
				SetConsoleTextAttribute(Mokryi, 2);
				cout << "Try NOT to miss your Goal";
				gotoxy(47, 16);
				SetConsoleTextAttribute(Mokryi, 4);
				cout << "Press any key to continue";
				SetConsoleTextAttribute(Mokryi, 0);
				system("pause");
				SetConsoleTextAttribute(Mokryi, 7);

				save();
				mainMenu();
			}
		}
	} while (true);

}

// TRACK
void switchColor(int obj, bool action) {
	switch (action) {
	case false:
		switch (obj) {
		case false: SetConsoleTextAttribute(Mokryi, 4);
			break;
		case true: SetConsoleTextAttribute(Mokryi, 2);
			break;
		}
		break;
	case true:

		break;
	}

}
void trackHabit() {
	int posX = 0;
	int count = 0;
	string searchWord = "";

	int find = 0;

	do {
		//BEAUTY
		system("cls");

		SetConsoleTextAttribute(Mokryi, 4);
		for (int i = 0; i < 30; i++) {
			gotoxy(70, i);
			cout << char(219);
		}
		SetConsoleTextAttribute(Mokryi, 7);

		gotoxy(73, 1);
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "-KEY UP/KEY DOWN-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " to move";

		gotoxy(73, 3);
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "-Enter-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " change status";
		SetConsoleTextAttribute(Mokryi, 2);
		cout << " -on";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << "/";
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "off-";

		gotoxy(73, 5);
		SetConsoleTextAttribute(Mokryi, 4);
		cout << "-ESC-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " go back";

		gotoxy(73, 28);
		SetConsoleTextAttribute(Mokryi, 7);
		cout << "You should practice : ";
		SetConsoleTextAttribute(Mokryi, 2);
		gotoxy(95, 28);
		cout << char(219) << char(219);




		gotoxy(109, 28);
		SetConsoleTextAttribute(Mokryi, 7);
		cout << "Done : ";
		gotoxy(116, 28);
		SetConsoleTextAttribute(Mokryi, 1);
		cout << char(219) << char(219);

		gotoxy(71, 6);
		SetConsoleTextAttribute(Mokryi, 4);
		for (int i = 71; i < 120; i++) {
			gotoxy(i, 6);
			cout << "_";
			gotoxy(i, 24);
			cout << "_";
		}
		SetConsoleTextAttribute(Mokryi, 7);





		gotoxy(1, 1);
		SetConsoleTextAttribute(Mokryi, 7);
		cout << "SEARCH: " << searchWord;
		gotoxy(0, 2);
		SetConsoleTextAttribute(Mokryi, 4);
		for (int i = 0; i < 70; i++) {
			cout << "_";
		}
		SetConsoleTextAttribute(Mokryi, 7);
		gotoxy(2, 4);
		cout << "SEARCH RESULTS:";

		SetConsoleTextAttribute(Mokryi, 7);

		gotoxy(0, 6);

		for (int i = 0; i < countH; i++) {
			switchColor(habits[i].isActive, false);

			if (posX == i && habits[posX].isActive == true)	 SetConsoleTextAttribute(Mokryi, 242);
			else if (posX == i && habits[posX].isActive == false)	 SetConsoleTextAttribute(Mokryi, 244);

			if (searchWord == "") {

				cout << habits[i].title << endl;
				SetConsoleTextAttribute(Mokryi, 7);
			}
			else {
				//œŒÿ”   -“≤ —“–Œ  « œŒƒ“–Œ ¿Ã» ¬ Ã¿—»¬≤
				find = habits[i].title.find(searchWord);
				if (find != -1) {
					count++;
				}
			}


		}

		Search* searchResult = new Search[count];
		//œŒÿ”  œŒƒ—“–Œ  « ƒŒƒ¿¬¿ÕÕﬂÃ ¬ “»Ã◊. Ã¿—»¬
		if (searchWord != "") {


			int index = 0;
			for (int i = 0; i < countH; i++) {

				find = habits[i].title.find(searchWord);
				if (find != -1) {
					searchResult[index].title = habits[i].title;
					searchResult[index].isActive = habits[i].isActive;
					index++;
				}
			}
			index--;

			//¬»¬≤ƒ Õ¿ ≈ –¿Õ “»Ã◊. Ã¿—»¬”
			for (int i = 0; i < count; i++) {
				switchColor(searchResult[i].isActive, false);   ///////////////812

				if (posX == i && searchResult[i].isActive == true) SetConsoleTextAttribute(Mokryi, 242);
				else if (posX == i && searchResult[i].isActive == false) SetConsoleTextAttribute(Mokryi, 244);

				cout << searchResult[i].title << endl;
				SetConsoleTextAttribute(Mokryi, 7);
			}
			//◊ËÒÚÍ‡ ÔÂÂ‰ ÌÓ‚ËÏ ÍÛ„ÓÏ

		}

		//¬»¬Œƒ  ¿À≈Õƒ¿–ﬂ
		if (count > 0 || countH > 0) {
			gotoxy(79, 8);
			if (searchWord == "") {
				switch (habits[posX].isActive) {
				case true:
					SetConsoleTextAttribute(Mokryi, 2);
					cout << "-ON-";
					break;
				case false:
					SetConsoleTextAttribute(Mokryi, 4);
					cout << "-OFF-";
					break;
				}
			}
			else {
				switch (searchResult[posX].isActive) {
				case true:
					SetConsoleTextAttribute(Mokryi, 2);
					cout << "-ON-";
					break;
				case false:
					SetConsoleTextAttribute(Mokryi, 4);
					cout << "-OFF-";
					break;
				}
			}



			gotoxy(103, 8);
			cout << timeObj.nameM << "/";
			gotoxy(107, 8);
			cout << timeObj.year;

			SetConsoleTextAttribute(Mokryi, 7);
			gotoxy(79, 10);

			if (searchWord == "") cout << habits[posX].title;
			else if (count > 0) cout << searchResult[posX].title;
			SetConsoleTextAttribute(Mokryi, 7);
			gotoxy(79, 12);
			cout << "Mo   Tu   We   Th   Fr   Sa   Su";
			int y = 14;

			//int dayNumb = 1;
			int index = 0;
			int charIndex = 1;
			gotoxy(79, y);
			for (int i = 0; i < timeObj.firstNum + timeObj.amountD - 1; i++) {

				if (searchWord == "") {
					if (habits[posX].shedule[index] == true) SetConsoleTextAttribute(Mokryi, 2);
					if (habits[posX].progressArr[i - (timeObj.firstNum - 1)] == true) SetConsoleTextAttribute(Mokryi, 1);
				}
				else {
					for (int j = 0; j < countH; j++) {
						for (int o = 0; o < count; o++) {
							if (habits[j].title == searchResult[o].title && habits[j].shedule[index] == true) SetConsoleTextAttribute(Mokryi, 2);
							if (habits[j].title == searchResult[o].title && habits[j].progressArr[i - (timeObj.firstNum - 1)] == true)  SetConsoleTextAttribute(Mokryi, 1);
						}
					}
				}

				if (i < abs(timeObj.firstNum - 1)) cout << "     ";
				else cout << char(219) << char(219) << "   ";
				/*if (i < timeObj.firstNum - 1) {
					SetConsoleTextAttribute(Mokryi, 7);
					cout << "     ";
				}
				else {
					if (dayNumb < 10) {
						cout << "0" << dayNumb;
					}
					else {
						cout << dayNumb;
					}
					dayNumb++;
					SetConsoleTextAttribute(Mokryi, 7);
					cout << "   ";
				}*/
				SetConsoleTextAttribute(Mokryi, 7);

				index++;
				if (index == 7) {
					cout << "\n\n";
					index = 0;
					y += 2;
					gotoxy(79, y);
				}
			}
		}


		/////////////////

		//«◊»“”¬¿ÕÕﬂ «  À¿¬»  ÕŒœŒ 
		Sleep(0.5);
		int key = _getch();
		switch (key) {
		case 27:
			if (habits[0].title != "") save();
			mainMenu();
			break;
		case 13:
			if (searchWord == "")habits[posX].isActive = !habits[posX].isActive;
			else {
				searchResult[posX].isActive = !searchResult[posX].isActive;
				for (int i = 0; i < countH; i++) {
					for (int j = 0; j < countH; j++) {
						if (habits[i].title == searchResult[j].title) {
							habits[i].isActive = searchResult[j].isActive;
						}
					}
				}
			}
			break;
		}
		if (key == 8 && searchWord.length() > 0) {
			searchWord.pop_back();
		}
		else if ((key != 224 && key != 80 && key != 77 && key != 75 && key != 72 && key != 9 && key != 13 && key != 8) && searchWord.length() < 32) {
			posX = 0;
			searchWord += char(key);
		}

		//navigation
		if (count == 0) count = countH;
		switchMove(key, false, false, &posX, 0, count - 1);

		delete[]searchResult;
		count = 0;

	} while (true);
}
//=======================================================================

//=========================-TODAY GOALS-=================================
void changeStatus(int* sFrom, int* sTo, string*& From, string*& To, int* posX, bool* posY) {

	string replace = "";
	if (*sFrom > 0) {
		//”·Ë‡∫Ï ‚Ë·‡ÌËÈ ÂÎÂÏÂÌÚ Á Ï‡Ò≥‚‡, Á‡ÔËÒÛ∫Ï ÈÓ„Ó ‚ ÁÏ≥ÌÌÛ.
		int i = 0;
		replace = From[*posX];

		*sFrom -= 1;
		string* temp = new string[*sFrom];

		for (i; i < *posX; i++) {
			temp[i] = *(From + i);
		}
		for (i = *posX; i < *sFrom; i++) {
			temp[i] = *(From + (i + 1));
		}




		From = new string[*sFrom];
		for (int i = 0; i < *sFrom; i++) {
			*(From + i) = temp[i];
		}

		delete[]temp;
		//ƒÓ·‡‚Îˇ∫Ï ‚ Í≥ÌÂˆ¸ Ï‡Ò≥‚‡ DONE

		string* tempD = new string[*sTo];
		for (int i = 0; i < *sTo; i++) {
			tempD[i] = *(To + i);
		}

		*sTo += 1;
		To = new string[*sTo];
		for (int i = 0; i < *sTo - 1; i++) {
			*(To + i) = tempD[i];
		}

		*(To + (*sTo - 1)) = replace;

		delete[]tempD;
		//Œ·ÌÓ‚Îˇ∫Ï ÍÛÒÓ


		if (*posX == *sFrom) {
			*posX = *posX - 1;
			if (*sFrom == 0) {
				*posY = !*posY;
				*posX = 0;
			}
		}

	}

}
void todayGoals(bool choose) {
	bool round = false;
	switch (choose) {
	case false: round = false;
		break;
	case true: round = true;
		break;
	}

	int posX = 0;
	bool posY = false;

	int mainColor = 0;
	int backColor = 0;

	///////-----------------------------------111-----------------
	int countDone = 0;
	for (int i = 0; i < countH; i++) {
		if (habits[i].progressArr[timeObj.indexDM] == true && habits[i].isActive == true && habits[i].shedule[timeObj.indexDay] == true) countDone++;
	}
	int sDone = countDone;
	////////
	int countShould = 0;
	for (int i = 0; i < countH; i++) {
		if (habits[i].progressArr[timeObj.indexDM] == false && habits[i].isActive == true && habits[i].shedule[timeObj.indexDay] == true) countShould++;
	}
	int sShould = countShould;
	///////-----------------------------------222-----------------


	int countGoal = 0;
	for (int i = 0; i < countG; i++) {
		if (goals[i].isDone == false) countGoal++;
	}
	int sGoal = countGoal;
	////////
	int countFin = 0;
	int passedDate = false;

	for (int i = 0; i < countG; i++) {
		passedDate = false;
		if (goals[i].year >= timeObj.year) {
			if (goals[i].year == timeObj.year && goals[i].mon >= timeObj.indexM) {
				if (goals[i].mon == timeObj.indexM && goals[i].day < timeObj.indexDM + 1) {
					passedDate = true;
				}
			}
			else passedDate = true;
		}
		else passedDate = true;

		if (goals[i].isDone == true && passedDate == false) countFin++;
	}
	int sFin = countFin;
	///////////////////////////////////////////////////////////////


	string* should = new string[sShould];
	string* done = new string[sDone];
	string* goal = new string[sGoal];
	string* fin = new string[sFin];

	countDone = 0;
	countShould = 0;
	countGoal = 0;
	countFin = 0;

	///////-----------------------------------111-----------------
	//ƒŒ¡¿¬»“‹ ƒ¿Õ ¬ —œ»—Œ  ƒ¿Õ
	for (int i = 0; i < countH; i++) {
		if (habits[i].progressArr[timeObj.indexDM] == true && habits[i].isActive == true && habits[i].shedule[timeObj.indexDay] == true) {
			done[countDone] = habits[i].title;
			countDone++;
		}
	}
	//ƒŒ¡¿¬»“‹ ÿ”ƒ ¬ —œ»—Œ  ÿ”ƒ
	for (int i = 0; i < countH; i++) {
		if (habits[i].progressArr[timeObj.indexDM] == false && habits[i].isActive == true && habits[i].shedule[timeObj.indexDay] == true) {
			should[countShould] = habits[i].title;
			countShould++;
		}
	}


	///////-----------------------------------222-----------------
	//√ŒÀ ¬ —œ»—Œ  √ŒÀ
	for (int i = 0; i < countG; i++) {
		if (goals[i].isDone == false) {
			goal[countGoal] = goals[i].title;
			countGoal++;
		}
	}


	//‘≤Õ ¬ —œ»—Œ  ‘≤Õ
	for (int i = 0; i < countG; i++) {
		passedDate = false;
		if (goals[i].year >= timeObj.year) {
			if (goals[i].year == timeObj.year && goals[i].mon >= timeObj.indexM) {
				if (goals[i].mon == timeObj.indexM && goals[i].day < timeObj.indexDM + 1) {
					passedDate = true;
				}
			}
			else passedDate = true;
		}
		else passedDate = true;
		if (goals[i].isDone == true && passedDate == false) {
			fin[countFin] = goals[i].title;
			countFin++;
		}
	}
	///////////////////////////////////////////////////////////////

	do {
		if (!round) {
			mainColor = 4;
			backColor = 2;
			if (sShould == 0) posY = true;
			else if (sDone == 0) posY = false;
		}
		else {
			mainColor = 2;
			backColor = 4;
			if (sGoal == 0) posY = true;
			else if (sFin == 0) posY = false;
		}
		system("cls");

		SetConsoleTextAttribute(Mokryi, mainColor);
		if (!round) {
			gotoxy(57, 1);
			cout << "TODAY'S ROUTINE";
		}
		else {
			gotoxy(60, 1);
			cout << "MY GOALS";
		}


		SetConsoleTextAttribute(Mokryi, backColor);
		gotoxy(40, 3);
		if (!round) {
			cout << "ROUTINE LIST:";
		}
		else {
			cout << "GOAL LIST:";
		}
		gotoxy(80, 3);
		cout << "DONE:";


		gotoxy(4, 3);
		cout << "-W/S- | -A/D-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " to move";

		gotoxy(4, 5);
		SetConsoleTextAttribute(Mokryi, backColor);
		cout << "-Space-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " to action";

		gotoxy(4, 7);
		SetConsoleTextAttribute(Mokryi, backColor);
		cout << "-ESC-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " save & exit";

		gotoxy(4, 9);
		SetConsoleTextAttribute(Mokryi, backColor);
		cout << "-TAB-";
		SetConsoleTextAttribute(Mokryi, 7);
		cout << " change to ";
		SetConsoleTextAttribute(Mokryi, mainColor);
		if (!round) cout << "Goal";
		else cout << "Routine";
		SetConsoleTextAttribute(Mokryi, 7);

		if (round == true) {

			for (int i = 0; i < countG; i++) {
				if ((goals[i].title == goal[posX] && !posY) || (goals[i].title == fin[posX] && posY == true)) {
					gotoxy(4, 15);
					cout << goals[i].title;

					gotoxy(4, 17);
					SetConsoleTextAttribute(Mokryi, backColor);
					cout << "Deadline: ";
					SetConsoleTextAttribute(Mokryi, 8);
					if (goals[i].day == 0) {
						cout << " -No-";
					}
					else {
						if (goals[i].day < 10) {
							cout << "0" << goals[i].day << ".";
						}
						else {
							cout << goals[i].day << ".";
						}
						if (goals[i].mon < 10) {
							cout << "0" << goals[i].mon << ".";
						}
						else {
							cout << goals[i].mon << ".";
						}
						cout << goals[i].year;
					}
				}
			}

			gotoxy(3, 20);
			SetConsoleTextAttribute(Mokryi, 7);
			cout << "* without deadline";

			gotoxy(3, 22);
			SetConsoleTextAttribute(Mokryi, 8);
			cout << "* 1 week & more";

			gotoxy(3, 24);
			SetConsoleTextAttribute(Mokryi, 4);
			cout << "* ";
			cout << "already past";

			SetConsoleTextAttribute(Mokryi, 9);
			gotoxy(3, 26);
			cout << "* ";
			cout << "7 days & less";

			SetConsoleTextAttribute(Mokryi, 6);
			gotoxy(3, 28);
			cout << "* ";
			cout << "3 days & less";
		}

		SetConsoleTextAttribute(Mokryi, backColor);
		if (round == true) {
			for (int i = 0; i < 37; i++) {
				gotoxy(i, 12);
				cout << "_";
				gotoxy(i, 18);
				cout << "_";
			}
		}

		for (int i = 0; i < 30; i++) {
			gotoxy(37, i);
			cout << char(219);
		}
		SetConsoleTextAttribute(Mokryi, 7);



		switch (round) {
		case false:
			for (int i = 0; i < sShould; i++) {
				if (posX == i && posY == false) SetConsoleTextAttribute(Mokryi, mainColor);
				gotoxy(40, i + 5);
				cout << should[i] << endl;
				SetConsoleTextAttribute(Mokryi, 7);
			}
			break;
		case true:
			for (int o = 0; o < sGoal; o++) {
				gotoxy(43, o + 5);
				if (posY == false && posX == o) SetConsoleTextAttribute(Mokryi, mainColor);
				cout << goal[o];
				SetConsoleTextAttribute(Mokryi, 7);
			}
			for (int i = 0; i < sGoal; i++) {
				////
				for (int j = 0; j < countG; j++) {

					int dayIf3 = 0;
					int dayIf7 = 0;
					int monIf3 = 0;
					int monIf7 = 0;
					int amountD = 0;
					int yearIf3 = 0;
					int yearIf7 = 0;

					if (goal[i] == goals[j].title) {
						if (goals[j].day > 7) {
							dayIf7 = goals[j].day - 7;
							monIf7 = goals[j].mon;


							dayIf3 = goals[j].day - 3;
							monIf3 = goals[j].mon;

							yearIf3 = goals[j].year;
							yearIf7 = goals[j].year;
						}
						else if (goals[j].day > 3) {

							dayIf3 = goals[j].day - 3;
							monIf3 = goals[j].mon;
							yearIf3 = goals[j].year;

							if (goals[j].mon == 1) {
								monIf7 = 12;
								yearIf7 = goals[j].year - 1;
							}
							else {
								monIf7 = goals[j].mon - 1;
								yearIf7 = goals[j].year;
							}

							if (monIf7 == 1 || monIf7 == 3 || monIf7 == 5 || monIf7 == 7 || monIf7 == 8 || monIf7 == 10 || monIf7 == 12) amountD = 31;
							else if (monIf7 == 2 && (yearIf7 % 4 == 0 && (yearIf7 % 400 == 0 || yearIf7 % 100 != 0))) amountD = 29;
							else if (monIf7 == 4 || monIf7 == 6 || monIf7 == 9 || monIf7 == 11) amountD = 30;
							else amountD = 28;

							dayIf7 = amountD - abs(goals[j].day - 7);
						}
						else if (goals[j].day <= 3) {
							if (goals[j].mon == 1) {
								monIf3 = 12;
								monIf7 = 12;

								yearIf7 = goals[j].year - 1;
								yearIf3 = goals[j].year - 1;
							}
							else {
								monIf3 = goals[j].mon - 1;
								monIf7 = goals[j].mon - 1;

								yearIf3 = goals[j].year;
								yearIf7 = goals[j].year;
							}

							if (monIf7 == 1 || monIf7 == 3 || monIf7 == 5 || monIf7 == 7 || monIf7 == 8 || monIf7 == 10 || monIf7 == 12) amountD = 31;
							else if (monIf7 == 2 && (yearIf7 % 4 == 0 && (yearIf7 % 400 == 0 || yearIf7 % 100 != 0))) amountD = 29;
							else if (monIf7 == 4 || monIf7 == 6 || monIf7 == 9 || monIf7 == 11) amountD = 30;
							else amountD = 28;

							dayIf3 = amountD - abs(goals[j].day - 3);
							dayIf7 = amountD - abs(goals[j].day - 7);
						}

						bool passedDate = false;
						bool days7less = false;
						bool days3less = false;

						//1 Week
						if (yearIf7 >= timeObj.year) {
							if (yearIf7 == timeObj.year && monIf7 >= timeObj.indexM) {
								if (monIf7 == timeObj.indexM && dayIf7 < timeObj.indexDM + 1) {
									days7less = true;
								}
							}
							else days7less = true;
						}
						else days7less = true;

						//Passed
						if (goals[j].year >= timeObj.year) {
							if (goals[j].year == timeObj.year && goals[j].mon >= timeObj.indexM) {
								if (goals[j].mon == timeObj.indexM && goals[j].day < timeObj.indexDM + 1) {
									passedDate = true;
								}
							}
							else passedDate = true;
						}
						else passedDate = true;

						if (yearIf3 >= timeObj.year) {
							if (yearIf3 == timeObj.year && monIf3 >= timeObj.indexM) {
								if (monIf3 == timeObj.indexM && dayIf3 < timeObj.indexDM + 1) {
									days3less = true;
								}
							}
							else days3less = true;
						}
						else days3less = true;



						gotoxy(40, i + 5);

						// Without d
						if (goals[j].day == 0) {
							SetConsoleTextAttribute(Mokryi, 7);
							cout << " * ";
							SetConsoleTextAttribute(Mokryi, 7);
						}
						//Passed date
						else if (passedDate == true) {
							SetConsoleTextAttribute(Mokryi, 4);
							cout << " * ";
							SetConsoleTextAttribute(Mokryi, 7);
						}
						//More than week
						else if (!passedDate && !days3less && !days7less) {
							SetConsoleTextAttribute(Mokryi, 8);
							cout << " * ";
							SetConsoleTextAttribute(Mokryi, 7);
						}
						//1 Week
						else if (!passedDate && days7less == true && days3less == false) {
							SetConsoleTextAttribute(Mokryi, 9);
							cout << " * ";
							SetConsoleTextAttribute(Mokryi, 7);
						}
						//3 days
						else if (!passedDate && days3less == true) {
							SetConsoleTextAttribute(Mokryi, 6);
							cout << " * ";
							SetConsoleTextAttribute(Mokryi, 7);
						}
						//






					}
				}
				///////////////
			}
			break;
		}

		gotoxy(0, 29);

		SetConsoleTextAttribute(Mokryi, 8);

		switch (round) {
		case false:
			for (int i = 0; i < sDone; i++) {
				if (posX == i && posY == true)SetConsoleTextAttribute(Mokryi, mainColor);
				gotoxy(80, i + 5);
				cout << done[i] << endl;
				SetConsoleTextAttribute(Mokryi, 8);
			}
			break;
		case true:
			for (int i = 0; i < sFin; i++) {
				gotoxy(80, i + 5);
				if (posY == true && posX == i) SetConsoleTextAttribute(Mokryi, mainColor);
				cout << fin[i];
				SetConsoleTextAttribute(Mokryi, 8);
			}
			break;
		}



		int key = _getch();
		if (key == 72 || key == 119) {
			switch (round) {
			case false:
				switch (posY) {
				case false:
					moveUp(&posX, 0, sShould - 1);
					break;

				case true:
					moveUp(&posX, 0, sDone - 1);
					break;
				}
				break;
			case true:
				switch (posY) {
				case false:
					moveUp(&posX, 0, sGoal - 1);
					break;

				case true:
					moveUp(&posX, 0, sFin - 1);
					break;
				}
				break;
			}

		}

		else if (key == 80 || key == 115) {
			switch (round) {
			case false:
				switch (posY) {
				case false:
					moveDown(&posX, 0, sShould - 1);
					break;

				case true:
					moveDown(&posX, 0, sDone - 1);
					break;
				}
			default:
				break;
			case true:
				switch (posY) {
				case false:
					moveDown(&posX, 0, sGoal - 1);
					break;

				case true:
					moveDown(&posX, 0, sFin - 1);
					break;
				}
				break;
			}
		}


		else if (key == 77 || key == 100) {
			if (posY == false) {
				posY = true;
				posX = 0;
			}
			// right
		}
		else if (key == 75 || key == 97) {
			if (posY == true) {
				posY = false;
				posX = 0;
			}
			// left
		}

		//“ÛÚ Ò‚≥˜ÓÏ ÍÌÓÔÍ≥-‰ÂÈÒÚ‚≥ˇ
		switch (key) {
		case 9:
			posX = 0;
			posY = false;
			round = !round;
			break;
		case 32:
			switch (round) {
			case false:
				switch (posY) {
				case false:
					//if (sShould > 0) {
					changeStatus(&sShould, &sDone, should, done, &posX, &posY);
					//}
					break;

				case true:
					//if (sDone > 0) {
					changeStatus(&sDone, &sShould, done, should, &posX, &posY);
					//}

					break;
				default:
					break;
				}
				break;
			case true:
				switch (posY) {
				case false:
					//if (sShould > 0) {
					changeStatus(&sGoal, &sFin, goal, fin, &posX, &posY);
					//}
					break;

				case true:
					//if (sDone > 0) {
					changeStatus(&sFin, &sGoal, fin, goal, &posX, &posY);
					//}

					break;
				default:
					break;
				}
				break;
			}
			break;
		case 27:
			for (int i = 0; i < countH; i++) {
				for (int j = 0; j < sShould; j++) {
					if (habits[i].title == should[j]) habits[i].progressArr[timeObj.indexDM] = false;
				}
				for (int j = 0; j < sDone; j++) {
					if (habits[i].title == done[j]) habits[i].progressArr[timeObj.indexDM] = true;

				}
			}

			for (int i = 0; i < countG; i++) {
				for (int j = 0; j < sGoal; j++) {
					if (goals[i].title == goal[j]) goals[i].isDone = false;
				}
				for (int j = 0; j < sFin; j++) {
					if (goals[i].title == fin[j]) goals[i].isDone = true;
				}
			}

			if (habits[0].title != "" || goals[0].title != "") save();
			SetConsoleTextAttribute(Mokryi, 7);
			mainMenu();
			break;
		}

	} while (true);
}
//=======================================================================
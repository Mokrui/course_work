#include"Header.h"

int main() {
	/*do {
		int ssss = _getch();
		cout << ssss << endl;
	} while (true);*/


	/*HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 256; i++)
	{
		SetConsoleTextAttribute(handle, i);
		cout << i << "  ";
		SetConsoleTextAttribute(handle, 0);
		cout << endl;
	}*/

	getTime();
	init();
	mainMenu();
}
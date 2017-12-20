#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define MAX_SCREEN_WIDTH 999
#define MAX_SCREEN_HEIGHT 999
#define KB_SPACE 0x20

COORD ConsoleSize = { 200, 50 };

int main(void) {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hConsoleOutput, COORD{ MAX_SCREEN_WIDTH, MAX_SCREEN_HEIGHT });
	SMALL_RECT ConsoleWindow = { 0, 0, ConsoleSize.X - 1, ConsoleSize.Y - 1 }; SetConsoleWindowInfo(hConsoleOutput, true, &ConsoleWindow);
	SetConsoleScreenBufferSize(hConsoleOutput, ConsoleSize);

	WORD colorValue[2] = { FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY, BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY };
	int color = 0;
	int a = 0;
	while (1) {
		printf("%d", a);
		for (SHORT i = 48; i < ConsoleSize.Y; i++) for (SHORT j = 0; j < ConsoleSize.X; j++) {
			SetConsoleCursorPosition(hConsoleOutput, COORD{ j, i });
			SetConsoleTextAttribute(hConsoleOutput, colorValue[color]);
			if (i == ConsoleSize.Y - 1 && j == ConsoleSize.X - 1) continue;
			if (j % 4 != 0) continue;
			else putchar(' ');
		}
		SetConsoleCursorPosition(hConsoleOutput, COORD{ 0, 0 });
		SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_INTENSITY);


		if (_kbhit()) {
			if (_getch() == KB_SPACE) {
				break;
			}
		}
		color = !color;
		a++;

		Sleep(50);
	}

	//SetConsoleCursorPosition カーソル位置指定

	return 0;
}
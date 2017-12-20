#pragma once

WORD colorValue[2] = { FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_INTENSITY, BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY };
int color = 0;
int a = 0;
SHORT i, j;
while (1) {
	printf("%d", a);
	for (i = 6; i < ConsoleSize.Y - 2; i++) {
		for (j = 0; j < ConsoleSize.X; j++) {
			SetConsoleCursorPosition(hConsoleOutput, COORD{ j, i });
			SetConsoleTextAttribute(hConsoleOutput, colorValue[color]);
			if (i == ConsoleSize.Y - 1 && j == ConsoleSize.X - 1) continue;
			if (j % 1 != 0) continue;
			else putchar(' ');
		}
	}

	if (_kbhit()) {
		if (_getch() == KB_SPACE) {
			break;
		}
	}
	color = !color;
	a++;

	char title[100];
	strcpy_s(title, "aaa");




	for (i = 6; i < ConsoleSize.Y - 2; i++) {

		SetConsoleCursorPosition(hConsoleOutput, COORD{ j - 1, i });
		SetConsoleTextAttribute(hConsoleOutput, 0);
		putchar(' ');
	}
	SetConsoleCursorPosition(hConsoleOutput, COORD{ 0, 0 });
	SetConsoleTextAttribute(hConsoleOutput, FOREGROUND_INTENSITY);
	Sleep(200);
}

//SetConsoleCursorPosition カーソル位置指定

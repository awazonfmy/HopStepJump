//マスター

#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <Windows.h>
#include <cwchar>

#define MAX_SCREEN_WIDTH 300
#define MAX_SCREEN_HEIGHT 300

extern COORD ConsoleSize;
extern HANDLE hConsoleOutput;

int draw();
int game();
int ranking();
int title();

typedef struct _SCREEN {
	COORD size;
	char a[MAX_SCREEN_HEIGHT][MAX_SCREEN_WIDTH];
	WORD color[MAX_SCREEN_HEIGHT][MAX_SCREEN_WIDTH];
	_SCREEN(COORD _size = COORD{ 2, 1 }) {
		size = _size;
		for (SHORT i = 0; i < _size.Y; i++) for (SHORT j = 0; j < _size.X; j++) {
			a[i][j] = ' ';
			color[i][j] = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		}
	}
} SCREEN;

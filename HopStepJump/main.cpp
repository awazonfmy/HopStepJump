#include "header.h"

COORD ConsoleSize;
HANDLE hConsoleOutput;

HANDLE init(void) {
	ConsoleSize = { 240, 60 };

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTitle("Hop Step Jump!!!");

	CONSOLE_FONT_INFOEX ConsoleCurrentFontEx;
	GetCurrentConsoleFontEx(hConsoleOutput, false, &ConsoleCurrentFontEx);
	ConsoleCurrentFontEx.cbSize = sizeof(ConsoleCurrentFontEx);
	ConsoleCurrentFontEx.nFont = 0;
	ConsoleCurrentFontEx.dwFontSize.X = 0;                   // Width of each character in the font
	ConsoleCurrentFontEx.dwFontSize.Y = 8;                  // Height
	ConsoleCurrentFontEx.FontFamily = FF_DONTCARE;
	ConsoleCurrentFontEx.FontWeight = FW_NORMAL;
	std::wcscpy(ConsoleCurrentFontEx.FaceName, L"ÇlÇr ÉSÉVÉbÉN"); // Choose your font
	SetCurrentConsoleFontEx(hConsoleOutput, false, &ConsoleCurrentFontEx);

	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);

	SetConsoleScreenBufferSize(hConsoleOutput, COORD{ MAX_SCREEN_WIDTH, MAX_SCREEN_HEIGHT });
	SMALL_RECT ConsoleWindow = { 0, 0, ConsoleSize.X - 1, ConsoleSize.Y - 1 };
	SetConsoleWindowInfo(hConsoleOutput, true, &ConsoleWindow);
	SetConsoleScreenBufferSize(hConsoleOutput, ConsoleSize);

	return hConsoleOutput;
}

int main(void) {
	SCREEN scConsole;

	HANDLE hConsoleOutput = init();

	title();
	
	system("pause");
	return 0;
}
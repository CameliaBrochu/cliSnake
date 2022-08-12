#include "CliGameEngine.h"

#include <Windows.h>
#include <WinUser.h>

cliGE::CliGameEngine::CliGameEngine(size_t screenWidth, size_t screenHeight)
	:m_screenWidth(screenWidth),m_screenHeight(screenHeight)
{
}

void cliGE::CliGameEngine::start()
{
	wchar_t* screen = new wchar_t[m_screenWidth * m_screenHeight];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);

	// Set cursor visibility to false
	CONSOLE_CURSOR_INFO* cInfo = new CONSOLE_CURSOR_INFO();
	cInfo->dwSize = 1;
	cInfo->bVisible = false;
	SetConsoleCursorInfo(hConsole, cInfo);

	DWORD dwBytesWritten = 0;


	size_t pX = 0;
	size_t pY = 0;

	onGameLoad();

	while (true) {

		// Init screen with spaces
		for (size_t i = 0; i < m_screenWidth * m_screenHeight; i++)
		{
			screen[i] = L' ';
		}


		// A : 0x41
		if (GetAsyncKeyState(0x41)) {
			--pX;
		}

		// D : 0x44
		if (GetAsyncKeyState(0x44)) {
			++pX;
		}

		// W : 0x57
		if (GetAsyncKeyState(0x57)) {
			--pY;
		}

		// S : 0x53
		if (GetAsyncKeyState(0x53)) {
			++pY;
		}

		screen[pX + (pY * m_screenWidth)] = L'P';

		WriteConsoleOutputCharacter(hConsole, screen, m_screenWidth * m_screenHeight, { 0,0 }, &dwBytesWritten);
		Sleep(16);
	}
}

void cliGE::CliGameEngine::onGameLoad()
{
}

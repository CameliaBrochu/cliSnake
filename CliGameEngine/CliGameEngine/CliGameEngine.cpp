#include "CliGameEngine.h"

#include <Windows.h>
#include <WinUser.h>

cliGE::CliGameEngine::CliGameEngine(size_t screenWidth, size_t screenHeight)
	:m_screenWidth(screenWidth),m_screenHeight(screenHeight),m_screen(new wchar_t[m_screenWidth * m_screenHeight])
{
}

void cliGE::CliGameEngine::start()
{
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);

	// Set cursor visibility to false
	CONSOLE_CURSOR_INFO* cInfo = new CONSOLE_CURSOR_INFO();
	cInfo->dwSize = 1;
	cInfo->bVisible = false;
	SetConsoleCursorInfo(hConsole, cInfo);

	DWORD dwBytesWritten = 0;

	onGameLoad();

	while (true) {

		// Clear screen with spaces
		for (size_t i = 0; i < m_screenWidth * m_screenHeight; i++)
		{
			m_screen[i] = L' ';
		}

		onGameUpdate();
		onGameDraw(m_screen);

		WriteConsoleOutputCharacter(hConsole, m_screen, m_screenWidth * m_screenHeight, { 0,0 }, &dwBytesWritten);
		Sleep(16);
	}
}

void cliGE::CliGameEngine::onGameLoad()
{
}

void cliGE::CliGameEngine::onGameUpdate()
{
}

void cliGE::CliGameEngine::onGameDraw(wchar_t*)
{
}

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
	delete cInfo;

	DWORD dwBytesWritten = 0;

	onGameLoad();

	while (true) {

		onGameUpdate();

		// Clear screen with spaces
		for (size_t i = 0; i < m_screenWidth * m_screenHeight; i++)
		{
			m_screen[i] = L' ';
		}

		onGameDraw();

		WriteConsoleOutputCharacter(hConsole, m_screen, m_screenWidth * m_screenHeight, { 0,0 }, &dwBytesWritten);
		Sleep(16);
	}
}

void cliGE::CliGameEngine::writeCharAt(char p_char, int x, int y)
{
	m_screen[x + (y * m_screenWidth)] = p_char;
}

void cliGE::CliGameEngine::onGameLoad()
{
}

void cliGE::CliGameEngine::onGameUpdate()
{
}

void cliGE::CliGameEngine::onGameDraw()
{
}

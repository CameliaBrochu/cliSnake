#include <stdio.h>
#include "CliGameEngine.h"

#include <Windows.h>
#include <WinUser.h>

class demoGameEngine : public cliGE::CliGameEngine
{
public:
	using CliGameEngine::CliGameEngine;

	void onGameLoad() {
		pX = 0;
		pY = 0;
	}
	void onGameUpdate() {
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
	}

	void onGameDraw(wchar_t* screen) {
		screen[pX + (pY * 120)] = L'P';
	}
private:
	size_t pX;
	size_t pY;
};

int main() {

	demoGameEngine demo(120, 40);
	demo.start();

	return 0;
}
#pragma once
namespace cliGE {
	class CliGameEngine
	{
	public:
		explicit CliGameEngine(size_t screenWidth, size_t screenHeight);
		void start();
		virtual void onGameLoad();
		virtual void onGameUpdate();
		virtual void onGameDraw();
		void writeCharAt(wchar_t wchar,int x,int y);

	private:
		size_t m_screenWidth;
		size_t m_screenHeight;
		wchar_t* m_screen;
	};
}



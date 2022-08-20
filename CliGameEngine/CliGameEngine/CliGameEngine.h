#pragma once
namespace cliGE {
	class CliGameEngine
	{
	public:
		explicit CliGameEngine(size_t screenWidth, size_t screenHeight);
		void start();
		virtual void onGameLoad() = 0;
		virtual void onGameUpdate() = 0;
		virtual void onGameDraw() = 0;
		void writeCharAt(char p_char,int x,int y);
		bool keyPressed(int keyCode);

	private:
		size_t m_screenWidth;
		size_t m_screenHeight;
		wchar_t* m_screen;
	};
}



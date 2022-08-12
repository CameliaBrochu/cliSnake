#pragma once
namespace cliGE {
	class CliGameEngine
	{
	public:
		CliGameEngine(size_t screenWidth, size_t screenHeight);
		void start();
		void onGameLoad();

	private:
		size_t m_screenWidth;
		size_t m_screenHeight;
	};
}



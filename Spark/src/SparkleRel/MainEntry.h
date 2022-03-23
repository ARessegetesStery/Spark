#pragma once

#include "sppch.h"
#include "lib/splog/splog.h"

#include "Windows.h"

extern Spark::Application* createApp();

int main()
{
	std::cout << "Welcome to Spark!" << std::endl;

	std::string str("123");
	SPLOG_WARNING("Hello SPLOG!, {0}, {1}, {0}", 1, str);
	// std::cout << splog::spToString(str) << std::endl;
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices

	auto app = createApp();
	app->tickUpdate();
	delete app;
}
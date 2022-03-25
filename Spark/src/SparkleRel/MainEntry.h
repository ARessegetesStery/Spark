#pragma once

#include "sppch.h"
#include "lib/splog/splog.h"
#include "lib/splog/Platform/Windows/splogWindowsConfig.h"

#include "Windows.h"

extern Spark::Application* createApp();

int main()
{
	std::cout << "Welcome to Spark!" << std::endl;

	/* --- Test ground --- */
	splog::Logger* log = splog::Logger::genLogger("Spark");
	log->setLogFormat("[||TIME||]||CSTR|| ||NAME||: ||LMSG|| ||CEND||");
	log->trace("Hello!");

	//std::string str("123");
	//std::cout << str.length() << std::endl;

	/* ------------------- */

	auto app = createApp();
	app->tickUpdate();
	delete app;
}
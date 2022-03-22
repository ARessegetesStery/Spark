#pragma once

#include "sppch.h"
#include "splog.h"

extern Spark::Application* createApp();

int main()
{
	std::cout << "Welcome to Spark!" << std::endl;

	SPLOG_INFO("Hello SPLOG!");

	auto app = createApp();
	app->tickUpdate();
	delete app;
}
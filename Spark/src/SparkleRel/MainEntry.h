#pragma once

#include "sppch.h"

extern Spark::Application* createApp();

int main()
{
	std::cout << "Welcome to Spark!" << std::endl;

	auto app = createApp();
	app->tickUpdate();
	delete app;
}
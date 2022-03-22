#include "sppch.h"

#include "Application.h"

namespace Spark {

	Application::Application()
	{
		m_Running = true;
	}

	Application::~Application()
	{
	}

	void Application::tickUpdate()
	{
		while (m_Running)
		{

		}
	}
}
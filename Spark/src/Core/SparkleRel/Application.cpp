#include "sppch.h"

#include "Application.h"

#include "Event/ApplicationEvent.h"

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
		WindowResizedEvent e(1280, 720);
		SP_CORE_LOG_TRACE(e.ToString())

		while (m_Running)
		{

		}
	}
}
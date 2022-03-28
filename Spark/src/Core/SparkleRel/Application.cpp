#include "sppch.h"

#include "Application.h"

#include "Event/Event.h"
#include "Event/ApplicationEvent.h"

#include <GLAD/glad.h>

namespace Spark {

#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		SP_CORE_ASSERT(!s_Instance, "Application already exists!")
		s_Instance = this;

		m_Running = true;
		m_Window = std::unique_ptr<Window>(Window::createWindow());

		m_Window->setCallbackFunc(BIND_EVENT_FUNC(onEvent));
	}

	Application::~Application()
	{
	}

	void Application::onEvent(Event& e)
	{
		SP_CORE_LOG_INFO(e.ToString())

		EventDispatcher Dispatcher(e);
		Dispatcher.Dispatch<WindowClosedEvent>(BIND_EVENT_FUNC(onWindowClose));
	}

	bool Application::onWindowClose(WindowClosedEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::tickUpdate()
	{
		
		while (m_Running)
		{
			glClearColor(0.4f, 0.2f, 0.6f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			m_Window->onUpdate();
		}
	}
}
#pragma once

#include "sppch.h"

#include "Core/Basics.h"
#include "Core/Window.h"
#include "Event/Event.h"
#include "Event/ApplicationEvent.h"

namespace Spark {

	class SPARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void onEvent(Event& e);
		bool onWindowClose(WindowClosedEvent& e);

		void tickUpdate();

	private:
		bool m_Running;
		std::unique_ptr<Window> m_Window;

		static Application* s_Instance;
	};

	Application* createApp();

}
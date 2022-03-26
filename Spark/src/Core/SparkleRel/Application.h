#pragma once

#include "sppch.h"

#include "Basics.h"
#include "Core/Log.h"

namespace Spark {

	class SPARK_API Application
	{
	public:
		Application();
		virtual ~Application();

		void tickUpdate();

	private:
		bool m_Running;
	};

	Application* createApp();

}
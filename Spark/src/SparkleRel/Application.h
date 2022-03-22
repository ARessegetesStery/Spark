#pragma once

#include "sppch.h"

#include "Core.h"

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

}
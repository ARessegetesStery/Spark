#pragma once

#include "sppch.h"
#include "Core/Window.h"

#include <GLAD/glad.h>

namespace Spark {

	class SPARK_API WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProp& prop);
		virtual ~WindowsWindow();

		virtual void onUpdate() override;

		inline unsigned int getHeight() const override { return m_Info.height; }
		inline unsigned int getWidth() const override { return m_Info.width; }

		// Window attributes
		inline void setCallbackFunc(const EventCallbackFn& func) override { m_Info.callback = func; }
		inline bool isVSync() const override { return m_Info.VSync; }

		void setVSync(bool Enabled) override;

		void init(const WindowProp& prop);
		void shutdown();

	private:

		GLFWwindow* m_Window;

		struct WindowInfo
		{
			std::string name;
			unsigned int height, width;

			EventCallbackFn callback;
			bool VSync;
		};
		
		WindowInfo m_Info;
	};

}

#include "sppch.h"
#include "WindowsWindow.h"

#include "Event/KeyEvent.h"
#include "Event/MouseEvent.h"
#include "Event/ApplicationEvent.h"

namespace Spark {

	static bool s_GLFWInited = false;

	WindowsWindow::WindowsWindow(const WindowProp& prop)
	{
		init(prop);
	}

	// when using Windows window, use unique_ptr as the window will not be freed in destructor
	Window* Window::createWindow(const WindowProp& prop)
	{
		return new WindowsWindow(prop);
	}

	WindowsWindow::~WindowsWindow()
	{
		shutdown();
	}

	void WindowsWindow::init(const WindowProp& prop)
	{
		m_Info.height = prop.height;
		m_Info.width = prop.width;
		m_Info.name = prop.name;

		SP_CORE_LOG_INFO("Window Created: Width: {0}, Height: {1}", m_Info.width, m_Info.height)

		if (s_GLFWInited == false)
		{
			int success = glfwInit();
			SP_CORE_ASSERT(success, "GLFW fail to initialize!")
			s_GLFWInited = true;
		}

		m_Window = glfwCreateWindow(m_Info.width, m_Info.height, m_Info.name.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SP_CORE_ASSERT(success, "GLAD failed to load!")
		glfwSetWindowUserPointer(m_Window, &m_Info);

		/* ------ Setting up GLFW Callback Links ------*/
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowInfo& info = *(WindowInfo*)glfwGetWindowUserPointer(window);
				WindowClosedEvent e;
				info.callback(e);
			});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowInfo& info = *(WindowInfo*)glfwGetWindowUserPointer(window);
				info.width = width;
				info.height = height;

				WindowResizedEvent e(width, height);
				info.callback(e);
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double Xoffset, double Yoffset)
			{
				WindowInfo& info = *(WindowInfo*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent e((float)Xoffset, (float)Yoffset);
				info.callback(e);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double XPos, double YPos)
			{
				WindowInfo& info = *(WindowInfo*)glfwGetWindowUserPointer(window);
				MouseMovedEvent e((float)XPos, (float)YPos);
				info.callback(e);
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowInfo& info = *(WindowInfo*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e(button);
					info.callback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(button);
					info.callback(e);
					break;
				}
				}
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowInfo& info = *(WindowInfo*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent e(key, 0);
					info.callback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent e(key);
					info.callback(e);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent e(key, 1);
					info.callback(e);
					break;
				}
				}
			});
		/* --------------------------------------------*/

		setVSync(true);
	}

	void WindowsWindow::onUpdate()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void WindowsWindow::shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}
}

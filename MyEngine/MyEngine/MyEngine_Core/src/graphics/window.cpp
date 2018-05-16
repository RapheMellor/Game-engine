#include "window.h"

namespace MyEngine { namespace graphics {

	void window_resize(GLFWwindow *window, int m_Width, int m_Height);

	//Window variables are set
	Window::Window(const char *name, int width, int height)
	{
		m_Name = name;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
		}

		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
		}
	}

	Window::~Window()
	{

	}

	bool Window::init()
	{
		//If initialising GLFW does'nt work output this message
		if (!glfwInit())
		{
			std::cout << "Error" << std::endl;
			return false;
		}

		//If the window fails to be created output this message
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Failed Window" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		//If the GLEW library could not be initialised output this message
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialize GLEW" << std::endl;
			return false;
		}

		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

		return true;
	}

	//If key is pressed
	bool Window::isKeyPressed(unsigned int keycode) const
	{
		if (keycode >= MAX_KEYS)
			return false;

		return m_Keys[keycode];
	}

	//If mouse button is pressed
	bool Window::isMouseButtonPressed(unsigned int button) const
	{
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseButtons[button];
	}

	//Get position of mouse cursor in application screen
	void Window::getMousePosition(double& x, double& y) const
	{
		x = mx;
		y = my;
	}

	//Clear application window
	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);
	}

	//Close down the window when application is terminated
	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	//Sprites resize with the window
	void window_resize(GLFWwindow *window, int m_Width, int m_Height)
	{
		glViewport(0, 0, m_Width, m_Height);
	}

	//Is key press released
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
	}

	//Is mouse click released
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	//Where is mouse position
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

} }
#include "window.h"

#define PRINT(x) std::cout << x << std::endl

namespace photon {
	namespace graphics {

		// Define static arrays
		bool Window::m_keys[MAX_KEYS]; 
		bool Window::m_buttons[MAX_BUTTONS];
		double Window::m_mousex;
		double Window::m_mousey;

		Window::Window(const char* title, int width, int height) {
			m_title = title;
			m_width = width;
			m_height = height;

			if (!init()) {glfwTerminate();}

			for (int i = 0; i < MAX_KEYS; i++) {
				m_keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++) {
				m_buttons[i] = false;
			}
		}

		Window::~Window() {
			glfwTerminate();
		}

		bool Window::init() {
			// glfw init and handle failure
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW" << std::endl;
				return false;
			}

			m_window = glfwCreateWindow(m_width, m_height, "3D Rendering", NULL, NULL);

			// Handle window create failure
			if (!m_window) {
				std::cout << "Failed to create window" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_window);
			glfwSetWindowUserPointer(m_window, this); // map between GLFWwindow and Window

			glfwSetWindowSizeCallback(m_window, windowResize);
			glfwSetKeyCallback(m_window, keyCallback);
			glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
			glfwSetCursorPosCallback(m_window, mousePositionCallback);

			if (glewInit() != GLEW_OK) {
				std::cout << "Failed to initialize glew" << std::endl;
				return false;
			}

			return true;
		}


		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_window);
		}

		void Window::update() {
			glfwPollEvents();
			glfwSwapBuffers(m_window);
			std::cout << getMouseX() << ", " << getMouseY() << std::endl;
		}

		void Window::windowResize(GLFWwindow* window, int width, int height) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_width = width;
			win->m_height = height;
			glViewport(0, 0, width, height); 
		}

		void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS) {
				win->m_keys[key] = true;
			}
			else if (action == GLFW_RELEASE) {
				win->m_keys[key] = false;
			}
		}

		void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			if (action == GLFW_PRESS) {
				win->m_buttons[button] = true;
			}
			else if (action == GLFW_RELEASE) {
				win->m_buttons[button] = false;
			}
		}
		
		void Window::mousePositionCallback(GLFWwindow* window, double x, double y) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_mousex = x;
			win->m_mousey = y;
		}
	}
}
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace photon {
	namespace graphics {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class Window {
			
		private:
			int m_width, m_height;
			const char* m_title;
			GLFWwindow* m_window;
			bool m_closed;

			static bool m_keys[MAX_KEYS];
			static bool m_buttons[MAX_BUTTONS];

			static double m_mousex;
			static double m_mousey;

		public:
			Window(const char* title, int width, int height);
			~Window();
			void update();
			void clear() const;
			bool closed() const;

			inline int getWidth() const { return m_width; }
			inline int getHeight() const { return m_height; }		
			inline int getKey(int key) const { return m_keys[key]; }
			inline int getButton(int button) const { return m_buttons[button]; }
			inline double getMouseX() const { return m_mousex; }
			inline double getMouseY() const { return m_mousey; }

			// inline void setWidth(int width) { m_width = width; }
			// inline void setHeight(int height) { m_height = height; }
			// inline void setKey(int key, bool value) { m_keys[key] = value; }
			// inline void setButton(int button, bool value) { m_buttons[button] = value; }

		private:
			bool init();

			static void windowResize(GLFWwindow* window, int width, int height);
			static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
			static void mousePositionCallback(GLFWwindow* window, double x, double y);

		};

	}
}
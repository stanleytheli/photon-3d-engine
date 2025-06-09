#include <iostream>

#include "src/graphics/window.h"

#define PRINT(x) std::cout << x << std::endl

int main() {
	using namespace photon::graphics;

	// PRINT(glfwGetVersionString());

	Window window("Renderer", 1000, 700);

	glClearColor(0.8f, 0.3f, 0.3f, 1.0f);

	// Testing that GLEW is working
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed()) {
		window.clear();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
	
}
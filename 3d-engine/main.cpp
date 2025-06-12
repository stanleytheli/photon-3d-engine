#include <iostream>
#include <cmath>

#include "src/graphics/window.h"
#include "src/math/math.h"

#define PRINT(x) std::cout << x << std::endl

int main() {
	using namespace photon::graphics;
	using namespace photon::math;

	Window window("Renderer", 1000, 700);

	vec3 a(4.0, 5.0, 1.0);
	vec3 b(2.0, 3.0, 2.0);
	vec3 c;

	c = a * b;
	c += a;

	PRINT(a);
	PRINT(c);
	PRINT(c.dot(a));
	
	vec3 d = a.cross(c);
	PRINT(d);
	PRINT(d.dot(a));
	PRINT(d.dot(c));

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
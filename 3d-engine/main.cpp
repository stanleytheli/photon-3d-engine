#include <iostream>

#include "src/graphics/window.h"
#include "src/math/math.h"

#define PRINT(x) std::cout << x << std::endl

int main() {
	using namespace photon::graphics;
	using namespace photon::math;

	Window window("Renderer", 1000, 700);

	vec3 a(1.0, 2.0, 3.0);
	vec3 b(4.0, 3.0, 7.0);
	vec3 c(2.0, 8.0, -2.0);
	mat3x3 A = mat3x3::basis(a, b, c);
	
	vec3 d(4.0, -5.0, 2.0);
	vec3 e(1.0, 3.0, 7.0);
	vec3 f(2.0, -1.0, -5.0);
	mat3x3 B = mat3x3::basis(d, e, f);

	PRINT(A);
	PRINT(B);

	A.multiply(B);
	PRINT(A);

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
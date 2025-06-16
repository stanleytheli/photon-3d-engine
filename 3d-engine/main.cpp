#include <iostream>

#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"
#include "src/graphics/simplerenderer2d.h"
#include "src/graphics/renderable2d.h"

#include "src/math/math.h"
#include "src/utils/fileUtils.h"

#define PRINT(x) std::cout << x << std::endl
#define PI 3.141592653

int main() {
	using namespace photon::graphics;
	using namespace photon::math;

	Window window("Renderer", 1000, 700);

	glClearColor(0.454, 0.890, 0.882, 1.0);
	
	// matrix and vector testing
	/*
	mat4x4 Rx = mat4x4::rotate(vec3(1, 0, 0), PI / 3);
	mat4x4 Ry = mat4x4::rotate(vec3(0, 1, 0), PI / 3);
	mat4x4 Rz = mat4x4::rotate(vec3(0, 0, 1), PI / 3);

	PRINT(Rx);
	PRINT(Ry);
	PRINT(Rz);
	*/

	// Old rendering pipeline 
	/*
	GLfloat vertices[] = {
		-0.5, -0.5,  0.0,
		 0.5, -0.5,  0.0,
		 0.0,  0.5,  0.0,
		 0.3,  0.25, 0.0,
		 0.9,  0.25, 0.0,
		 0.7, -0.25, 0.0,
		-0.3,  0.25, 0.0,
		-0.9,  0.25, 0.0,
		-0.7, -0.25, 0.0,
	};

	GLfloat colors[] = {
		 0.219, 0.584, 0.878, 1.0,
		 0.922, 0.290, 0.259, 1.0,
		 0.125, 0.722, 0.035, 1.0,
		 0.219, 0.584, 0.878, 1.0,
		 0.922, 0.290, 0.259, 1.0,
		 0.125, 0.722, 0.035, 1.0,
		 0.219, 0.584, 0.878, 1.0,
		 0.922, 0.290, 0.259, 1.0,
		 0.125, 0.722, 0.035, 1.0,
	};

	GLuint indices[] = {
		0, 1, 2,
		3, 4, 5,
		6, 7, 8,
	};
	*/

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", mat4x4::identity());
	shader.setUniformMat4("vw_matrix", mat4x4::identity());

	shader.setUniform2f("light_pos", vec2(0.0, 0.0));

	Renderable2D sprite1(vec3(0.2, 0.2, 0), vec2(0.5, 0.5), vec4(0.922, 0.290, 0.259, 1.0), shader);
	Renderable2D sprite2(vec3(-0.2, 0, 0), vec2(0.3, 0.7), vec4(0.219, 0.584, 0.878, 1.0), shader);
	Renderable2D sprite3(vec3(-0.1, -0.5, 0), vec2(0.4, 0.6), vec4(0.125, 0.722, 0.035, 1.0), shader);
	SimpleRenderer2D renderer;

	while (!window.closed()) {
		window.clear();

		float x = window.getMouseX(), y = window.getMouseY();
		float w = window.getWidth(), h = window.getHeight();
		float normMouseX = 2 * (x/w) - 1;
		float normMouseY = 1 - 2 * (y/h);
		shader.setUniform2f("light_pos", vec2(normMouseX, normMouseY));

		renderer.submit(&sprite1);
		renderer.submit(&sprite2);
		renderer.submit(&sprite3);
		renderer.flush();

		window.update();
	}

	return 0;
	
}
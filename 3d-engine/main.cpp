#include <iostream>

#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/math/math.h"
#include "src/utils/fileUtils.h"

#define PRINT(x) std::cout << x << std::endl

int main() {
	using namespace photon::graphics;
	using namespace photon::math;

	Window window("Renderer", 1000, 700);

	glClearColor(0.454, 0.890, 0.882, 1.0);

	/*
	GLfloat vertices[] = {
	-0.5, -0.5, 0.0,
	 0.5, -0.5, 0.0,
	 0.0,  0.5, 0.0,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	*/

	GLfloat vertices[] = {
		-0.5, -0.5, 0.0,
		 0.5, -0.5, 0.0,
		 0.0,  0.5, 0.0,
		 0.3,  0.25,0.0,
		 0.9,  0.25,0.0,
		 0.7, -0.25,0.0,
		-0.3,  0.25,0.0,
		-0.9,  0.25,0.0,
		-0.7, -0.25,0.0,
	};

	GLuint indices[] = {
		0, 1, 2,
		3, 4, 5,
		6, 7, 8,
	};

	VertexArray vao;
	Buffer* vbo = new Buffer(vertices, 9 * 3, 3);
	IndexBuffer* ibo = new IndexBuffer(indices, 9);

	vao.addBuffer(vbo, 0);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	shader.setUniformMat4("pr_matrix", mat4x4::scale(1.0));
	shader.setUniformMat4("vw_matrix", mat4x4::identity());
	shader.setUniformMat4("ml_matrix", mat4x4::identity());

	shader.setUniform2f("light_pos", vec2(0.0, 0.0));

	while (!window.closed()) {
		window.clear();

		float x = (float)window.getMouseX(), y = (float)window.getMouseY();
		float w = window.getWidth(), h = window.getHeight();
		float normMouseX = 2 * (x/w) - 1;
		float normMouseY = 1 - 2 * (y/h);
		shader.setUniform2f("light_pos", vec2(normMouseX, normMouseY));

		vao.bind();
		ibo->bind();
		glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_INT, 0);
		vao.unbind();
		ibo->unbind();

		window.update();
	}

	return 0;
	
}
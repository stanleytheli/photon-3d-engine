#include <iostream>

#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"
#include "src/graphics/renderable2d.h"
#include "src/graphics/simplerenderer2d.h"
#include "src/graphics/batchrenderer2d.h"
#include "src/graphics/staticsprite.h"
#include "src/graphics/sprite.h"
#include "src/graphics/layers/tilelayer.h"

#include "src/math/math.h"
#include "src/utils/fileUtils.h"
#include "src/utils/timer.h"

#define PRINT(x) std::cout << x << std::endl
#define PI 3.141592653

int main() {
	using namespace photon;
	using namespace photon::graphics;
	using namespace photon::math;

	Window window("Renderer", 900, 800);

	//glClearColor(0.454, 0.890, 0.882, 1.0);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	Shader* shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader->enable();

	shader->setUniformMat4("pr_matrix", mat4x4::identity());
	shader->setUniformMat4("vw_matrix", mat4x4::identity());
	shader->setUniformMat4("ml_matrix", mat4x4::identity());

	shader->setUniform2f("light_pos", vec2(0.0, 0.0));

	/*
	Sprite sprite1(0.25, 0.25, 0, 0.5, 0.5, vec4(0.922, 0.290, 0.259, 1.0));
	Sprite sprite2(-0.1, 0, 0, 0.3, 0.7, vec4(0.219, 0.584, 0.878, 1.0));
	Sprite sprite3(0.1, -0.5, 0, 0.4, 0.6, vec4(0.125, 0.722, 0.035, 1.0));
	*/

	TileLayer layer(shader);
	for (float x = -1.0; x < 1.0; x += 0.02) {
		for (float y = -1.0; y < 1.0; y += 0.02) {
			layer.add(
				new Sprite(x, y, 0, 0.018, 0.018, vec4(
					rand() % 1000 / 2000.0f,
					rand() % 1000 / 2000.0f,
					rand() % 1000 / 1000.0f,
					1.0))
			);
		}
	}

	// Don't reset this one
	Timer time;
	Timer timer;
	unsigned short frames = 0;

	while (!window.closed()) {


		mat4x4 mat = mat4x4::rotate(vec3(1, 0, 1), time.elapsed());
		shader->setUniformMat4("ml_matrix", mat);

		window.clear();

		float x = window.getMouseX(), y = window.getMouseY();
		float w = window.getWidth(), h = window.getHeight();
		float normMouseX = 2 * (x/w) - 1;
		float normMouseY = 1 - 2 * (y/h);
		shader->setUniform2f("light_pos", vec2(normMouseX, normMouseY));

		layer.render();

		window.update();

		frames++;
		if (timer.elapsed() > 1.0) {
			std::cout << "FPS: " << frames << "\n";
			timer.reset();
			frames = 0;
		}
	}

	return 0;
	
}
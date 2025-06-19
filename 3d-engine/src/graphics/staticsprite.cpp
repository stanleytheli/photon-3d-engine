#include "staticsprite.h"

namespace photon {
	namespace graphics {

		StaticSprite::StaticSprite(float x, float y, float z, float width, float height, math::vec4 color, Shader& shader) 
			: Renderable2D(math::vec3(x, y, z), math::vec2(width, height), color), m_shader(shader) {

			GLfloat vertices[] = {
				0.0, 0.0, 0.0,
				0.0, height, 0.0,
				width, height, 0.0,
				width, 0.0, 0.0,
			};

			GLfloat colors[] = {
				 color.x, color.y, color.z, color.w,
				 color.x, color.y, color.z, color.w,
				 color.x, color.y, color.z, color.w,
				 color.x, color.y, color.z, color.w,
			};

			GLuint indices[] = {
				0, 1, 2,
				0, 2, 3,
			};

			m_vertexArray = new VertexArray();
			m_vertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_vertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);
			m_indexBuffer = new IndexBuffer(indices, 6);

		}

		StaticSprite::~StaticSprite() {
			delete m_vertexArray;
			delete m_indexBuffer;
		}


	}
}
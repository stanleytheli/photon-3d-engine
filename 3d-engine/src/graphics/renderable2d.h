#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"
#include "../math/math.h"
#include "shader.h"

namespace photon {
	namespace graphics {

		class Renderable2D {
		protected:
			math::vec3 m_position;
			math::vec2 m_size;
			math::vec4 m_color;

			VertexArray *m_vertexArray;
			IndexBuffer *m_indexBuffer;
			Shader& m_shader;
		public:
			Renderable2D(math::vec3 position, math::vec2 size, math::vec4 color, Shader& shader) 
			: m_shader(shader) {
				m_position = position;
				m_size = size;
				m_color = color;

				GLfloat vertices[] = {
					0.0, 0.0, 0.0,
					0.0, size.y, 0.0,
					size.x, size.y, 0.0,
					size.x, 0.0, 0.0,
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

			virtual ~Renderable2D() {
				delete m_vertexArray;
				delete m_indexBuffer;
			}
			
			inline VertexArray* getVAO() const { return m_vertexArray; }
			inline IndexBuffer* getIBO() const { return m_indexBuffer; }
			inline Shader& getShader() const { return m_shader; }

			inline const math::vec3& getPosition() const { return m_position; }
			inline const math::vec2& getSize() const { return m_size; }
			inline const math::vec4& getColor() const { return m_color; }
		};

	}
}
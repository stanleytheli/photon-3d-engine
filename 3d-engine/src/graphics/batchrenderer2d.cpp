#include "batchrenderer2d.h"

namespace photon {
	namespace graphics {

		BatchRenderer2D::BatchRenderer2D() {
			init();
		}

		BatchRenderer2D::~BatchRenderer2D() {
			delete m_IBO;
			delete m_indices;
			glDeleteBuffers(1, &m_VBO);
		}

		void BatchRenderer2D::init() {

			m_indexCount = 0;

			glGenVertexArrays(1, &m_VAO);
			glGenBuffers(1, &m_VBO);

			glBindVertexArray(m_VAO);
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);
			
			glEnableVertexAttribArray(SHADER_VERT_IDX);
			glEnableVertexAttribArray(SHADER_COLOR_IDX);

			glVertexAttribPointer(SHADER_VERT_IDX, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::vertex)));
			glVertexAttribPointer(SHADER_COLOR_IDX, 4, GL_UNSIGNED_BYTE, GL_TRUE, VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::color)));

			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

			m_indices = new GLuint[INDICES_SIZE];

			int offset = 0;
			for (int i = 0; i < INDICES_SIZE; i += 6) {
				m_indices[i]     = offset + 0;
				m_indices[i + 1] = offset + 1;
				m_indices[i + 2] = offset + 2;
				m_indices[i + 3] = offset + 2;
				m_indices[i + 4] = offset + 3;
				m_indices[i + 5] = offset + 0;
				offset += 4;
			}
			
			m_IBO = new IndexBuffer(m_indices, INDICES_SIZE);
		}

		void BatchRenderer2D::begin() {
			glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
			m_buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
		}

		void BatchRenderer2D::end() {
			glUnmapBuffer(GL_ARRAY_BUFFER);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void BatchRenderer2D::submit(const Renderable2D* renderable) {
			const math::vec3& pos = renderable->getPosition();
			const math::vec2& size = renderable->getSize();
			const math::vec4& color= renderable->getColor();

			int r = color.x * 255.0;
			int g = color.y * 255.0;
			int b = color.z * 255.0;
			int a = color.w * 255.0;

			unsigned int c = r | g << 8 | b << 16 | a << 24;

			m_buffer->vertex = pos;
			m_buffer->color = c;
			m_buffer++;

			m_buffer->vertex = math::vec3(pos.x, pos.y + size.y, pos.z);
			m_buffer->color = c;
			m_buffer++;

			m_buffer->vertex = math::vec3(pos.x + size.x, pos.y + size.y, pos.z);
			m_buffer->color = c;
			m_buffer++;
			
			m_buffer->vertex = math::vec3(pos.x + size.x, pos.y, pos.z);
			m_buffer->color = c;
			m_buffer++;

			m_indexCount += 6;
		}

		void BatchRenderer2D::flush() {
			glBindVertexArray(m_VAO);
			m_IBO->bind();

			glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);
			m_indexCount = 0;

			m_IBO->unbind();
			glBindVertexArray(0);
		}

	}
}
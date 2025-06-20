#pragma once
#include "renderer2d.h"
#include "buffers/indexbuffer.h"
#include <cstddef>

namespace photon {
	namespace graphics {

#define MAX_SPRITES			25000
#define VERTEX_SIZE			sizeof(VertexData)
#define SPRITE_SIZE			(VERTEX_SIZE * 4)
#define BUFFER_SIZE			(SPRITE_SIZE * MAX_SPRITES)
#define INDICES_SIZE		(MAX_SPRITES * 6)

#define SHADER_VERT_IDX		0
#define SHADER_COLOR_IDX	1

		class BatchRenderer2D : public Renderer2D {
		private:
			GLuint m_VAO;
			GLuint m_VBO;
			IndexBuffer* m_IBO;
			GLsizei m_indexCount;

			GLuint* m_indices;
			VertexData* m_buffer;

		public:
			BatchRenderer2D();
			~BatchRenderer2D();
			void submit(const Renderable2D* renderable) override;
			void flush() override;

			void begin() override;
			void end() override;
		private:
			void init();
		};

	}
}
#pragma once

#include <GL/glew.h>
#include "buffer.h"
#include <vector>

namespace photon {
	namespace graphics {

		class VertexArray {
		private:
			GLuint m_arrayID;
			std::vector<Buffer*> m_buffers;
		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer* buffer, GLuint index);

			void bind() const;
			void unbind() const;
		};

	}
}
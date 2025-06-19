#pragma once

#pragma once

#include <GL/glew.h>

namespace photon {
	namespace graphics {

		class IndexBuffer {
		private:
			GLuint m_bufferID;
			GLuint m_count;

		public:
			IndexBuffer(GLuint* data, GLsizei count);
			~IndexBuffer();

			void bind() const;
			void unbind() const;

			GLuint getCount() { return m_count; }
		};

	}
}
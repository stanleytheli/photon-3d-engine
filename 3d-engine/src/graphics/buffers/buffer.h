#pragma once

#include <GL/glew.h>

namespace photon {
	namespace graphics {

		class Buffer {
		private:
			GLuint m_bufferID;
			GLuint m_componentCount;

		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
			~Buffer();

			void bind() const;
			void unbind() const;

			GLuint getComponentCount() { return m_componentCount; }
		};

	}
}
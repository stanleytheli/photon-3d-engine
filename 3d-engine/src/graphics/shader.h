#pragma once
#include "../utils/fileUtils.h"
#include "../math/math.h"

#include <GL/glew.h>

namespace photon {
	namespace graphics {

		class Shader {
		private:
			GLuint m_shaderID;
			const char *m_vertPath, *m_fragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void enable() const;
			void disable() const;

			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, const math::vec2& vec);
			void setUniform3f(const GLchar* name, const math::vec3& vec);
			void setUniform4f(const GLchar* name, const math::vec4& vec);
			void setUniformMat4(const GLchar* name, const math::mat4x4 mat);

		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};

	}
}
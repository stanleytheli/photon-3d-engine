#include "shader.h"
#include <iostream>
#include <vector>

namespace photon {
	namespace graphics {

		Shader::Shader(const char* vertPath, const char* fragPath) { 
			m_vertPath = vertPath;
			m_fragPath = fragPath;
			m_shaderID = load();
		}

		Shader::~Shader() {
			glDeleteProgram(m_shaderID);
		}


		GLint Shader::getUniformLocation(const GLchar* name) {
			return glGetUniformLocation(m_shaderID, name);
		}
		void Shader::setUniform1f(const GLchar* name, float value) {
			glUniform1f(getUniformLocation(name), value);
		}
		void Shader::setUniform1i(const GLchar* name, int value) {
			glUniform1i(getUniformLocation(name), value);
		}
		void Shader::setUniform2f(const GLchar* name, const math::vec2& vec) {
			glUniform2f(getUniformLocation(name), vec.x, vec.y);
		}
		void Shader::setUniform3f(const GLchar* name, const math::vec3& vec) {
			glUniform3f(getUniformLocation(name), vec.x, vec.y, vec.z);
		}
		void Shader::setUniform4f(const GLchar* name, const math::vec4& vec) {
			glUniform4f(getUniformLocation(name), vec.x, vec.y, vec.z, vec.w);
		}
		void Shader::setUniformMat4(const GLchar* name, const math::mat4x4 mat) {
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, mat.elements);
		}


		GLuint Shader::load() {
			GLuint program = glCreateProgram();

			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSource = readFile(m_vertPath);
			std::string fragSource = readFile(m_fragPath);
			const char* cVertSource = vertSource.c_str();
			const char* cFragSource = fragSource.c_str();

			glShaderSource(vertex, 1, &cVertSource, NULL);
			glCompileShader(vertex);

			// Check vert shader
			GLint result_vert;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result_vert);

			if (result_vert == GL_FALSE) {
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader" << &error[0];
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &cFragSource, NULL);
			glCompileShader(fragment);

			// Check frag shader
			GLint result_frag;
			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result_frag);

			if (result_frag == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader" << &error[0];
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		void Shader::enable() const {
			glUseProgram(m_shaderID);
		}

		void Shader::disable() const {
			glUseProgram(0);
		}
	}
}
#pragma once
#include "renderable2d.h"

namespace photon {
	namespace graphics {

		class StaticSprite : public Renderable2D {
		public:
			VertexArray* m_vertexArray;
			IndexBuffer* m_indexBuffer;
			Shader& m_shader;

			StaticSprite(float x, float y, float z, float width, float height, math::vec4 color, Shader& shader);
			virtual ~StaticSprite();

			inline VertexArray* getVAO() const { return m_vertexArray; }
			inline IndexBuffer* getIBO() const { return m_indexBuffer; }
			inline Shader& getShader() const { return m_shader; }

		};

	}
}
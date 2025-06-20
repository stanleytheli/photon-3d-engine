#pragma once

#include "buffers/buffer.h"
#include "buffers/indexbuffer.h"
#include "buffers/vertexarray.h"
#include "../math/math.h"
#include "shader.h"

namespace photon {
	namespace graphics {

		struct VertexData {
			math::vec3 vertex;
			unsigned int color;

		};

		class Renderable2D {
		protected:
			math::vec3 m_position;
			math::vec2 m_size;
			math::vec4 m_color;
			Renderable2D(math::vec3 position, math::vec2 size, math::vec4 color)
				: m_position(position), m_size(size), m_color(color) {
			}

		public:
			virtual ~Renderable2D() {}
			inline const math::vec3& getPosition() const { return m_position; }
			inline const math::vec2& getSize() const { return m_size; }
			inline const math::vec4& getColor() const { return m_color; }
		};

	}
}
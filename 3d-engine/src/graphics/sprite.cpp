#include "sprite.h"

namespace photon {
	namespace graphics {

		Sprite::Sprite(float x, float y, float z, float width, float height, math::vec4 color)
			: Renderable2D(math::vec3(x, y, z), math::vec2(width, height), color) { }


	}
}
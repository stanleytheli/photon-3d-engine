#pragma once
#include "renderable2d.h"

namespace photon {
	namespace graphics {

		class Sprite : public Renderable2D {
		private:

		public:
			Sprite(float x, float y, float z, float width, float height, math::vec4 color);
		};

	}
}
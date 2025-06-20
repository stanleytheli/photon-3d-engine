#pragma once

#include "renderable2d.h"
#include <GL/glew.h>
#include "../math/math.h"

namespace photon {
	namespace graphics {

		class Renderer2D {
		public:
			virtual void submit(const Renderable2D* renderable) = 0;
			virtual void flush() = 0;
			virtual void begin() {};
			virtual void end() {};
		};

	}
}
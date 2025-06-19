#pragma once

#include <deque>
#include "renderer2d.h"
#include "staticsprite.h"

namespace photon {
	namespace graphics {

		class SimpleRenderer2D : public Renderer2D {
		private:
			std::deque<const StaticSprite*> m_queue;
		public:
			void submit(const Renderable2D* sprite) override;
			void flush() override;
		};

	}
}
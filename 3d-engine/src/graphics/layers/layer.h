#pragma once
#include "../Renderer2D.h"
#include "../Renderable2D.h"
#include "../Shader.h"
#include "../../math/math.h"
#include <vector>

namespace photon {
	namespace graphics {
		
		class Layer {
		private:
			Renderer2D* m_renderer;
			Shader* m_shader;
			std::vector<Renderable2D*> m_renderables;
			math::mat4x4 m_prMatrix;
		protected:
			Layer(Renderer2D* renderer, Shader* shader, math::mat4x4 prMatrix);
		public:
			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			virtual void render();
		};

	}
}
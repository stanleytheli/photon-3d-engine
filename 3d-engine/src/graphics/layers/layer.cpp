#include "layer.h"

namespace photon {
	namespace graphics {

		Layer::Layer(Renderer2D* renderer, Shader* shader, math::mat4x4 prMatrix) 
			: m_renderer(renderer), m_shader(shader), m_prMatrix(prMatrix) {

			m_shader->enable();
			m_shader->setUniformMat4("pr_matrix", m_prMatrix);
			m_shader->disable();
		}

		Layer::~Layer() {
			delete m_shader;
			delete m_renderer;
			for (int i = 0; i < m_renderables.size(); i++) {
				delete m_renderables[i];
			}
		}
			
		void Layer::add(Renderable2D* renderable) {
			m_renderables.push_back(renderable);
		}

		void Layer::render() {
			m_shader->enable();
			
			m_renderer->begin();
			for (int i = 0; i < m_renderables.size(); i++) {
				m_renderer->submit(m_renderables[i]);
			}
			m_renderer->end();

			m_renderer->flush();

			//m_shader->disable();
		}
	}
}
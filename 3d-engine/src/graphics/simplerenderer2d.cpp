#include "simplerenderer2d.h"

namespace photon {
	namespace graphics {

		void SimpleRenderer2D::submit(const Renderable2D* renderable) {
			m_queue.push_back(renderable);
		}

		void SimpleRenderer2D::flush() {
			while (!m_queue.empty()) {
				const Renderable2D* renderable = m_queue.front();

				renderable->getVAO()->bind();
				renderable->getIBO()->bind();

				renderable->getShader().setUniformMat4("ml_matrix", 
					math::mat4x4::translate(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_INT, 0);
				
				renderable->getIBO()->unbind();
				renderable->getVAO()->unbind();

				m_queue.pop_front();
			}
		}

	}
}
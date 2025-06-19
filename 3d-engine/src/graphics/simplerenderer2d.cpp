#include "simplerenderer2d.h"

namespace photon {
	namespace graphics {

		void SimpleRenderer2D::submit(const Renderable2D* renderable) {
			m_queue.push_back((StaticSprite*) renderable);
		}

		void SimpleRenderer2D::flush() {
			while (!m_queue.empty()) {
				const StaticSprite* sprite = m_queue.front();

				sprite->getVAO()->bind();
				sprite->getIBO()->bind();

				sprite->getShader().setUniformMat4("ml_matrix",
					math::mat4x4::translate(sprite->getPosition()));
				glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_INT, 0);
				
				sprite->getIBO()->unbind();
				sprite->getVAO()->unbind();

				m_queue.pop_front();
			}
		}

	}
}
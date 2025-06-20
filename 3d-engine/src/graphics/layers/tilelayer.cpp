#include "tilelayer.h"

namespace photon {
	namespace graphics {

		TileLayer::TileLayer(Shader* shader)
			: Layer(new BatchRenderer2D(), shader, math::mat4x4::identity()) {}

		TileLayer::TileLayer(Shader* shader, math::mat4x4 prMatrix)
			: Layer(new BatchRenderer2D(), shader, prMatrix) {}

		TileLayer::~TileLayer() {

		}


	}
}
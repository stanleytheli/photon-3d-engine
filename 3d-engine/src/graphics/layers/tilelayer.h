#pragma once
#include "layer.h"
#include "../batchrenderer2d.h"

namespace photon {
	namespace graphics {

		class TileLayer : public Layer {
		private:

		public:
			TileLayer(Shader* shader);
			TileLayer(Shader* shader, math::mat4x4 prMatrix);
			~TileLayer();

		};


	}
}
#include "matrix.h"

namespace photon {
	namespace math {

		mat4x4::mat4x4() {
			for (int i = 0; i < n * n; i++) {
				elements[i] = 0.0;
			}
		}

		mat4x4::mat4x4(float diagonal) {
			for (int i = 0; i < n * n; i++) {
				elements[i] = 0.0;
			}
			for (int j = 0; j < n; j++) {
				elements[j + j * n] = diagonal;
			}
		}

		mat4x4 mat4x4::identity() {
			return mat4x4(1.0);
		}

		mat4x4 mat4x4::basis(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3) {
			mat4x4 output = mat4x4();
			output.setColumn(0, v0);
			output.setColumn(1, v1);
			output.setColumn(2, v2);
			output.setColumn(3, v3);
			return output;
		}

		mat4x4 mat4x4::scale(float factor) {
			mat4x4 output = mat4x4(factor);
			output.setItem(3, 3, 1.0);
			return output;
		}

		void mat4x4::basisUnpack(vec4& v0, vec4& v1, vec4& v2, vec4& v3) const {
			v0 = getColumn(0);
			v1 = getColumn(1);
			v2 = getColumn(2);
			v3 = getColumn(3);
		}

		float mat4x4::getItem(int row, int col) const {
			return elements[row + col * n];
		}

		void mat4x4::setItem(int row, int col, float value) {
			elements[row + col * n] = value;
		}

		vec4 mat4x4::getColumn(int col) const {
			return vec4(
				getItem(0, col),
				getItem(1, col),
				getItem(2, col),
				getItem(3, col)
			);
		}

		vec4 mat4x4::getRow(int row) const {
			return vec4(
				getItem(row, 0),
				getItem(row, 1),
				getItem(row, 2),
				getItem(row, 3)
			);
		}

		void mat4x4::setColumn(int col, const vec4& value) {
			elements[0 + col * n] = value.x;
			elements[1 + col * n] = value.y;
			elements[2 + col * n] = value.z;
			elements[3 + col * n] = value.w;
		}

		void mat4x4::setRow(int row, const vec4& value) {
			elements[row + 0 * n] = value.x;
			elements[row + 1 * n] = value.y;
			elements[row + 2 * n] = value.z;
			elements[row + 3 * n] = value.w;
		}

		mat4x4& mat4x4::multiply(const mat4x4& other) {
			mat4x4 output = mat4x4();

			// (AB)_ij = sum_k [A_ik B_kj]
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {

					float sum = 0.0;
					for (int k = 0; k < n; k++) {
						sum += getItem(i, k) * other.getItem(k, j);
					}
					output.setItem(i, j, sum);

				}
			}

			*this = output;
			return *this;
		}

		vec4 mat4x4::multiply(const vec4& other) const {
			vec4 output = vec4();

			// (Av)_i = sum_j A_ij v_j
			for (int i = 0; i < n; i++) {
				float sum = 0;
				for (int j = 0; j < n; j++) {
					sum += getItem(i, j) * other.getItem(j);
				}
				output.setItem(i, sum);
			}

			return output;
		}

		mat4x4 operator*(const mat4x4& left, const mat4x4& right) {
			mat4x4 output = left;
			return output.multiply(right);
		}

		vec4 operator*(const mat4x4& left, const vec4& right) {
			return left.multiply(right);
		}

		bool mat4x4::operator==(const mat4x4& other) {
			for (int i = 0; i < n * n; i++) {
				if (elements[i] != other.elements[i]) {
					return false;
				}
			}
			return true;
		}

		std::ostream& operator<<(std::ostream& stream, const mat4x4& mat) {
			stream << "mat4x4[" << mat.elements[0] << "  " << mat.elements[4] << "  " << mat.elements[8] << "  " << mat.elements[12] << "\n"
			   	   << "       " << mat.elements[1] << "  " << mat.elements[5] << "  " << mat.elements[9] << "  " << mat.elements[13] << "\n"
				   << "       " << mat.elements[2] << "  " << mat.elements[6] << "  " << mat.elements[10] << "  " << mat.elements[14] << "\n"
				   << "       " << mat.elements[3] << "  " << mat.elements[7] << "  " << mat.elements[11] << "  " << mat.elements[15] << "]\n";

			return stream;
		}

	}
}
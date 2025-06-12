#include "matrix.h"

namespace photon {
	namespace math {

		mat3x3::mat3x3() {
			for (int i = 0; i < 9; i++) {
				elements[i] = 0.0;
			}
		}

		mat3x3::mat3x3(double diagonal) {
			for (int i = 0; i < 9; i++) {
				elements[i] = 0.0;
			}
			for (int j = 0; j < 3; j++) {
				elements[j + j * 3] = diagonal;
			}
		}

		mat3x3 mat3x3::identity() {
			return mat3x3(1.0);
		}

		mat3x3 mat3x3::basis(const vec3& v0, const vec3& v1, const vec3& v2) {
			mat3x3 output = mat3x3();
			output.setColumn(0, v0);
			output.setColumn(1, v1);
			output.setColumn(2, v2);
			return output;
		}

		void mat3x3::setItem(int col, int row, double value) { 
			elements[row + col * 3] = value; 
		}

		vec3 mat3x3::getColumn(int col) const {
			return vec3(
				elements[0 + col*3],
				elements[1 + col*3],
				elements[2 + col*3]
			);
		}

		vec3 mat3x3::getRow(int row) const {
			return vec3(
				elements[row + 0 * 3],
				elements[row + 1 * 3],
				elements[row + 2 * 3]
			);
		}

		void mat3x3::setColumn(int col, const vec3& value) {
			elements[0 + col * 3] = value.x;
			elements[1 + col * 3] = value.y;
			elements[2 + col * 3] = value.z;
		}

		void mat3x3::setRow(int row, const vec3& value) {
			elements[row + 0 * 3] = value.x;
			elements[row + 1 * 3] = value.y;
			elements[row + 2 * 3] = value.z;
		}

		mat3x3& mat3x3::multiply(const mat3x3& other) {
			mat3x3 output = mat3x3();

			// (AB)_ij = sum_k [A_ik B_kj]
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {

					double sum = 0.0;
					for (int k = 0; k < 3; k++) {
						sum += getItem(i, k) * other.getItem(k, j);
					}
					output.setItem(i, j, sum);

				}
			}

			*this = output;
			return *this;
		}

		mat3x3 operator*(const mat3x3& left, const mat3x3& right) {
			mat3x3 output = left;
			output.multiply(right);
			return output;
		}

		bool mat3x3::operator==(const mat3x3& other) {
			for (int i = 0; i < 9; i++) {
				if (elements[i] != other.elements[i]) {
					return false;
				}
			}
			return true;
		}

		std::ostream& operator<<(std::ostream& stream, const mat3x3& mat) {
			stream << "mat3x3[" << mat.elements[0] << "  " << mat.elements[3] << "  " << mat.elements[6] << "\n"
				   << "       " << mat.elements[1] << "  " << mat.elements[4] << "  " << mat.elements[7] << "\n"
				   << "       " << mat.elements[2] << "  " << mat.elements[5] << "  " << mat.elements[8] << "]\n";
			return stream;
		}

	}
}
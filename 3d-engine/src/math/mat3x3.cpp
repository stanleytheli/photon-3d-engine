#include "matrix.h"
#include <cmath>

namespace photon {
	namespace math {

		mat3x3::mat3x3() {
			for (int i = 0; i < n * n; i++) {
				elements[i] = 0.0;
			}
		}

		mat3x3::mat3x3(float diagonal) {
			for (int i = 0; i < n * n; i++) {
				elements[i] = 0.0;
			}
			for (int j = 0; j < n; j++) {
				elements[j + j * n] = diagonal;
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

		mat3x3 mat3x3::rotate(const vec3& axis, const float theta) {
			vec3 a = axis.normalized();
			float sint = std::sin(theta);
			float cost = std::cos(theta);

			mat3x3 R = mat3x3();
			R.elements[0] = a.x * a.x * (1 - cost) + cost;
			R.elements[1] = a.x * a.y * (1 - cost) + a.z * sint;
			R.elements[2] = a.x * a.z * (1 - cost) - a.y * sint;
			R.elements[3] = a.x * a.y * (1 - cost) - a.z * sint;
			R.elements[4] = a.y * a.y * (1 - cost) + cost;
			R.elements[5] = a.y * a.z * (1 - cost) + a.x * sint;
			R.elements[6] = a.x * a.z * (1 - cost) + a.y * sint;
			R.elements[7] = a.y * a.z * (1 - cost) - a.x * sint;
			R.elements[8] = a.z * a.z * (1 - cost) + cost;
			return R;

			/* 
			// Old, non-hard-coded algorithm

			// Get valid orthonormal basis
			vec3 v = vec3(-a.y, a.x, 0);
			if (a.z > 0.707) { 
				v = vec3(0, -a.z, a.y);
			}
			v = v.normalized();
			vec3 w = a.cross(v);
			
			// Rotate orthonormal basis
			vec3 vp = v * cost + w * sint;
			vec3 wp = w * cost - v * sint;

			mat3x3 B0 = mat3x3::basis(v, w, a);
			mat3x3 B1 = mat3x3::basis(vp, wp, a);

			mat3x3 R = B1 * B0.transpose();
			return R;
			*/
		}

		void mat3x3::basisUnpack(vec3& v0, vec3& v1, vec3& v2) const {
			v0 = getColumn(0);
			v1 = getColumn(1);
			v2 = getColumn(2);
		}

		float mat3x3::getItem(int row, int col) const {
			return elements[row + col * n];
		}

		void mat3x3::setItem(int row, int col, float value) { 
			elements[row + col * n] = value; 
		}

		vec3 mat3x3::getColumn(int col) const {
			return vec3(
				getItem(0, col),
				getItem(1, col),
				getItem(2, col)
			);
		}

		vec3 mat3x3::getRow(int row) const {
			return vec3(
				getItem(row, 0),
				getItem(row, 1),
				getItem(row, 2)
			);
		}

		void mat3x3::setColumn(int col, const vec3& value) {
			elements[0 + col * n] = value.x;
			elements[1 + col * n] = value.y;
			elements[2 + col * n] = value.z;
		}

		void mat3x3::setRow(int row, const vec3& value) {
			elements[row + 0 * n] = value.x;
			elements[row + 1 * n] = value.y;
			elements[row + 2 * n] = value.z;
		}

		mat3x3& mat3x3::transpose() {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {

					if (i >= j) { continue; }
					// Case j < i (swap them):
					float temp = getItem(i, j);
					setItem(i, j, getItem(j, i));
					setItem(j, i, temp);

				}
			}
			return *this;
		}
		mat3x3 mat3x3::transposed() {
			mat3x3 output = *this;
			return output.transpose();
		}
		mat3x3 mat3x3::T() {
			return transposed();
		}

		

		mat3x3& mat3x3::multiply(const mat3x3& other) {
			mat3x3 output = mat3x3();

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

		vec3 mat3x3::multiply(const vec3& other) const {
			vec3 output = vec3();

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

		mat3x3 operator*(const mat3x3& left, const mat3x3& right) {
			mat3x3 output = left;
			return output.multiply(right);
		}

		vec3 operator*(const mat3x3& left, const vec3& right) {
			return left.multiply(right);
		}

		bool mat3x3::operator==(const mat3x3& other) {
			for (int i = 0; i < n * n; i++) {
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
#pragma once
#include <iostream>
#include "vector.h"

namespace photon {
	namespace math {
		
		struct mat3x3 {
			// M_ij = elements[j + i*3]
			double elements[3 * 3];

			// 3x3 matrix full of zeroes
			mat3x3();
			mat3x3(double diagonal);

			static mat3x3 identity();
			static mat3x3 basis(const vec3& v1, const vec3& v2, const vec3& v3);

			inline double getItem(int col, int row) const { return elements[row + col * 3]; };
			void setItem(int col, int row, double value);

			vec3 getColumn(int col) const;
			vec3 getRow(int row) const;
			void setColumn(int col, const vec3& value);
			void setRow(int row, const vec3& value);

			// Multiplies this matrix by the given matrix
			mat3x3& multiply(const mat3x3& other);

			friend mat3x3 operator*(const mat3x3& left, const mat3x3& right);

			bool operator==(const mat3x3& other);

			friend std::ostream& operator<<(std::ostream& stream, const mat3x3& mat);
		};
		
	}
}
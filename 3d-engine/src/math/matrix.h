#pragma once
#include <iostream>
#include "vector.h"

namespace photon {
	namespace math {
		
		struct mat3x3 {
			// M_ij = elements[j + i*n]
			int n = 3;
			float elements[9];

			// 3x3 matrix full of zeroes
			mat3x3();
			mat3x3(float diagonal);

			static mat3x3 identity();
			static mat3x3 basis(const vec3& v0, const vec3& v1, const vec3& v2);
			static mat3x3 rotate(const vec3& axis, const float theta);
			void basisUnpack(vec3& v0, vec3& v1, vec3& v2) const;

			inline float getItem(int col, int row) const;
			void setItem(int col, int row, float value);

			vec3 getColumn(int col) const;
			vec3 getRow(int row) const;
			void setColumn(int col, const vec3& value);
			void setRow(int row, const vec3& value);

			// Tranposes this matrix
			mat3x3& transpose();
			// Returns a transposed copy of this matrix
			mat3x3 transposed();
			// Returns a transposed copy of this matrix
			mat3x3 T();
			
			// Multiplies this matrix by the given matrix, using matrix multiplication
			mat3x3& multiply(const mat3x3& other);
			// Returns the result of (this matrix) * (vector), using matrix multiplication
			vec3 multiply(const vec3& other) const;

			friend mat3x3 operator*(const mat3x3& left, const mat3x3& right);
			friend vec3 operator*(const mat3x3& left, const vec3& right);

			bool operator==(const mat3x3& other);

			friend std::ostream& operator<<(std::ostream& stream, const mat3x3& mat);
		};

		struct mat4x4 {
			// M_ij = elements[j + i*n]
			int n = 4;
			float elements[16];

			// 4x4 matrix full of zeroes
			mat4x4();
			mat4x4(float diagonal);

			static mat4x4 identity();
			static mat4x4 basis(const vec4& v0, const vec4& v1, const vec4& v2, const vec4& v3);

			static mat4x4 scale(float factor);
			static mat4x4 translate(const vec3& delta);
			static mat4x4 rotate(const mat3x3& rotation);
			static mat4x4 rotate(const vec3& axis, const float theta);

			void basisUnpack(vec4& v0, vec4& v1, vec4& v2, vec4& v3) const;

			inline float getItem(int col, int row) const;
			void setItem(int col, int row, float value);

			vec4 getColumn(int col) const;
			vec4 getRow(int row) const;
			void setColumn(int col, const vec4& value);
			void setRow(int row, const vec4& value);

			// Tranposes this matrix
			mat4x4& transpose();
			// Returns a transposed copy of this matrix
			mat4x4 transposed();
			// Returns a transposed copy of this matrix
			mat4x4 T();

			// Multiplies this matrix by the given matrix, using matrix multiplication
			mat4x4& multiply(const mat4x4& other);
			// Returns the result of (this matrix) * (vector), using matrix multiplication
			vec4 multiply(const vec4& other) const;

			friend mat4x4 operator*(const mat4x4& left, const mat4x4& right);
			friend vec4 operator*(const mat4x4& left, const vec4& right);

			bool operator==(const mat4x4& other);

			friend std::ostream& operator<<(std::ostream& stream, const mat4x4& mat);
		};

		
	}
}